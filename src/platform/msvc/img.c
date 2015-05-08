#include <stdint.h>
#include <stdlib.h>



void plot_image(int sx, int sy,
                float * img,
                const char * filen,
                int flags)
{
exit(-1);
}

void plot_imagergb(int sx, int sy,
                   uint8_t * img,
                   const char * filen)
{
exit(-1);
}

void saveimage(float * img, int size, const char * fname)
{
exit(-1);
}

uint16_t * opentiff(const char * fname, int * sx, int * sy, int * sz)
{
exit(-1);
}

float * opentiff_f(const char * fname, int * sx, int * sy, int * sz)
{
exit(-1);
}

void writetiff_f(const char * fname, int sx, int sy, int sz, float * img)
{
exit(-1);
}

void writetiff_gray(const char * fname, int sx, int sy, int sz, uint16_t * img)
{
exit(-1);
}

void writetiff_rgb(const char * fname, int sx, int sy, int sz, uint8_t * img)
{
exit(-1);
}
