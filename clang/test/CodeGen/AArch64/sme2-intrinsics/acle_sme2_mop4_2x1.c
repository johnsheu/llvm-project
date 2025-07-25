// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py

// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme-mop4 -target-feature +sme-f16f16 -target-feature +sme-i16i64 -target-feature +sme-b16b16 -target-feature +sme-f64f64 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSME_OVERLOADED_FORMS -triple aarch64 -target-feature +sme-mop4 -target-feature +sme-f16f16 -target-feature +sme-i16i64 -target-feature +sme-b16b16 -target-feature +sme-f64f64 -target-feature +sme -target-feature +sme2 -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -p mem2reg,instcombine,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64 -target-feature +sme-mop4 -target-feature +sme-f16f16 -target-feature +sme-i16i64 -target-feature +sme-b16b16 -target-feature +sme-f64f64 -target-feature +sme -target-feature +sme2 -S -disable-O0-optnone -Werror -Wall -o /dev/null %s


#include <arm_sme.h>

#ifdef SME_OVERLOADED_FORMS
#define SME_ACLE_FUNC(A1,A2_UNUSED,A3, A4_UNUSED) A1##A3
#else
#define SME_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svmop4a_2x1_za32_s8_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4a.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_s8_s8(svint8x2_t zn, svint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_s8_s8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_s8_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4s.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_s8_s8(svint8x2_t zn, svint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_s8_s8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_u8_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4a.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_u8_u8(svuint8x2_t zn, svuint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_u8_u8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_u8_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4s.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_u8_u8(svuint8x2_t zn, svuint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_u8_u8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_s8_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.sumop4a.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_s8_u8(svint8x2_t zn, svuint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_s8_u8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_s8_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.sumop4s.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_s8_u8(svint8x2_t zn, svuint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_s8_u8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_u8_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.usmop4a.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_u8_s8(svuint8x2_t zn, svint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_u8_s8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_u8_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.usmop4s.wide.2x1.nxv16i8(i32 1, <vscale x 16 x i8> [[ZN_COERCE0:%.*]], <vscale x 16 x i8> [[ZN_COERCE1:%.*]], <vscale x 16 x i8> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_u8_s8(svuint8x2_t zn, svint8_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_u8_s8)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_s16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4a.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_s16_s16(svint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_s16_s16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_s16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4s.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_s16_s16(svint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_s16_s16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_u16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4a.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_u16_u16(svuint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_u16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_u16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4a.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_u16_u16(svuint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_u16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_f16_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.wide.2x1.nxv8f16(i32 1, <vscale x 8 x half> [[ZN_COERCE0:%.*]], <vscale x 8 x half> [[ZN_COERCE1:%.*]], <vscale x 8 x half> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_f16_f16(svfloat16x2_t zn, svfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_f16_f16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_f16_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.wide.2x1.nxv8f16(i32 1, <vscale x 8 x half> [[ZN_COERCE0:%.*]], <vscale x 8 x half> [[ZN_COERCE1:%.*]], <vscale x 8 x half> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_f16_f16(svfloat16x2_t zn, svfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_f16_f16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_bf16_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.wide.2x1.nxv8bf16(i32 1, <vscale x 8 x bfloat> [[ZN_COERCE0:%.*]], <vscale x 8 x bfloat> [[ZN_COERCE1:%.*]], <vscale x 8 x bfloat> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_bf16_bf16(svbfloat16x2_t zn, svbfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_bf16_bf16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_bf16_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.wide.2x1.nxv8bf16(i32 1, <vscale x 8 x bfloat> [[ZN_COERCE0:%.*]], <vscale x 8 x bfloat> [[ZN_COERCE1:%.*]], <vscale x 8 x bfloat> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_bf16_bf16(svbfloat16x2_t zn, svbfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_bf16_bf16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za64_s16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4a.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za64_s16_s16(svint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za64,_s16_s16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za64_s16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.smop4s.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za64_s16_s16(svint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za64,_s16_s16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za64_u16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4a.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za64_u16_u16(svuint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za64,_u16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za64_u16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.umop4s.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za64_u16_u16(svuint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za64,_u16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za64_s16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.sumop4a.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za64_s16_u16(svint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za64,_s16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za64_s16_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.sumop4s.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za64_s16_u16(svint16x2_t zn, svuint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za64,_s16_u16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za64_u16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.usmop4a.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za64_u16_s16(svuint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za64,_u16_s16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za64_u16_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.usmop4s.za64.wide.2x1.nxv8i16(i32 1, <vscale x 8 x i16> [[ZN_COERCE0:%.*]], <vscale x 8 x i16> [[ZN_COERCE1:%.*]], <vscale x 8 x i16> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za64_u16_s16(svuint16x2_t zn, svint16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za64,_u16_s16)(1, zn, zm);
}


// CHECK-LABEL: @test_svmop4a_2x1_za16_f16_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.2x1.nxv8f16(i32 1, <vscale x 8 x half> [[ZN_COERCE0:%.*]], <vscale x 8 x half> [[ZN_COERCE1:%.*]], <vscale x 8 x half> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za16_f16_f16(svfloat16x2_t zn, svfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za16,_f16_f16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za16_f16_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.2x1.nxv8f16(i32 1, <vscale x 8 x half> [[ZN_COERCE0:%.*]], <vscale x 8 x half> [[ZN_COERCE1:%.*]], <vscale x 8 x half> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za16_f16_f16(svfloat16x2_t zn, svfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za16,_f16_f16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za32_f32_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.2x1.nxv4f32(i32 1, <vscale x 4 x float> [[ZN_COERCE0:%.*]], <vscale x 4 x float> [[ZN_COERCE1:%.*]], <vscale x 4 x float> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za32_f32_f32(svfloat32x2_t zn, svfloat32_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za32,_f32_f32)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za32_f32_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.2x1.nxv4f32(i32 1, <vscale x 4 x float> [[ZN_COERCE0:%.*]], <vscale x 4 x float> [[ZN_COERCE1:%.*]], <vscale x 4 x float> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za32_f32_f32(svfloat32x2_t zn, svfloat32_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za32,_f32_f32)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za64_f64_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.2x1.nxv2f64(i32 1, <vscale x 2 x double> [[ZN_COERCE0:%.*]], <vscale x 2 x double> [[ZN_COERCE1:%.*]], <vscale x 2 x double> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za64_f64_f64(svfloat64x2_t zn, svfloat64_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za64,_f64_f64)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za64_f64_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.2x1.nxv2f64(i32 1, <vscale x 2 x double> [[ZN_COERCE0:%.*]], <vscale x 2 x double> [[ZN_COERCE1:%.*]], <vscale x 2 x double> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za64_f64_f64(svfloat64x2_t zn, svfloat64_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za64,_f64_f64)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4a_2x1_za16_bf16_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4a.2x1.nxv8bf16(i32 1, <vscale x 8 x bfloat> [[ZN_COERCE0:%.*]], <vscale x 8 x bfloat> [[ZN_COERCE1:%.*]], <vscale x 8 x bfloat> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4a_2x1_za16_bf16_bf16(svbfloat16x2_t zn, svbfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4a,_2x1,_za16,_bf16_bf16)(1, zn, zm);
}

// CHECK-LABEL: @test_svmop4s_2x1_za16_bf16_bf16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    tail call void @llvm.aarch64.sme.mop4s.2x1.nxv8bf16(i32 1, <vscale x 8 x bfloat> [[ZN_COERCE0:%.*]], <vscale x 8 x bfloat> [[ZN_COERCE1:%.*]], <vscale x 8 x bfloat> [[ZM:%.*]])
// CHECK-NEXT:    ret void
//
void test_svmop4s_2x1_za16_bf16_bf16(svbfloat16x2_t zn, svbfloat16_t zm) __arm_streaming __arm_inout("za") {
  SME_ACLE_FUNC(svmop4s,_2x1,_za16,_bf16_bf16)(1, zn, zm);
}
