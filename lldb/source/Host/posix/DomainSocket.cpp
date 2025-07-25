//===-- DomainSocket.cpp --------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "lldb/Host/posix/DomainSocket.h"
#include "lldb/Utility/LLDBLog.h"
#ifdef __linux__
#include <lldb/Host/linux/AbstractSocket.h>
#endif

#include "llvm/Support/Errno.h"
#include "llvm/Support/Error.h"
#include "llvm/Support/FileSystem.h"

#include <cstddef>
#include <fcntl.h>
#include <memory>
#include <sys/socket.h>
#include <sys/un.h>

using namespace lldb;
using namespace lldb_private;

static const int kDomain = AF_UNIX;
static const int kType = SOCK_STREAM;

static bool SetSockAddr(llvm::StringRef name, const size_t name_offset,
                        sockaddr_un *saddr_un, socklen_t &saddr_un_len) {
  if (name.size() + name_offset > sizeof(saddr_un->sun_path))
    return false;

  memset(saddr_un, 0, sizeof(*saddr_un));
  saddr_un->sun_family = kDomain;

  memcpy(saddr_un->sun_path + name_offset, name.data(), name.size());

  // For domain sockets we can use SUN_LEN in order to calculate size of
  // sockaddr_un, but for abstract sockets we have to calculate size manually
  // because of leading null symbol.
  if (name_offset == 0)
    saddr_un_len = SUN_LEN(saddr_un);
  else
    saddr_un_len =
        offsetof(struct sockaddr_un, sun_path) + name_offset + name.size();

#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
    defined(__OpenBSD__)
  saddr_un->sun_len = saddr_un_len;
#endif

  return true;
}

DomainSocket::DomainSocket(bool should_close)
    : DomainSocket(kInvalidSocketValue, should_close) {}

DomainSocket::DomainSocket(NativeSocket socket, bool should_close)
    : Socket(ProtocolUnixDomain, should_close) {
  m_socket = socket;
}

DomainSocket::DomainSocket(SocketProtocol protocol)
    : Socket(protocol, /*should_close=*/true) {}

DomainSocket::DomainSocket(NativeSocket socket,
                           const DomainSocket &listen_socket)
    : Socket(ProtocolUnixDomain, listen_socket.m_should_close_fd) {
  m_socket = socket;
}

DomainSocket::DomainSocket(SocketProtocol protocol, NativeSocket socket,
                           bool should_close)
    : Socket(protocol, should_close) {
  m_socket = socket;
}

llvm::Expected<DomainSocket::Pair> DomainSocket::CreatePair() {
  int sockets[2];
  int type = SOCK_STREAM;
#ifdef SOCK_CLOEXEC
  type |= SOCK_CLOEXEC;
#endif
  if (socketpair(AF_UNIX, type, 0, sockets) == -1)
    return llvm::errorCodeToError(llvm::errnoAsErrorCode());

#ifndef SOCK_CLOEXEC
  for (int s : sockets) {
    int r = fcntl(s, F_SETFD, FD_CLOEXEC | fcntl(s, F_GETFD));
    assert(r == 0);
    (void)r;
  }
#endif

  return Pair(std::unique_ptr<DomainSocket>(
                  new DomainSocket(ProtocolUnixDomain, sockets[0],
                                   /*should_close=*/true)),
              std::unique_ptr<DomainSocket>(
                  new DomainSocket(ProtocolUnixDomain, sockets[1],
                                   /*should_close=*/true)));
}

Status DomainSocket::Connect(llvm::StringRef name) {
  sockaddr_un saddr_un;
  socklen_t saddr_un_len;
  if (!SetSockAddr(name, GetNameOffset(), &saddr_un, saddr_un_len))
    return Status::FromErrorString("Failed to set socket address");

  Status error;
  m_socket = CreateSocket(kDomain, kType, 0, error);
  if (error.Fail())
    return error;
  if (llvm::sys::RetryAfterSignal(-1, ::connect, GetNativeSocket(),
                                  (struct sockaddr *)&saddr_un,
                                  saddr_un_len) < 0)
    SetLastError(error);

  return error;
}

Status DomainSocket::Listen(llvm::StringRef name, int backlog) {
  sockaddr_un saddr_un;
  socklen_t saddr_un_len;
  if (!SetSockAddr(name, GetNameOffset(), &saddr_un, saddr_un_len))
    return Status::FromErrorString("Failed to set socket address");

  DeleteSocketFile(name);

  Status error;
  m_socket = CreateSocket(kDomain, kType, 0, error);
  if (error.Fail())
    return error;
  if (::bind(GetNativeSocket(), (struct sockaddr *)&saddr_un, saddr_un_len) ==
      0)
    if (::listen(GetNativeSocket(), backlog) == 0)
      return error;

  SetLastError(error);
  return error;
}

llvm::Expected<std::vector<MainLoopBase::ReadHandleUP>> DomainSocket::Accept(
    MainLoopBase &loop,
    std::function<void(std::unique_ptr<Socket> socket)> sock_cb) {
  // TODO: Refactor MainLoop to avoid the shared_ptr requirement.
  auto io_sp = std::make_shared<DomainSocket>(GetNativeSocket(), false);
  auto cb = [this, sock_cb](MainLoopBase &loop) {
    Log *log = GetLog(LLDBLog::Host);
    Status error;
    auto conn_fd = AcceptSocket(GetNativeSocket(), nullptr, nullptr, error);
    if (error.Fail()) {
      LLDB_LOG(log, "AcceptSocket({0}): {1}", GetNativeSocket(), error);
      return;
    }
    std::unique_ptr<DomainSocket> sock_up(new DomainSocket(conn_fd, *this));
    sock_cb(std::move(sock_up));
  };

  Status error;
  std::vector<MainLoopBase::ReadHandleUP> handles;
  handles.emplace_back(loop.RegisterReadObject(io_sp, cb, error));
  if (error.Fail())
    return error.ToError();
  return handles;
}

size_t DomainSocket::GetNameOffset() const { return 0; }

void DomainSocket::DeleteSocketFile(llvm::StringRef name) {
  llvm::sys::fs::remove(name);
}

std::string DomainSocket::GetSocketName() const {
  if (m_socket == kInvalidSocketValue)
    return "";

  struct sockaddr_un saddr_un;
  saddr_un.sun_family = AF_UNIX;
  socklen_t sock_addr_len = sizeof(struct sockaddr_un);
  if (::getpeername(m_socket, (struct sockaddr *)&saddr_un, &sock_addr_len) !=
      0)
    return "";

  if (sock_addr_len <= offsetof(struct sockaddr_un, sun_path))
    return ""; // Unnamed domain socket

  llvm::StringRef name(saddr_un.sun_path + GetNameOffset(),
                       sock_addr_len - offsetof(struct sockaddr_un, sun_path) -
                           GetNameOffset());
  name = name.rtrim('\0');

  return name.str();
}

std::string DomainSocket::GetRemoteConnectionURI() const {
  std::string name = GetSocketName();
  if (name.empty())
    return name;

  return llvm::formatv(
      "{0}://{1}",
      GetNameOffset() == 0 ? "unix-connect" : "unix-abstract-connect", name);
}

std::vector<std::string> DomainSocket::GetListeningConnectionURI() const {
  if (m_socket == kInvalidSocketValue)
    return {};

  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  socklen_t addr_len = sizeof(struct sockaddr_un);
  if (::getsockname(m_socket, (struct sockaddr *)&addr, &addr_len) != 0)
    return {};

  return {llvm::formatv("unix-connect://{0}", addr.sun_path)};
}

llvm::Expected<std::unique_ptr<DomainSocket>>
DomainSocket::FromBoundNativeSocket(NativeSocket sockfd, bool should_close) {
  // Check if fd represents domain socket or abstract socket.
  struct sockaddr_un addr;
  socklen_t addr_len = sizeof(addr);
  if (getsockname(sockfd, (struct sockaddr *)&addr, &addr_len) == -1)
    return llvm::createStringError("not a socket or error occurred");
  if (addr.sun_family != AF_UNIX)
    return llvm::createStringError("Bad socket type");
#ifdef __linux__
  if (addr_len > offsetof(struct sockaddr_un, sun_path) &&
      addr.sun_path[0] == '\0')
    return std::make_unique<AbstractSocket>(sockfd, should_close);
#endif
  return std::make_unique<DomainSocket>(sockfd, should_close);
}
