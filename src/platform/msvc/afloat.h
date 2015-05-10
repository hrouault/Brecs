#pragma once

#ifdef __clpusplus
extern "C" {
#endif

#include <xmmintrin.h>

#ifdef __AVX__
#  pragma message("   AVX:  Using 32-byte aligned floats")
#  define shift (8)
#  define alignsize (32)
#  define VFUNC(name) _mm256_ ## name
typedef __m256 vecfloat;
typedef __declspec (align(32)) float afloat;
#else
#  pragma message("No AVX Defined:  Using 16-byte aligned floats")
#  define shift (4)
#  define alignsize (16)
#  define VFUNC(name) _mm_ ## name
typedef __m128 vecfloat;
typedef __declspec (align(16)) float afloat;
#endif

#ifdef __clpusplus
}
#endif