/* Copyright (c) , Herve Rouault <rouaulth@janelia.hhmi.org>,
 * Howard Hughes Medical Institute.
 * All rights reserved.
 * 
 * This file is part of Brecs.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Howard Hughes Medical Institute nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <math.h>

#include "inoutimg.h"

#define OVERSAMP 10

void gaussker2d(double sigma, size_t shift, size_t sizepsf)
{
    size_t pixsize = shift * OVERSAMP;
    size_t pixsize2 = pixsize * pixsize;
    size_t nbpixhighres = sizepsf * pixsize;
    size_t sizeimg = nbpixhighres + 2 * pixsize;
    double * psfhighres = malloc(sizeimg * sizeimg * sizeof(double));
    float * psfpic = malloc(sizeimg * sizeimg * sizeof(float));

    /* Calculation of the psf value */
    for (int y = 0; y < sizeimg; ++y) {
        double dy = y - (double)(nbpixhighres + pixsize) / 2 + 0.5;
        for (int x = 0; x < sizeimg; ++x) {
            double dx = x - (double)(nbpixhighres + pixsize) / 2 + 0.5;
            double r2 = dx * dx + dy * dy;
            double sigma2res = sigma * OVERSAMP * shift;
            sigma2res *= sigma2res;
            double val = exp(-r2 / 2 / sigma2res) / (2 * M_PI * sigma2res);
            psfhighres[y * nbpixhighres + x] = val;
            psfpic[y * nbpixhighres + x] = val;
        }
    }
    double sum = 0;
    for (size_t i = 0; i < sizeimg * sizeimg; ++i) {
        sum += psfhighres[i];
    }
    printf("%f\n", sum);
    float * psfpicshift = malloc(shift * shift * sizepsf * sizepsf
                                 * sizeof(float));
    double * psfshift = malloc(shift * shift * sizepsf * sizepsf
                                 * sizeof(double));
    for (size_t i = 0; i < shift * shift; ++i) {
        for (size_t j = 0; j < sizepsf * sizepsf; ++j) {
            double val = 0;
            for (size_t k = 0; k < pixsize * pixsize; ++k) {
                size_t xres = k % pixsize + pixsize
                              + j % sizepsf * pixsize
                              - i % shift * OVERSAMP
                              - (shift + 1) % 2 * OVERSAMP / 2;
                size_t yres = k / pixsize + pixsize
                              + j / sizepsf * pixsize
                              - i / shift * OVERSAMP
                              - (shift + 1) % 2 * OVERSAMP / 2;
                val += psfhighres[yres * nbpixhighres + xres];
            }
            psfshift[j + i * sizepsf * sizepsf] = val;
            psfpicshift[j + i * sizepsf * sizepsf] = val;
        }
    }
    writetiff_f("psf2d.tif", nbpixhighres, nbpixhighres, 1, psfpic);
    writetiff_f("psf2d-shift.tif",
                sizepsf, sizepsf, shift * shift, psfpicshift);
}



int main(int argc, char const *argv[])
{
    gaussker2d(1.05, 8, 16);

    return 0;
}
