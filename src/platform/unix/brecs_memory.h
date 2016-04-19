#pragma once

#ifdef __clpusplus
extern "C" {
#endif
#include <stdlib.h>

void *brecs_alloc(size_t size);

/* returns memory aligned to alignsize (see afloat.h). free with brecs_free */
int brecs_memalign(void **memptr,size_t size);

void brecs_free(void *memptr);

#ifdef __clpusplus
}
#endif
