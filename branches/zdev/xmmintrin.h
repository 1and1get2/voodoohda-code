/* APPLE LOCAL file mainline 2005-06-30 Radar 4131077 */
/* Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, if you include this header file into source
   files compiled by GCC, this header file does not by itself cause
   the resulting executable to be covered by the GNU General Public
   License.  This exception does not however invalidate any other
   reasons why the executable file might be covered by the GNU General
   Public License.  */

/* Implemented from the specification included in the Intel C++ Compiler
   User Guide and Reference, version 9.0.  */

#ifndef _XMMINTRIN_H_INCLUDED
#define _XMMINTRIN_H_INCLUDED

#ifdef __clang__

#ifndef __XMMINTRIN_H
#define __XMMINTRIN_H

#ifndef __SSE__
#error "SSE instruction set not enabled"
#else

#include "mmintrin.h"

typedef int __v4si __attribute__((__vector_size__(16)));
typedef float __v4sf __attribute__((__vector_size__(16)));
typedef float __m128 __attribute__((__vector_size__(16)));

// This header should only be included in a hosted environment as it depends on
// a standard library to provide allocation routines.
#if __STDC_HOSTED__
#include <mm_malloc.h>
#endif

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_add_ss(__m128 __a, __m128 __b)
{
    __a[0] += __b[0];
    return __a;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_add_ps(__m128 __a, __m128 __b)
{
    return __a + __b;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_sub_ss(__m128 __a, __m128 __b)
{
    __a[0] -= __b[0];
    return __a;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_sub_ps(__m128 __a, __m128 __b)
{
    return __a - __b;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_mul_ss(__m128 __a, __m128 __b)
{
    __a[0] *= __b[0];
    return __a;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_mul_ps(__m128 __a, __m128 __b)
{
    return __a * __b;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_div_ss(__m128 __a, __m128 __b)
{
    __a[0] /= __b[0];
    return __a;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_div_ps(__m128 __a, __m128 __b)
{
    return __a / __b;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_sqrt_ss(__m128 __a)
{
    __m128 __c = __builtin_ia32_sqrtss(__a);
    return (__m128) { __c[0], __a[1], __a[2], __a[3] };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_sqrt_ps(__m128 __a)
{
    return __builtin_ia32_sqrtps(__a);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_rcp_ss(__m128 __a)
{
    __m128 __c = __builtin_ia32_rcpss(__a);
    return (__m128) { __c[0], __a[1], __a[2], __a[3] };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_rcp_ps(__m128 __a)
{
    return __builtin_ia32_rcpps(__a);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_rsqrt_ss(__m128 __a)
{
    __m128 __c = __builtin_ia32_rsqrtss(__a);
    return (__m128) { __c[0], __a[1], __a[2], __a[3] };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_rsqrt_ps(__m128 __a)
{
    return __builtin_ia32_rsqrtps(__a);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_min_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_minss(__a, __b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_min_ps(__m128 __a, __m128 __b)
{
    return __builtin_ia32_minps(__a, __b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_max_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_maxss(__a, __b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_max_ps(__m128 __a, __m128 __b)
{
    return __builtin_ia32_maxps(__a, __b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_and_ps(__m128 __a, __m128 __b)
{
    return (__m128)((__v4si)__a & (__v4si)__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_andnot_ps(__m128 __a, __m128 __b)
{
    return (__m128)(~(__v4si)__a & (__v4si)__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_or_ps(__m128 __a, __m128 __b)
{
    return (__m128)((__v4si)__a | (__v4si)__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_xor_ps(__m128 __a, __m128 __b)
{
    return (__m128)((__v4si)__a ^ (__v4si)__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpeq_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 0);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpeq_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 0);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmplt_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 1);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmplt_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 1);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmple_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 2);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmple_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 2);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpgt_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_shufflevector(__a,
                                           __builtin_ia32_cmpss(__b, __a, 1),
                                           4, 1, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpgt_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__b, __a, 1);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpge_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_shufflevector(__a,
                                           __builtin_ia32_cmpss(__b, __a, 2),
                                           4, 1, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpge_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__b, __a, 2);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpneq_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 4);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpneq_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 4);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnlt_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnlt_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnle_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 6);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnle_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 6);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpngt_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_shufflevector(__a,
                                           __builtin_ia32_cmpss(__b, __a, 5),
                                           4, 1, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpngt_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__b, __a, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnge_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_shufflevector(__a,
                                           __builtin_ia32_cmpss(__b, __a, 6),
                                           4, 1, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpnge_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__b, __a, 6);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpord_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 7);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpord_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 7);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpunord_ss(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpss(__a, __b, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cmpunord_ps(__m128 __a, __m128 __b)
{
    return (__m128)__builtin_ia32_cmpps(__a, __b, 3);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comieq_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comieq(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comilt_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comilt(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comile_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comile(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comigt_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comigt(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comige_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comige(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_comineq_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_comineq(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomieq_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomieq(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomilt_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomilt(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomile_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomile(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomigt_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomigt(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomige_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomige(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_ucomineq_ss(__m128 __a, __m128 __b)
{
    return __builtin_ia32_ucomineq(__a, __b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_cvtss_si32(__m128 __a)
{
    return __builtin_ia32_cvtss2si(__a);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_cvt_ss2si(__m128 __a)
{
    return _mm_cvtss_si32(__a);
}

#ifdef __x86_64__

static __inline__ long long __attribute__((__always_inline__, __nodebug__))
_mm_cvtss_si64(__m128 __a)
{
    return __builtin_ia32_cvtss2si64(__a);
}

#endif

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtps_pi32(__m128 __a)
{
    return (__m64)__builtin_ia32_cvtps2pi(__a);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvt_ps2pi(__m128 __a)
{
    return _mm_cvtps_pi32(__a);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_cvttss_si32(__m128 __a)
{
    return __a[0];
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_cvtt_ss2si(__m128 __a)
{
    return _mm_cvttss_si32(__a);
}

static __inline__ long long __attribute__((__always_inline__, __nodebug__))
_mm_cvttss_si64(__m128 __a)
{
    return __a[0];
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvttps_pi32(__m128 __a)
{
    return (__m64)__builtin_ia32_cvttps2pi(__a);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtt_ps2pi(__m128 __a)
{
    return _mm_cvttps_pi32(__a);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtsi32_ss(__m128 __a, int __b)
{
    __a[0] = __b;
    return __a;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvt_si2ss(__m128 __a, int __b)
{
    return _mm_cvtsi32_ss(__a, __b);
}

#ifdef __x86_64__

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtsi64_ss(__m128 __a, long long __b)
{
    __a[0] = __b;
    return __a;
}

#endif

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpi32_ps(__m128 __a, __m64 __b)
{
    return __builtin_ia32_cvtpi2ps(__a, (__v2si)__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvt_pi2ps(__m128 __a, __m64 __b)
{
    return _mm_cvtpi32_ps(__a, __b);
}

static __inline__ float __attribute__((__always_inline__, __nodebug__))
_mm_cvtss_f32(__m128 __a)
{
    return __a[0];
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_loadh_pi(__m128 __a, const __m64 *__p)
{
    typedef float __mm_loadh_pi_v2f32 __attribute__((__vector_size__(8)));
    struct __mm_loadh_pi_struct {
        __mm_loadh_pi_v2f32 __u;
    } __attribute__((__packed__, __may_alias__));
    __mm_loadh_pi_v2f32 __b = ((struct __mm_loadh_pi_struct*)__p)->__u;
    __m128 __bb = __builtin_shufflevector(__b, __b, 0, 1, 0, 1);
    return __builtin_shufflevector(__a, __bb, 0, 1, 4, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_loadl_pi(__m128 __a, const __m64 *__p)
{
    typedef float __mm_loadl_pi_v2f32 __attribute__((__vector_size__(8)));
    struct __mm_loadl_pi_struct {
        __mm_loadl_pi_v2f32 __u;
    } __attribute__((__packed__, __may_alias__));
    __mm_loadl_pi_v2f32 __b = ((struct __mm_loadl_pi_struct*)__p)->__u;
    __m128 __bb = __builtin_shufflevector(__b, __b, 0, 1, 0, 1);
    return __builtin_shufflevector(__a, __bb, 4, 5, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_load_ss(const float *__p)
{
    struct __mm_load_ss_struct {
        float __u;
    } __attribute__((__packed__, __may_alias__));
    float __u = ((struct __mm_load_ss_struct*)__p)->__u;
    return (__m128){ __u, 0, 0, 0 };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_load1_ps(const float *__p)
{
    struct __mm_load1_ps_struct {
        float __u;
    } __attribute__((__packed__, __may_alias__));
    float __u = ((struct __mm_load1_ps_struct*)__p)->__u;
    return (__m128){ __u, __u, __u, __u };
}

#define        _mm_load_ps1(p) _mm_load1_ps(p)

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_load_ps(const float *__p)
{
    return *(__m128*)__p;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_loadu_ps(const float *__p)
{
    struct __loadu_ps {
        __m128 __v;
    } __attribute__((__packed__, __may_alias__));
    return ((struct __loadu_ps*)__p)->__v;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_loadr_ps(const float *__p)
{
    __m128 __a = _mm_load_ps(__p);
    return __builtin_shufflevector(__a, __a, 3, 2, 1, 0);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_set_ss(float __w)
{
    return (__m128){ __w, 0, 0, 0 };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_set1_ps(float __w)
{
    return (__m128){ __w, __w, __w, __w };
}

// Microsoft specific.
static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_set_ps1(float __w)
{
    return _mm_set1_ps(__w);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_set_ps(float __z, float __y, float __x, float __w)
{
    return (__m128){ __w, __x, __y, __z };
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_setr_ps(float __z, float __y, float __x, float __w)
{
    return (__m128){ __z, __y, __x, __w };
}

static __inline__ __m128 __attribute__((__always_inline__))
_mm_setzero_ps(void)
{
    return (__m128){ 0, 0, 0, 0 };
}

static __inline__ void __attribute__((__always_inline__))
_mm_storeh_pi(__m64 *__p, __m128 __a)
{
    __builtin_ia32_storehps((__v2si *)__p, __a);
}

static __inline__ void __attribute__((__always_inline__))
_mm_storel_pi(__m64 *__p, __m128 __a)
{
    __builtin_ia32_storelps((__v2si *)__p, __a);
}

static __inline__ void __attribute__((__always_inline__))
_mm_store_ss(float *__p, __m128 __a)
{
    struct __mm_store_ss_struct {
        float __u;
    } __attribute__((__packed__, __may_alias__));
    ((struct __mm_store_ss_struct*)__p)->__u = __a[0];
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_storeu_ps(float *__p, __m128 __a)
{
    __builtin_ia32_storeups(__p, __a);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_store1_ps(float *__p, __m128 __a)
{
    __a = __builtin_shufflevector(__a, __a, 0, 0, 0, 0);
    _mm_storeu_ps(__p, __a);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_store_ps1(float *__p, __m128 __a)
{
    return _mm_store1_ps(__p, __a);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_store_ps(float *__p, __m128 __a)
{
    *(__m128 *)__p = __a;
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_storer_ps(float *__p, __m128 __a)
{
    __a = __builtin_shufflevector(__a, __a, 3, 2, 1, 0);
    _mm_store_ps(__p, __a);
}

#define _MM_HINT_T0 3
#define _MM_HINT_T1 2
#define _MM_HINT_T2 1
#define _MM_HINT_NTA 0

/* FIXME: We have to #define this because "sel" must be a constant integer, and
 Sema doesn't do any form of constant propagation yet. */

#define _mm_prefetch(a, sel) (__builtin_prefetch((void *)(a), 0, (sel)))

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_stream_pi(__m64 *__p, __m64 __a)
{
    __builtin_ia32_movntq(__p, __a);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_stream_ps(float *__p, __m128 __a)
{
    __builtin_ia32_movntps(__p, __a);
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_sfence(void)
{
    __builtin_ia32_sfence();
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_extract_pi16(__m64 __a, int __n)
{
    __v4hi __b = (__v4hi)__a;
    return (unsigned short)__b[__n & 3];
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_insert_pi16(__m64 __a, int __d, int __n)
{
    __v4hi __b = (__v4hi)__a;
    __b[__n & 3] = __d;
    return (__m64)__b;
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_max_pi16(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pmaxsw((__v4hi)__a, (__v4hi)__b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_max_pu8(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pmaxub((__v8qi)__a, (__v8qi)__b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_min_pi16(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pminsw((__v4hi)__a, (__v4hi)__b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_min_pu8(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pminub((__v8qi)__a, (__v8qi)__b);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_movemask_pi8(__m64 __a)
{
    return __builtin_ia32_pmovmskb((__v8qi)__a);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_mulhi_pu16(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pmulhuw((__v4hi)__a, (__v4hi)__b);
}

#define _mm_shuffle_pi16(a, n) __extension__ ({ \
__m64 __a = (a); \
(__m64)__builtin_ia32_pshufw((__v4hi)__a, (n)); })

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_maskmove_si64(__m64 __d, __m64 __n, char *__p)
{
    __builtin_ia32_maskmovq((__v8qi)__d, (__v8qi)__n, __p);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_avg_pu8(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pavgb((__v8qi)__a, (__v8qi)__b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_avg_pu16(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_pavgw((__v4hi)__a, (__v4hi)__b);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_sad_pu8(__m64 __a, __m64 __b)
{
    return (__m64)__builtin_ia32_psadbw((__v8qi)__a, (__v8qi)__b);
}

static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
_mm_getcsr(void)
{
    return __builtin_ia32_stmxcsr();
}

static __inline__ void __attribute__((__always_inline__, __nodebug__))
_mm_setcsr(unsigned int __i)
{
    __builtin_ia32_ldmxcsr(__i);
}

#define _mm_shuffle_ps(a, b, mask) __extension__ ({ \
__m128 __a = (a); \
__m128 __b = (b); \
(__m128)__builtin_shufflevector((__v4sf)__a, (__v4sf)__b, \
(mask) & 0x3, ((mask) & 0xc) >> 2, \
(((mask) & 0x30) >> 4) + 4, \
(((mask) & 0xc0) >> 6) + 4); })

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_unpackhi_ps(__m128 __a, __m128 __b)
{
    return __builtin_shufflevector(__a, __b, 2, 6, 3, 7);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_unpacklo_ps(__m128 __a, __m128 __b)
{
    return __builtin_shufflevector(__a, __b, 0, 4, 1, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_move_ss(__m128 __a, __m128 __b)
{
    return __builtin_shufflevector(__a, __b, 4, 1, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_movehl_ps(__m128 __a, __m128 __b)
{
    return __builtin_shufflevector(__a, __b, 6, 7, 2, 3);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_movelh_ps(__m128 __a, __m128 __b)
{
    return __builtin_shufflevector(__a, __b, 0, 1, 4, 5);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpi16_ps(__m64 __a)
{
    __m64 __b, __c;
    __m128 __r;
    
    __b = _mm_setzero_si64();
    __b = _mm_cmpgt_pi16(__b, __a);
    __c = _mm_unpackhi_pi16(__a, __b);
    __r = _mm_setzero_ps();
    __r = _mm_cvtpi32_ps(__r, __c);
    __r = _mm_movelh_ps(__r, __r);
    __c = _mm_unpacklo_pi16(__a, __b);
    __r = _mm_cvtpi32_ps(__r, __c);
    
    return __r;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpu16_ps(__m64 __a)
{
    __m64 __b, __c;
    __m128 __r;
    
    __b = _mm_setzero_si64();
    __c = _mm_unpackhi_pi16(__a, __b);
    __r = _mm_setzero_ps();
    __r = _mm_cvtpi32_ps(__r, __c);
    __r = _mm_movelh_ps(__r, __r);
    __c = _mm_unpacklo_pi16(__a, __b);
    __r = _mm_cvtpi32_ps(__r, __c);
    
    return __r;
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpi8_ps(__m64 __a)
{
    __m64 __b;
    
    __b = _mm_setzero_si64();
    __b = _mm_cmpgt_pi8(__b, __a);
    __b = _mm_unpacklo_pi8(__a, __b);
    
    return _mm_cvtpi16_ps(__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpu8_ps(__m64 __a)
{
    __m64 __b;
    
    __b = _mm_setzero_si64();
    __b = _mm_unpacklo_pi8(__a, __b);
    
    return _mm_cvtpi16_ps(__b);
}

static __inline__ __m128 __attribute__((__always_inline__, __nodebug__))
_mm_cvtpi32x2_ps(__m64 __a, __m64 __b)
{
    __m128 __c;
    
    __c = _mm_setzero_ps();
    __c = _mm_cvtpi32_ps(__c, __b);
    __c = _mm_movelh_ps(__c, __c);
    
    return _mm_cvtpi32_ps(__c, __a);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtps_pi16(__m128 __a)
{
    __m64 __b, __c;
    
    __b = _mm_cvtps_pi32(__a);
    __a = _mm_movehl_ps(__a, __a);
    __c = _mm_cvtps_pi32(__a);
    
    return _mm_packs_pi16(__b, __c);
}

static __inline__ __m64 __attribute__((__always_inline__, __nodebug__))
_mm_cvtps_pi8(__m128 __a)
{
    __m64 __b, __c;
    
    __b = _mm_cvtps_pi16(__a);
    __c = _mm_setzero_si64();
    
    return _mm_packs_pi16(__b, __c);
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
_mm_movemask_ps(__m128 __a)
{
    return __builtin_ia32_movmskps(__a);
}

#define _MM_SHUFFLE(z, y, x, w) (((z) << 6) | ((y) << 4) | ((x) << 2) | (w))

#define _MM_EXCEPT_INVALID    (0x0001)
#define _MM_EXCEPT_DENORM     (0x0002)
#define _MM_EXCEPT_DIV_ZERO   (0x0004)
#define _MM_EXCEPT_OVERFLOW   (0x0008)
#define _MM_EXCEPT_UNDERFLOW  (0x0010)
#define _MM_EXCEPT_INEXACT    (0x0020)
#define _MM_EXCEPT_MASK       (0x003f)

#define _MM_MASK_INVALID      (0x0080)
#define _MM_MASK_DENORM       (0x0100)
#define _MM_MASK_DIV_ZERO     (0x0200)
#define _MM_MASK_OVERFLOW     (0x0400)
#define _MM_MASK_UNDERFLOW    (0x0800)
#define _MM_MASK_INEXACT      (0x1000)
#define _MM_MASK_MASK         (0x1f80)

#define _MM_ROUND_NEAREST     (0x0000)
#define _MM_ROUND_DOWN        (0x2000)
#define _MM_ROUND_UP          (0x4000)
#define _MM_ROUND_TOWARD_ZERO (0x6000)
#define _MM_ROUND_MASK        (0x6000)

#define _MM_FLUSH_ZERO_MASK   (0x8000)
#define _MM_FLUSH_ZERO_ON     (0x8000)
#define _MM_FLUSH_ZERO_OFF    (0x0000)

#define _MM_GET_EXCEPTION_MASK() (_mm_getcsr() & _MM_MASK_MASK)
#define _MM_GET_EXCEPTION_STATE() (_mm_getcsr() & _MM_EXCEPT_MASK)
#define _MM_GET_FLUSH_ZERO_MODE() (_mm_getcsr() & _MM_FLUSH_ZERO_MASK)
#define _MM_GET_ROUNDING_MODE() (_mm_getcsr() & _MM_ROUND_MASK)

#define _MM_SET_EXCEPTION_MASK(x) (_mm_setcsr((_mm_getcsr() & ~_MM_MASK_MASK) | (x)))
#define _MM_SET_EXCEPTION_STATE(x) (_mm_setcsr((_mm_getcsr() & ~_MM_EXCEPT_MASK) | (x)))
#define _MM_SET_FLUSH_ZERO_MODE(x) (_mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | (x)))
#define _MM_SET_ROUNDING_MODE(x) (_mm_setcsr((_mm_getcsr() & ~_MM_ROUND_MASK) | (x)))

#define _MM_TRANSPOSE4_PS(row0, row1, row2, row3) \
do { \
__m128 tmp3, tmp2, tmp1, tmp0; \
tmp0 = _mm_unpacklo_ps((row0), (row1)); \
tmp2 = _mm_unpacklo_ps((row2), (row3)); \
tmp1 = _mm_unpackhi_ps((row0), (row1)); \
tmp3 = _mm_unpackhi_ps((row2), (row3)); \
(row0) = _mm_movelh_ps(tmp0, tmp2); \
(row1) = _mm_movehl_ps(tmp2, tmp0); \
(row2) = _mm_movelh_ps(tmp1, tmp3); \
(row3) = _mm_movehl_ps(tmp3, tmp1); \
} while (0)

/* Aliases for compatibility. */
#define _m_pextrw _mm_extract_pi16
#define _m_pinsrw _mm_insert_pi16
#define _m_pmaxsw _mm_max_pi16
#define _m_pmaxub _mm_max_pu8
#define _m_pminsw _mm_min_pi16
#define _m_pminub _mm_min_pu8
#define _m_pmovmskb _mm_movemask_pi8
#define _m_pmulhuw _mm_mulhi_pu16
#define _m_pshufw _mm_shuffle_pi16
#define _m_maskmovq _mm_maskmove_si64
#define _m_pavgb _mm_avg_pu8
#define _m_pavgw _mm_avg_pu16
#define _m_psadbw _mm_sad_pu8
#define _m_ _mm_
#define _m_ _mm_

/* Ugly hack for backwards-compatibility (compatible with gcc) */
#ifdef __SSE2__
#include "emmintrin.h"
#endif

#endif /* __SSE__ */

#endif /* __XMMINTRIN_H */

#else /* !__clang__ */

#ifndef __SSE__
# error "SSE instruction set not enabled"
#else

/* We need type definitions from the MMX header file.  */
#include "mmintrin.h"

/* Get _mm_malloc () and _mm_free ().  */
/* APPLE LOCAL begin xmmintrin.h for kernel 4123064 */
#if __STDC_HOSTED__
#include <mm_malloc.h>
#endif
/* APPLE LOCAL end xmmintrin.h for kernel 4123064 */

/* The Intel API is flexible enough that we must allow aliasing with other
   vector types, and their scalar components.  */
typedef float __m128 __attribute__ ((__vector_size__ (16), __may_alias__));

/* Internal data types for implementing the intrinsics.  */
typedef float __v4sf __attribute__ ((__vector_size__ (16)));

/* Create a selector for use with the SHUFPS instruction.  */
#define _MM_SHUFFLE(fp3,fp2,fp1,fp0) \
 (((fp3) << 6) | ((fp2) << 4) | ((fp1) << 2) | (fp0))

/* Constants for use with _mm_prefetch.  */
enum _mm_hint
{
  _MM_HINT_T0 = 3,
  _MM_HINT_T1 = 2,
  _MM_HINT_T2 = 1,
  _MM_HINT_NTA = 0
};

/* Bits in the MXCSR.  */
#define _MM_EXCEPT_MASK       0x003f
#define _MM_EXCEPT_INVALID    0x0001
#define _MM_EXCEPT_DENORM     0x0002
#define _MM_EXCEPT_DIV_ZERO   0x0004
#define _MM_EXCEPT_OVERFLOW   0x0008
#define _MM_EXCEPT_UNDERFLOW  0x0010
#define _MM_EXCEPT_INEXACT    0x0020

#define _MM_MASK_MASK         0x1f80
#define _MM_MASK_INVALID      0x0080
#define _MM_MASK_DENORM       0x0100
#define _MM_MASK_DIV_ZERO     0x0200
#define _MM_MASK_OVERFLOW     0x0400
#define _MM_MASK_UNDERFLOW    0x0800
#define _MM_MASK_INEXACT      0x1000

#define _MM_ROUND_MASK        0x6000
#define _MM_ROUND_NEAREST     0x0000
#define _MM_ROUND_DOWN        0x2000
#define _MM_ROUND_UP          0x4000
#define _MM_ROUND_TOWARD_ZERO 0x6000

#define _MM_FLUSH_ZERO_MASK   0x8000
#define _MM_FLUSH_ZERO_ON     0x8000
#define _MM_FLUSH_ZERO_OFF    0x0000

/* APPLE LOCAL begin nodebug inline 4152603 */
#define __always_inline__ __always_inline__, __nodebug__
/* APPLE LOCAL end nodebug inline 4152603 */

/* APPLE LOCAL begin radar 5618945 */
#undef __STATIC_INLINE
#ifdef __GNUC_STDC_INLINE__
#define __STATIC_INLINE __inline
#else
#define __STATIC_INLINE static __inline
#endif
/* APPLE LOCAL end radar 5618945 */

/* Create a vector of zeros.  */
/* APPLE LOCAL begin radar 4152603 */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setzero_ps (void)
{
  return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
}

/* Perform the respective operation on the lower SPFP (single-precision
   floating-point) values of A and B; the upper three SPFP values are
   passed through from A.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_addss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_subss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_mul_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_mulss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_div_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_divss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sqrt_ss (__m128 __A)
{
  return (__m128) __builtin_ia32_sqrtss ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_rcp_ss (__m128 __A)
{
  return (__m128) __builtin_ia32_rcpss ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_rsqrt_ss (__m128 __A)
{
  return (__m128) __builtin_ia32_rsqrtss ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_min_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_minss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_max_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_maxss ((__v4sf)__A, (__v4sf)__B);
}

/* Perform the respective operation on the four SPFP values in A and B.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_add_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_addps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sub_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_subps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_mul_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_mulps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_div_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_divps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sqrt_ps (__m128 __A)
{
  return (__m128) __builtin_ia32_sqrtps ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_rcp_ps (__m128 __A)
{
  return (__m128) __builtin_ia32_rcpps ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_rsqrt_ps (__m128 __A)
{
  return (__m128) __builtin_ia32_rsqrtps ((__v4sf)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_min_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_minps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_max_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_maxps ((__v4sf)__A, (__v4sf)__B);
}

/* Perform logical bit-wise operations on 128-bit values.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_and_ps (__m128 __A, __m128 __B)
{
  return __builtin_ia32_andps (__A, __B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_andnot_ps (__m128 __A, __m128 __B)
{
  return __builtin_ia32_andnps (__A, __B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_or_ps (__m128 __A, __m128 __B)
{
  return __builtin_ia32_orps (__A, __B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_xor_ps (__m128 __A, __m128 __B)
{
  return __builtin_ia32_xorps (__A, __B);
}

/* Perform a comparison on the lower SPFP values of A and B.  If the
   comparison is true, place a mask of all ones in the result, otherwise a
   mask of zeros.  The upper three SPFP values are passed through from A.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpeq_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpeqss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmplt_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpltss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmple_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpless ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpgt_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movss ((__v4sf) __A,
					(__v4sf)
					__builtin_ia32_cmpltss ((__v4sf) __B,
								(__v4sf)
								__A));
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpge_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movss ((__v4sf) __A,
					(__v4sf)
					__builtin_ia32_cmpless ((__v4sf) __B,
								(__v4sf)
								__A));
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpneq_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpneqss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnlt_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpnltss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnle_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpnless ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpngt_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movss ((__v4sf) __A,
					(__v4sf)
					__builtin_ia32_cmpnltss ((__v4sf) __B,
								 (__v4sf)
								 __A));
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnge_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movss ((__v4sf) __A,
					(__v4sf)
					__builtin_ia32_cmpnless ((__v4sf) __B,
								 (__v4sf)
								 __A));
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpord_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpordss ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpunord_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpunordss ((__v4sf)__A, (__v4sf)__B);
}

/* Perform a comparison on the four SPFP values of A and B.  For each
   element, if the comparison is true, place a mask of all ones in the
   result, otherwise a mask of zeros.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpeq_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpeqps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmplt_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpltps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmple_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpleps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpgt_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpgtps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpge_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpgeps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpneq_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpneqps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnlt_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpnltps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnle_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpnleps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpngt_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpngtps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpnge_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpngeps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpord_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpordps ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cmpunord_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_cmpunordps ((__v4sf)__A, (__v4sf)__B);
}

/* Compare the lower SPFP values of A and B and return 1 if true
   and 0 if false.  */

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comieq_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comieq ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comilt_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comilt ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comile_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comile ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comigt_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comigt ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comige_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comige ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_comineq_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_comineq ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomieq_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomieq ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomilt_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomilt ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomile_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomile ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomigt_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomigt ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomige_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomige ((__v4sf)__A, (__v4sf)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_ucomineq_ss (__m128 __A, __m128 __B)
{
  return __builtin_ia32_ucomineq ((__v4sf)__A, (__v4sf)__B);
}

/* Convert the lower SPFP value to a 32-bit integer according to the current
   rounding mode.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtss_si32 (__m128 __A)
{
  return __builtin_ia32_cvtss2si ((__v4sf) __A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvt_ss2si (__m128 __A)
{
  return _mm_cvtss_si32 (__A);
}

#ifdef __x86_64__
/* Convert the lower SPFP value to a 32-bit integer according to the
   current rounding mode.  */

/* Intel intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtss_si64 (__m128 __A)
{
  return __builtin_ia32_cvtss2si64 ((__v4sf) __A);
}

/* Microsoft intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtss_si64x (__m128 __A)
{
  return __builtin_ia32_cvtss2si64 ((__v4sf) __A);
}
#endif

/* Convert the two lower SPFP values to 32-bit integers according to the
   current rounding mode.  Return the integers in packed form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtps_pi32 (__m128 __A)
{
  return (__m64) __builtin_ia32_cvtps2pi ((__v4sf) __A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvt_ps2pi (__m128 __A)
{
  return _mm_cvtps_pi32 (__A);
}

/* Truncate the lower SPFP value to a 32-bit integer.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvttss_si32 (__m128 __A)
{
  return __builtin_ia32_cvttss2si ((__v4sf) __A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtt_ss2si (__m128 __A)
{
  return _mm_cvttss_si32 (__A);
}

#ifdef __x86_64__
/* Truncate the lower SPFP value to a 32-bit integer.  */

/* Intel intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvttss_si64 (__m128 __A)
{
  return __builtin_ia32_cvttss2si64 ((__v4sf) __A);
}

/* Microsoft intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE long long __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvttss_si64x (__m128 __A)
{
  return __builtin_ia32_cvttss2si64 ((__v4sf) __A);
}
#endif

/* Truncate the two lower SPFP values to 32-bit integers.  Return the
   integers in packed form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvttps_pi32 (__m128 __A)
{
  return (__m64) __builtin_ia32_cvttps2pi ((__v4sf) __A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtt_ps2pi (__m128 __A)
{
  return _mm_cvttps_pi32 (__A);
}

/* Convert B to a SPFP value and insert it as element zero in A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi32_ss (__m128 __A, int __B)
{
  return (__m128) __builtin_ia32_cvtsi2ss ((__v4sf) __A, __B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvt_si2ss (__m128 __A, int __B)
{
  return _mm_cvtsi32_ss (__A, __B);
}

#ifdef __x86_64__
/* Convert B to a SPFP value and insert it as element zero in A.  */

/* Intel intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64_ss (__m128 __A, long long __B)
{
  return (__m128) __builtin_ia32_cvtsi642ss ((__v4sf) __A, __B);
}

/* Microsoft intrinsic.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtsi64x_ss (__m128 __A, long long __B)
{
  return (__m128) __builtin_ia32_cvtsi642ss ((__v4sf) __A, __B);
}
#endif

/* Convert the two 32-bit values in B to SPFP form and insert them
   as the two lower elements in A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpi32_ps (__m128 __A, __m64 __B)
{
  return (__m128) __builtin_ia32_cvtpi2ps ((__v4sf) __A, (__v2si)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvt_pi2ps (__m128 __A, __m64 __B)
{
  return _mm_cvtpi32_ps (__A, __B);
}

/* Convert the four signed 16-bit values in A to SPFP form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpi16_ps (__m64 __A)
{
  __v4hi __sign;
  __v2si __hisi, __losi;
  __v4sf __r;

  /* This comparison against zero gives us a mask that can be used to
     fill in the missing sign bits in the unpack operations below, so
     that we get signed values after unpacking.  */
  __sign = __builtin_ia32_pcmpgtw ((__v4hi)0LL, (__v4hi)__A);

  /* Convert the four words to doublewords.  */
  __hisi = (__v2si) __builtin_ia32_punpckhwd ((__v4hi)__A, __sign);
  __losi = (__v2si) __builtin_ia32_punpcklwd ((__v4hi)__A, __sign);

  /* Convert the doublewords to floating point two at a time.  */
  __r = (__v4sf) _mm_setzero_ps ();
  __r = __builtin_ia32_cvtpi2ps (__r, __hisi);
  __r = __builtin_ia32_movlhps (__r, __r);
  __r = __builtin_ia32_cvtpi2ps (__r, __losi);

  return (__m128) __r;
}

/* Convert the four unsigned 16-bit values in A to SPFP form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpu16_ps (__m64 __A)
{
  __v2si __hisi, __losi;
  __v4sf __r;

  /* Convert the four words to doublewords.  */
  __hisi = (__v2si) __builtin_ia32_punpckhwd ((__v4hi)__A, (__v4hi)0LL);
  __losi = (__v2si) __builtin_ia32_punpcklwd ((__v4hi)__A, (__v4hi)0LL);

  /* Convert the doublewords to floating point two at a time.  */
  __r = (__v4sf) _mm_setzero_ps ();
  __r = __builtin_ia32_cvtpi2ps (__r, __hisi);
  __r = __builtin_ia32_movlhps (__r, __r);
  __r = __builtin_ia32_cvtpi2ps (__r, __losi);

  return (__m128) __r;
}

/* Convert the low four signed 8-bit values in A to SPFP form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpi8_ps (__m64 __A)
{
  __v8qi __sign;

  /* This comparison against zero gives us a mask that can be used to
     fill in the missing sign bits in the unpack operations below, so
     that we get signed values after unpacking.  */
  __sign = __builtin_ia32_pcmpgtb ((__v8qi)0LL, (__v8qi)__A);

  /* Convert the four low bytes to words.  */
  __A = (__m64) __builtin_ia32_punpcklbw ((__v8qi)__A, __sign);

  return _mm_cvtpi16_ps(__A);
}

/* Convert the low four unsigned 8-bit values in A to SPFP form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpu8_ps(__m64 __A)
{
  __A = (__m64) __builtin_ia32_punpcklbw ((__v8qi)__A, (__v8qi)0LL);
  return _mm_cvtpu16_ps(__A);
}

/* Convert the four signed 32-bit values in A and B to SPFP form.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtpi32x2_ps(__m64 __A, __m64 __B)
{
  __v4sf __zero = (__v4sf) _mm_setzero_ps ();
  __v4sf __sfa = __builtin_ia32_cvtpi2ps (__zero, (__v2si)__A);
  __v4sf __sfb = __builtin_ia32_cvtpi2ps (__zero, (__v2si)__B);
  return (__m128) __builtin_ia32_movlhps (__sfa, __sfb);
}

/* Convert the four SPFP values in A to four signed 16-bit integers.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtps_pi16(__m128 __A)
{
  __v4sf __hisf = (__v4sf)__A;
  __v4sf __losf = __builtin_ia32_movhlps (__hisf, __hisf);
  __v2si __hisi = __builtin_ia32_cvtps2pi (__hisf);
  __v2si __losi = __builtin_ia32_cvtps2pi (__losf);
  return (__m64) __builtin_ia32_packssdw (__hisi, __losi);
}

/* Convert the four SPFP values in A to four signed 8-bit integers.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtps_pi8(__m128 __A)
{
  __v4hi __tmp = (__v4hi) _mm_cvtps_pi16 (__A);
  return (__m64) __builtin_ia32_packsswb (__tmp, (__v4hi)0LL);
}

/* Selects four specific SPFP values from A and B based on MASK.  */
#if 0
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_shuffle_ps (__m128 __A, __m128 __B, int __mask)
{
  return (__m128) __builtin_ia32_shufps ((__v4sf)__A, (__v4sf)__B, __mask);
}
#else
#define _mm_shuffle_ps(A, B, MASK) \
 ((__m128) __builtin_ia32_shufps ((__v4sf)(A), (__v4sf)(B), (MASK)))
#endif


/* Selects and interleaves the upper two SPFP values from A and B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpackhi_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_unpckhps ((__v4sf)__A, (__v4sf)__B);
}

/* Selects and interleaves the lower two SPFP values from A and B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_unpacklo_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_unpcklps ((__v4sf)__A, (__v4sf)__B);
}

/* Sets the upper two SPFP values with 64-bits of data loaded from P;
   the lower two values are passed through from A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_loadh_pi (__m128 __A, __m64 const *__P)
{
  return (__m128) __builtin_ia32_loadhps ((__v4sf)__A, (__v2si *)__P);
}

/* Stores the upper two SPFP values of A into P.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_storeh_pi (__m64 *__P, __m128 __A)
{
  __builtin_ia32_storehps ((__v2si *)__P, (__v4sf)__A);
}

/* Moves the upper two values of B into the lower two values of A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_movehl_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movhlps ((__v4sf)__A, (__v4sf)__B);
}

/* Moves the lower two values of B into the upper two values of A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_movelh_ps (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movlhps ((__v4sf)__A, (__v4sf)__B);
}

/* Sets the lower two SPFP values with 64-bits of data loaded from P;
   the upper two values are passed through from A.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_loadl_pi (__m128 __A, __m64 const *__P)
{
  return (__m128) __builtin_ia32_loadlps ((__v4sf)__A, (__v2si *)__P);
}

/* Stores the lower two SPFP values of A into P.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_storel_pi (__m64 *__P, __m128 __A)
{
  __builtin_ia32_storelps ((__v2si *)__P, (__v4sf)__A);
}

/* Creates a 4-bit mask from the most significant bits of the SPFP values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_movemask_ps (__m128 __A)
{
  return __builtin_ia32_movmskps ((__v4sf)__A);
}

/* Return the contents of the control register.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE unsigned int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_getcsr (void)
{
  return __builtin_ia32_stmxcsr ();
}

/* Read exception bits from the control register.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE unsigned int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_GET_EXCEPTION_STATE (void)
{
  return _mm_getcsr() & _MM_EXCEPT_MASK;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE unsigned int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_GET_EXCEPTION_MASK (void)
{
  return _mm_getcsr() & _MM_MASK_MASK;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE unsigned int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_GET_ROUNDING_MODE (void)
{
  return _mm_getcsr() & _MM_ROUND_MASK;
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE unsigned int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_GET_FLUSH_ZERO_MODE (void)
{
  return _mm_getcsr() & _MM_FLUSH_ZERO_MASK;
}

/* Set the control register to I.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setcsr (unsigned int __I)
{
  __builtin_ia32_ldmxcsr (__I);
}

/* Set exception bits in the control register.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_SET_EXCEPTION_STATE(unsigned int __mask)
{
  _mm_setcsr((_mm_getcsr() & ~_MM_EXCEPT_MASK) | __mask);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_SET_EXCEPTION_MASK (unsigned int __mask)
{
  _mm_setcsr((_mm_getcsr() & ~_MM_MASK_MASK) | __mask);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_SET_ROUNDING_MODE (unsigned int __mode)
{
  _mm_setcsr((_mm_getcsr() & ~_MM_ROUND_MASK) | __mode);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_MM_SET_FLUSH_ZERO_MODE (unsigned int __mode)
{
  _mm_setcsr((_mm_getcsr() & ~_MM_FLUSH_ZERO_MASK) | __mode);
}

/* Create a vector with element 0 as F and the rest zero.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_ss (float __F)
{
  return __extension__ (__m128)(__v4sf){ __F, 0, 0, 0 };
}

/* Create a vector with all four elements equal to F.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set1_ps (float __F)
{
  return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_ps1 (float __F)
{
  return _mm_set1_ps (__F);
}

/* Create a vector with element 0 as *P and the rest zero.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_load_ss (float const *__P)
{
  return _mm_set_ss (*__P);
}

/* Create a vector with all four elements equal to *P.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_load1_ps (float const *__P)
{
  return _mm_set1_ps (*__P);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_load_ps1 (float const *__P)
{
  return _mm_load1_ps (__P);
}

/* Load four SPFP values from P.  The address must be 16-byte aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_load_ps (float const *__P)
{
  return (__m128) *(__v4sf *)__P;
}

/* Load four SPFP values from P.  The address need not be 16-byte aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_loadu_ps (float const *__P)
{
  return (__m128) __builtin_ia32_loadups (__P);
}

/* Load four SPFP values in reverse order.  The address must be aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_loadr_ps (float const *__P)
{
  __v4sf __tmp = *(__v4sf *)__P;
  return (__m128) __builtin_ia32_shufps (__tmp, __tmp, _MM_SHUFFLE (0,1,2,3));
}

/* Create the vector [Z Y X W].  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_set_ps (const float __Z, const float __Y, const float __X, const float __W)
{
  return __extension__ (__m128)(__v4sf){ __W, __X, __Y, __Z };
}

/* Create the vector [W X Y Z].  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_setr_ps (float __Z, float __Y, float __X, float __W)
{
  return __extension__ (__m128)(__v4sf){ __Z, __Y, __X, __W };
}

/* Stores the lower SPFP value.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_store_ss (float *__P, __m128 __A)
{
  *__P = __builtin_ia32_vec_ext_v4sf ((__v4sf)__A, 0);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE float __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_cvtss_f32 (__m128 __A)
{
  return __builtin_ia32_vec_ext_v4sf ((__v4sf)__A, 0);
}

/* Store four SPFP values.  The address must be 16-byte aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_store_ps (float *__P, __m128 __A)
{
  *(__v4sf *)__P = (__v4sf)__A;
}

/* Store four SPFP values.  The address need not be 16-byte aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_storeu_ps (float *__P, __m128 __A)
{
  __builtin_ia32_storeups (__P, (__v4sf)__A);
}

/* Store the lower SPFP value across four words.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_store1_ps (float *__P, __m128 __A)
{
  __v4sf __va = (__v4sf)__A;
  __v4sf __tmp = __builtin_ia32_shufps (__va, __va, _MM_SHUFFLE (0,0,0,0));
  _mm_storeu_ps (__P, __tmp);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_store_ps1 (float *__P, __m128 __A)
{
  _mm_store1_ps (__P, __A);
}

/* Store four SPFP values in reverse order.  The address must be aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_storer_ps (float *__P, __m128 __A)
{
  __v4sf __va = (__v4sf)__A;
  __v4sf __tmp = __builtin_ia32_shufps (__va, __va, _MM_SHUFFLE (0,1,2,3));
  _mm_store_ps (__P, __tmp);
}

/* Sets the low SPFP value of A from the low value of B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m128 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_move_ss (__m128 __A, __m128 __B)
{
  return (__m128) __builtin_ia32_movss ((__v4sf)__A, (__v4sf)__B);
}

/* Extracts one of the four words of A.  The selector N must be immediate.  */
#if 0
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_extract_pi16 (__m64 const __A, int const __N)
{
  return __builtin_ia32_vec_ext_v4hi ((__v4hi)__A, __N);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pextrw (__m64 const __A, int const __N)
{
  return _mm_extract_pi16 (__A, __N);
}
#else
#define _mm_extract_pi16(A, N)	__builtin_ia32_vec_ext_v4hi ((__v4hi)(A), (N))
#define _m_pextrw(A, N)		_mm_extract_pi16((A), (N))
#endif

/* Inserts word D into one of four words of A.  The selector N must be
   immediate.  */
#if 0
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_insert_pi16 (__m64 const __A, int const __D, int const __N)
{
  return (__m64) __builtin_ia32_vec_set_v4hi ((__v4hi)__A, __D, __N);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pinsrw (__m64 const __A, int const __D, int const __N)
{
  return _mm_insert_pi16 (__A, __D, __N);
}
#else
#define _mm_insert_pi16(A, D, N) \
  ((__m64) __builtin_ia32_vec_set_v4hi ((__v4hi)(A), (D), (N)))
#define _m_pinsrw(A, D, N)	 _mm_insert_pi16((A), (D), (N))
#endif

/* Compute the element-wise maximum of signed 16-bit values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_max_pi16 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pmaxsw ((__v4hi)__A, (__v4hi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmaxsw (__m64 __A, __m64 __B)
{
  return _mm_max_pi16 (__A, __B);
}

/* Compute the element-wise maximum of unsigned 8-bit values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_max_pu8 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pmaxub ((__v8qi)__A, (__v8qi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmaxub (__m64 __A, __m64 __B)
{
  return _mm_max_pu8 (__A, __B);
}

/* Compute the element-wise minimum of signed 16-bit values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_min_pi16 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pminsw ((__v4hi)__A, (__v4hi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pminsw (__m64 __A, __m64 __B)
{
  return _mm_min_pi16 (__A, __B);
}

/* Compute the element-wise minimum of unsigned 8-bit values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_min_pu8 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pminub ((__v8qi)__A, (__v8qi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pminub (__m64 __A, __m64 __B)
{
  return _mm_min_pu8 (__A, __B);
}

/* Create an 8-bit mask of the signs of 8-bit values.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_movemask_pi8 (__m64 __A)
{
  return __builtin_ia32_pmovmskb ((__v8qi)__A);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE int __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmovmskb (__m64 __A)
{
  return _mm_movemask_pi8 (__A);
}

/* Multiply four unsigned 16-bit values in A by four unsigned 16-bit values
   in B and produce the high 16 bits of the 32-bit results.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_mulhi_pu16 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pmulhuw ((__v4hi)__A, (__v4hi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pmulhuw (__m64 __A, __m64 __B)
{
  return _mm_mulhi_pu16 (__A, __B);
}

/* Return a combination of the four 16-bit values in A.  The selector
   must be an immediate.  */
#if 0
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_shuffle_pi16 (__m64 __A, int __N)
{
  return (__m64) __builtin_ia32_pshufw ((__v4hi)__A, __N);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pshufw (__m64 __A, int __N)
{
  return _mm_shuffle_pi16 (__A, __N);
}
#else
#define _mm_shuffle_pi16(A, N) \
  ((__m64) __builtin_ia32_pshufw ((__v4hi)(A), (N)))
#define _m_pshufw(A, N)		_mm_shuffle_pi16 ((A), (N))
#endif

/* Conditionally store byte elements of A into P.  The high bit of each
   byte in the selector N determines whether the corresponding byte from
   A is stored.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_maskmove_si64 (__m64 __A, __m64 __N, char *__P)
{
  __builtin_ia32_maskmovq ((__v8qi)__A, (__v8qi)__N, __P);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_maskmovq (__m64 __A, __m64 __N, char *__P)
{
  _mm_maskmove_si64 (__A, __N, __P);
}

/* Compute the rounded averages of the unsigned 8-bit values in A and B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_avg_pu8 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pavgb ((__v8qi)__A, (__v8qi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pavgb (__m64 __A, __m64 __B)
{
  return _mm_avg_pu8 (__A, __B);
}

/* Compute the rounded averages of the unsigned 16-bit values in A and B.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_avg_pu16 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_pavgw ((__v4hi)__A, (__v4hi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_pavgw (__m64 __A, __m64 __B)
{
  return _mm_avg_pu16 (__A, __B);
}

/* Compute the sum of the absolute differences of the unsigned 8-bit
   values in A and B.  Return the value in the lower 16-bit word; the
   upper words are cleared.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sad_pu8 (__m64 __A, __m64 __B)
{
  return (__m64) __builtin_ia32_psadbw ((__v8qi)__A, (__v8qi)__B);
}

/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE __m64 __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_m_psadbw (__m64 __A, __m64 __B)
{
  return _mm_sad_pu8 (__A, __B);
}

/* Loads one cache line from address P to a location "closer" to the
   processor.  The selector I specifies the type of prefetch operation.  */
#if 0
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_prefetch (void *__P, enum _mm_hint __I)
{
  __builtin_prefetch (__P, 0, __I);
}
#else
#define _mm_prefetch(P, I) \
  __builtin_prefetch ((P), 0, (I))
#endif

/* Stores the data in A to the address P without polluting the caches.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_stream_pi (__m64 *__P, __m64 __A)
{
  /* APPLE LOCAL 4656532 use V1DImode for _m64 */
  __builtin_ia32_movntq (__P, __A);
}

/* Likewise.  The address must be 16-byte aligned.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_stream_ps (float *__P, __m128 __A)
{
  __builtin_ia32_movntps (__P, (__v4sf)__A);
}

/* Guarantees that every preceding store is globally visible before
   any subsequent store.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_sfence (void)
{
  __builtin_ia32_sfence ();
}

/* The execution of the next instruction is delayed by an implementation
   specific amount of time.  The instruction does not modify the
   architectural state.  */
/* APPLE LOCAL begin radar 5618945 */
__STATIC_INLINE void __attribute__((__always_inline__))
/* APPLE LOCAL end radar 5618945 */
_mm_pause (void)
{
  __asm__ __volatile__ ("rep; nop" : : );
}
/* APPLE LOCAL end radar 4152603 */

/* Transpose the 4x4 matrix composed of row[0-3].  */
#define _MM_TRANSPOSE4_PS(row0, row1, row2, row3)			\
do {									\
  __v4sf __r0 = (row0), __r1 = (row1), __r2 = (row2), __r3 = (row3);	\
  __v4sf __t0 = __builtin_ia32_unpcklps (__r0, __r1);			\
  __v4sf __t1 = __builtin_ia32_unpcklps (__r2, __r3);			\
  __v4sf __t2 = __builtin_ia32_unpckhps (__r0, __r1);			\
  __v4sf __t3 = __builtin_ia32_unpckhps (__r2, __r3);			\
  (row0) = __builtin_ia32_movlhps (__t0, __t1);				\
  (row1) = __builtin_ia32_movhlps (__t1, __t0);				\
  (row2) = __builtin_ia32_movlhps (__t2, __t3);				\
  (row3) = __builtin_ia32_movhlps (__t3, __t2);				\
} while (0)

/* APPLE LOCAL begin nodebug inline 4152603 */
#undef __always_inline__
/* APPLE LOCAL end nodebug inline 4152603 */

/* For backward source compatibility.  */
#include "emmintrin.h"

#endif /* __SSE__ */

#endif /* __clang__ */

#endif /* _XMMINTRIN_H_INCLUDED */
