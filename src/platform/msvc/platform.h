#pragma once

/*
Disabled warnings
C4305: Loss of precision (usually a double to float)
C4996: Use of an "unsafe" string function from the C runtime library.
*/
#pragma warning(disable:4305)
#pragma warning(disable:4996)


#define _USE_MATH_DEFINES
#include "rand.h"
#include "afloat.h"
#include "brecs_memory.h"

#define inline __forceinline


/* Just ignore this on windows, since we're not using libtiff
*/
#define TIFFSetWarningHandler(...)