//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <clc/opencl/atomic/atomic_cmpxchg.h>

#define IMPL(TYPE, AS)                                                         \
  _CLC_OVERLOAD _CLC_DEF TYPE atomic_cmpxchg(volatile AS TYPE *p, TYPE cmp,    \
                                             TYPE val) {                       \
    return __sync_val_compare_and_swap(p, cmp, val);                           \
  }

IMPL(int, global)
IMPL(unsigned int, global)
IMPL(int, local)
IMPL(unsigned int, local)
#undef IMPL
