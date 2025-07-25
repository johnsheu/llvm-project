; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py UTC_ARGS: --version 5
; RUN: llc -mtriple=riscv32 -mattr=+v -verify-machineinstrs < %s | FileCheck %s
; RUN: llc -mtriple=riscv64 -mattr=+v -verify-machineinstrs < %s | FileCheck %s

define <1 x i8> @masked_load_v1i8(ptr %a, <1 x i1> %mask) {
; CHECK-LABEL: masked_load_v1i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 1, e8, mf8, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <1 x i8> @llvm.masked.load.v1i8(ptr %a, i32 8, <1 x i1> %mask, <1 x i8> undef)
  ret <1 x i8> %load
}

define <1 x i16> @masked_load_v1i16(ptr %a, <1 x i1> %mask) {
; CHECK-LABEL: masked_load_v1i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 1, e16, mf4, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <1 x i16> @llvm.masked.load.v1i16(ptr %a, i32 8, <1 x i1> %mask, <1 x i16> undef)
  ret <1 x i16> %load
}

define <1 x i32> @masked_load_v1i32(ptr %a, <1 x i1> %mask) {
; CHECK-LABEL: masked_load_v1i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 1, e32, mf2, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <1 x i32> @llvm.masked.load.v1i32(ptr %a, i32 8, <1 x i1> %mask, <1 x i32> undef)
  ret <1 x i32> %load
}

define <1 x i64> @masked_load_v1i64(ptr %a, <1 x i1> %mask) {
; CHECK-LABEL: masked_load_v1i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 1, e64, m1, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <1 x i64> @llvm.masked.load.v1i64(ptr %a, i32 8, <1 x i1> %mask, <1 x i64> undef)
  ret <1 x i64> %load
}

define <2 x i8> @masked_load_v2i8(ptr %a, <2 x i1> %mask) {
; CHECK-LABEL: masked_load_v2i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 2, e8, mf8, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <2 x i8> @llvm.masked.load.v2i8(ptr %a, i32 8, <2 x i1> %mask, <2 x i8> undef)
  ret <2 x i8> %load
}

define <2 x i16> @masked_load_v2i16(ptr %a, <2 x i1> %mask) {
; CHECK-LABEL: masked_load_v2i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 2, e16, mf4, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <2 x i16> @llvm.masked.load.v2i16(ptr %a, i32 8, <2 x i1> %mask, <2 x i16> undef)
  ret <2 x i16> %load
}

define <2 x i32> @masked_load_v2i32(ptr %a, <2 x i1> %mask) {
; CHECK-LABEL: masked_load_v2i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 2, e32, mf2, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <2 x i32> @llvm.masked.load.v2i32(ptr %a, i32 8, <2 x i1> %mask, <2 x i32> undef)
  ret <2 x i32> %load
}

define <2 x i64> @masked_load_v2i64(ptr %a, <2 x i1> %mask) {
; CHECK-LABEL: masked_load_v2i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 2, e64, m1, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <2 x i64> @llvm.masked.load.v2i64(ptr %a, i32 8, <2 x i1> %mask, <2 x i64> undef)
  ret <2 x i64> %load
}

define <4 x i8> @masked_load_v4i8(ptr %a, <4 x i1> %mask) {
; CHECK-LABEL: masked_load_v4i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 4, e8, mf4, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <4 x i8> @llvm.masked.load.v4i8(ptr %a, i32 8, <4 x i1> %mask, <4 x i8> undef)
  ret <4 x i8> %load
}

define <4 x i16> @masked_load_v4i16(ptr %a, <4 x i1> %mask) {
; CHECK-LABEL: masked_load_v4i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 4, e16, mf2, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <4 x i16> @llvm.masked.load.v4i16(ptr %a, i32 8, <4 x i1> %mask, <4 x i16> undef)
  ret <4 x i16> %load
}

define <4 x i32> @masked_load_v4i32(ptr %a, <4 x i1> %mask) {
; CHECK-LABEL: masked_load_v4i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 4, e32, m1, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <4 x i32> @llvm.masked.load.v4i32(ptr %a, i32 8, <4 x i1> %mask, <4 x i32> undef)
  ret <4 x i32> %load
}

define <4 x i64> @masked_load_v4i64(ptr %a, <4 x i1> %mask) {
; CHECK-LABEL: masked_load_v4i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 4, e64, m2, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <4 x i64> @llvm.masked.load.v4i64(ptr %a, i32 8, <4 x i1> %mask, <4 x i64> undef)
  ret <4 x i64> %load
}

define <8 x i8> @masked_load_v8i8(ptr %a, <8 x i1> %mask) {
; CHECK-LABEL: masked_load_v8i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 8, e8, mf2, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <8 x i8> @llvm.masked.load.v8i8(ptr %a, i32 8, <8 x i1> %mask, <8 x i8> undef)
  ret <8 x i8> %load
}

define <8 x i16> @masked_load_v8i16(ptr %a, <8 x i1> %mask) {
; CHECK-LABEL: masked_load_v8i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 8, e16, m1, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <8 x i16> @llvm.masked.load.v8i16(ptr %a, i32 8, <8 x i1> %mask, <8 x i16> undef)
  ret <8 x i16> %load
}

define <8 x i32> @masked_load_v8i32(ptr %a, <8 x i1> %mask) {
; CHECK-LABEL: masked_load_v8i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 8, e32, m2, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <8 x i32> @llvm.masked.load.v8i32(ptr %a, i32 8, <8 x i1> %mask, <8 x i32> undef)
  ret <8 x i32> %load
}

define <8 x i64> @masked_load_v8i64(ptr %a, <8 x i1> %mask) {
; CHECK-LABEL: masked_load_v8i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 8, e64, m4, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <8 x i64> @llvm.masked.load.v8i64(ptr %a, i32 8, <8 x i1> %mask, <8 x i64> undef)
  ret <8 x i64> %load
}

define <16 x i8> @masked_load_v16i8(ptr %a, <16 x i1> %mask) {
; CHECK-LABEL: masked_load_v16i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 16, e8, m1, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <16 x i8> @llvm.masked.load.v16i8(ptr %a, i32 8, <16 x i1> %mask, <16 x i8> undef)
  ret <16 x i8> %load
}

define <16 x i16> @masked_load_v16i16(ptr %a, <16 x i1> %mask) {
; CHECK-LABEL: masked_load_v16i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 16, e16, m2, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <16 x i16> @llvm.masked.load.v16i16(ptr %a, i32 8, <16 x i1> %mask, <16 x i16> undef)
  ret <16 x i16> %load
}

define <16 x i32> @masked_load_v16i32(ptr %a, <16 x i1> %mask) {
; CHECK-LABEL: masked_load_v16i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 16, e32, m4, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <16 x i32> @llvm.masked.load.v16i32(ptr %a, i32 8, <16 x i1> %mask, <16 x i32> undef)
  ret <16 x i32> %load
}

define <16 x i64> @masked_load_v16i64(ptr %a, <16 x i1> %mask) {
; CHECK-LABEL: masked_load_v16i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 16, e64, m8, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <16 x i64> @llvm.masked.load.v16i64(ptr %a, i32 8, <16 x i1> %mask, <16 x i64> undef)
  ret <16 x i64> %load
}

define <32 x i8> @masked_load_v32i8(ptr %a, <32 x i1> %mask) {
; CHECK-LABEL: masked_load_v32i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 32
; CHECK-NEXT:    vsetvli zero, a1, e8, m2, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <32 x i8> @llvm.masked.load.v32i8(ptr %a, i32 8, <32 x i1> %mask, <32 x i8> undef)
  ret <32 x i8> %load
}

define <32 x i16> @masked_load_v32i16(ptr %a, <32 x i1> %mask) {
; CHECK-LABEL: masked_load_v32i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 32
; CHECK-NEXT:    vsetvli zero, a1, e16, m4, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <32 x i16> @llvm.masked.load.v32i16(ptr %a, i32 8, <32 x i1> %mask, <32 x i16> undef)
  ret <32 x i16> %load
}

define <32 x i32> @masked_load_v32i32(ptr %a, <32 x i1> %mask) {
; CHECK-LABEL: masked_load_v32i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 32
; CHECK-NEXT:    vsetvli zero, a1, e32, m8, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <32 x i32> @llvm.masked.load.v32i32(ptr %a, i32 8, <32 x i1> %mask, <32 x i32> undef)
  ret <32 x i32> %load
}

define <32 x i64> @masked_load_v32i64(ptr %a, <32 x i1> %mask) {
; CHECK-LABEL: masked_load_v32i64:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 16, e64, m8, ta, ma
; CHECK-NEXT:    vle64.v v8, (a0), v0.t
; CHECK-NEXT:    vsetivli zero, 2, e8, mf4, ta, ma
; CHECK-NEXT:    vslidedown.vi v0, v0, 2
; CHECK-NEXT:    addi a0, a0, 128
; CHECK-NEXT:    vsetivli zero, 16, e64, m8, ta, ma
; CHECK-NEXT:    vle64.v v16, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <32 x i64> @llvm.masked.load.v32i64(ptr %a, i32 8, <32 x i1> %mask, <32 x i64> undef)
  ret <32 x i64> %load
}

define <64 x i8> @masked_load_v64i8(ptr %a, <64 x i1> %mask) {
; CHECK-LABEL: masked_load_v64i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 64
; CHECK-NEXT:    vsetvli zero, a1, e8, m4, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <64 x i8> @llvm.masked.load.v64i8(ptr %a, i32 8, <64 x i1> %mask, <64 x i8> undef)
  ret <64 x i8> %load
}

define <64 x i16> @masked_load_v64i16(ptr %a, <64 x i1> %mask) {
; CHECK-LABEL: masked_load_v64i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 64
; CHECK-NEXT:    vsetvli zero, a1, e16, m8, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <64 x i16> @llvm.masked.load.v64i16(ptr %a, i32 8, <64 x i1> %mask, <64 x i16> undef)
  ret <64 x i16> %load
}

define <64 x i32> @masked_load_v64i32(ptr %a, <64 x i1> %mask) {
; CHECK-LABEL: masked_load_v64i32:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 32
; CHECK-NEXT:    vsetvli zero, a1, e32, m8, ta, ma
; CHECK-NEXT:    vle32.v v8, (a0), v0.t
; CHECK-NEXT:    vsetivli zero, 4, e8, mf2, ta, ma
; CHECK-NEXT:    vslidedown.vi v0, v0, 4
; CHECK-NEXT:    addi a0, a0, 128
; CHECK-NEXT:    vsetvli zero, a1, e32, m8, ta, ma
; CHECK-NEXT:    vle32.v v16, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <64 x i32> @llvm.masked.load.v64i32(ptr %a, i32 8, <64 x i1> %mask, <64 x i32> undef)
  ret <64 x i32> %load
}

define <128 x i8> @masked_load_v128i8(ptr %a, <128 x i1> %mask) {
; CHECK-LABEL: masked_load_v128i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 128
; CHECK-NEXT:    vsetvli zero, a1, e8, m8, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <128 x i8> @llvm.masked.load.v128i8(ptr %a, i32 8, <128 x i1> %mask, <128 x i8> undef)
  ret <128 x i8> %load
}

define <128 x i16> @masked_load_v128i16(ptr %a, <128 x i1> %mask) {
; CHECK-LABEL: masked_load_v128i16:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 64
; CHECK-NEXT:    vsetvli zero, a1, e16, m8, ta, ma
; CHECK-NEXT:    vle16.v v8, (a0), v0.t
; CHECK-NEXT:    vsetivli zero, 8, e8, m1, ta, ma
; CHECK-NEXT:    vslidedown.vi v0, v0, 8
; CHECK-NEXT:    addi a0, a0, 128
; CHECK-NEXT:    vsetvli zero, a1, e16, m8, ta, ma
; CHECK-NEXT:    vle16.v v16, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <128 x i16> @llvm.masked.load.v128i16(ptr %a, i32 8, <128 x i1> %mask, <128 x i16> undef)
  ret <128 x i16> %load
}

define <256 x i8> @masked_load_v256i8(ptr %a, <256 x i1> %mask) {
; CHECK-LABEL: masked_load_v256i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 1, e8, m1, ta, ma
; CHECK-NEXT:    vmv1r.v v16, v8
; CHECK-NEXT:    li a1, 128
; CHECK-NEXT:    vsetvli zero, a1, e8, m8, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    addi a0, a0, 128
; CHECK-NEXT:    vmv1r.v v0, v16
; CHECK-NEXT:    vle8.v v16, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <256 x i8> @llvm.masked.load.v256i8(ptr %a, i32 8, <256 x i1> %mask, <256 x i8> undef)
  ret <256 x i8> %load
}

define <7 x i8> @masked_load_v7i8(ptr %a, <7 x i1> %mask) {
; CHECK-LABEL: masked_load_v7i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsetivli zero, 7, e8, mf2, ta, ma
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <7 x i8> @llvm.masked.load.v7i8(ptr %a, i32 8, <7 x i1> %mask, <7 x i8> undef)
  ret <7 x i8> %load
}

define <7 x i8> @masked_load_passthru_v7i8(ptr %a, <7 x i1> %mask) {
; CHECK-LABEL: masked_load_passthru_v7i8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    li a1, 127
; CHECK-NEXT:    vsetivli zero, 8, e8, mf2, ta, mu
; CHECK-NEXT:    vmv.s.x v8, a1
; CHECK-NEXT:    vmand.mm v0, v0, v8
; CHECK-NEXT:    vmv.v.i v8, 0
; CHECK-NEXT:    vle8.v v8, (a0), v0.t
; CHECK-NEXT:    ret
  %load = call <7 x i8> @llvm.masked.load.v7i8(ptr %a, i32 8, <7 x i1> %mask, <7 x i8> zeroinitializer)
  ret <7 x i8> %load
}
