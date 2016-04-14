#include <stdlib.h>

#include "afloat.h"
#include "brecs_memory.h"

int brecs_memalign(void **memptr,size_t size)
{ 
    return posix_memalign(memptr,alignsize,size);
}

void* brecs_alloc(size_t size)
{
    void *p;
    if(posix_memalign(&p,alignsize,size)==0)
        return p;
    return 0;
}

void brecs_free(void* p) {
    free(p);
}
