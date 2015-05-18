// posix_memalign((void **)&res, alignsize, size3 * sizeof(float));

#include <stdlib.h> // for size_t, 
#include "afloat.h" // for alignsize

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
