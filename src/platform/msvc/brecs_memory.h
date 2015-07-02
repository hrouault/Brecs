#pragma once

#ifdef __clpusplus
extern "C" {
#endif

void *brecs_alloc(size_t size);                /* returns memory aligned to alignsize (see afloat.h). free with brecs_free */
int brecs_memalign(void **memptr,size_t size); /* returns errno on failure, or 0 on succesfull allocation of memory aligned to alignsize (see afloat.h). free memory with brecs_free */
void brecs_free(void *memptr);

#ifdef __clpusplus
}
#endif
