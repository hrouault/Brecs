// rand.h
#pragma once

#include <stdint.h>

double   drand48();

/* TO USE THESE: Uncomment here, and change definitions in rand.c to be non-static
double   erand48(uint64_t *state);
uint64_t eseed48(uint32_t seedval);
void     dseed48(uint32_t seedval);
*/
