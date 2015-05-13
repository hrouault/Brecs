// posix_memalign((void **)&res, alignsize, size3 * sizeof(float));

#include <stdlib.h> // for size_t
#include <malloc.h>
#include "afloat.h" // for alignsize

int brecs_memalign(void **memptr,size_t size)
{ 
    *memptr=_aligned_malloc(size,alignsize);    
    return errno;
}

void *brecs_alloc(size_t size)
{
    return _aligned_malloc(size,alignsize);
}

void brecs_free(void* p) {
    if(!p) return;
    _aligned_free(p);
}