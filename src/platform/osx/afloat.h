#pragma once


#ifdef __AVX__
static int const shift = 8;
static int const alignsize = 32;
#  define VFUNC(name) _mm256_ ## name
typedef __m256 vecfloat;
typedef float afloat __attribute__ ((__aligned__(32)));
#else
static int const shift = 4;
static int const alignsize = 16;
#  define VFUNC(name) _mm_ ## name
typedef __m128 vecfloat;
typedef float afloat __attribute__ ((__aligned__(16)));
#endif