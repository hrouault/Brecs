#include <stdint.h>

static uint64_t rand48_a = 0x5deece66dull;
static uint64_t rand48_c = 0xbull;
static uint64_t rand_state = 0x1234abcd330eull;

static double erand48(uint64_t *state)
{ uint64_t  temp;
  double *tempd = ((double *) (&temp));
  *state = ((*state) * rand48_a + rand48_c) & 0xffffffffffffull;
  temp = 0x3ff0000000000000ull | (*state << 4);
  return (*tempd - 1.0);
}


double drand48() {
    return erand48(&rand_state);
}

static uint64_t eseed48(uint32_t seedval) {
    return ((((uint64_t) seedval) << 16) | 0x330e);
}

static void dseed48(uint32_t seedval) {
    rand_state = eseed48(seedval);
}