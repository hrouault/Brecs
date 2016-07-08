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

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <platform.h>

#include "inoutimg.h"
#include "genpsf.h"

#define M_PIf ((float)M_PI)


float * gaussker2d(float sigma,
                   uint16_t sdiv, uint16_t sizepsf, uint16_t oversamp)
{
    uint32_t sizepsf2 = sizepsf * sizepsf;
    uint32_t sdiv2 = sdiv * sdiv;
    uint32_t pixsize = sdiv * oversamp;
    uint32_t sizeimg = (sizepsf + 2) * pixsize;
    uint32_t sizeimg2 = sizeimg * sizeimg;
    float * psfhighres = malloc(sizeimg * sizeimg * sizeof(float));

    /* Calculation of the psf value */
    for (uint32_t y = 0; y < sizeimg; ++y) {
        float dy = y - (sizeimg - 1) * 0.5f;
        for (uint32_t x = 0; x < sizeimg; ++x) {
            float dx = x - (sizeimg - 1) * 0.5f;
            float r2 = dx * dx + dy * dy;
            float sigma2res = sigma * pixsize;
            sigma2res *= sigma2res;
            float val = expf(-r2 / 2 / sigma2res) / (2 * M_PIf * sigma2res);
            psfhighres[y * sizeimg + x] = val;
        }
    }
    printf("high res image generated\n");
    writetiff_f("raw2dpsf.tif", sizeimg, sizeimg, 1, psfhighres);
    double sum = 0;
    for (uint32_t i = 0; i < sizeimg2; ++i) {
        sum += psfhighres[i];
    }
    printf("normalization achieved\n");
    float * psfpicsdiv = (float*)brecs_alloc(sdiv2 * sizepsf2 * sizeof(float));
    printf("memory allocated\n");
    uint32_t offset = 3 * pixsize / 2 - oversamp / 2;
    for (uint32_t i = 0; i < sdiv * sdiv; ++i) {
        uint32_t sx = i % sdiv * oversamp;
        uint32_t sy = i / sdiv * oversamp;
        for (uint32_t j = 0; j < sizepsf * sizepsf; ++j) {
            uint32_t xcoarse = j % sizepsf * pixsize;
            uint32_t ycoarse = j / sizepsf * pixsize;
            float val = 0;
            for (uint32_t k = 0; k < pixsize * pixsize; ++k) {
                uint32_t xres = k % pixsize + xcoarse - sx + offset;
                uint32_t yres = k / pixsize + ycoarse - sy + offset;
                val += psfhighres[yres * sizeimg + xres];
            }
            psfpicsdiv[j + i * sizepsf2] = val;
        }
    }
    printf("psf reorganised\n");
    free(psfhighres);
    return(psfpicsdiv);
}

float * gaussker3dwf(float sigmaxy, float alphasigz,
                     uint16_t sdiv, uint16_t sdivz,
                     uint16_t sizepsfxy, uint16_t sizepsfz,
                     uint16_t oversamp)
    /* the oversampling is used both for the xy axes and the z axis */
    /* sigmaz varies linearly with z with coef alphasigz */
{
    uint32_t sizepsf2 = sizepsfxy * sizepsfxy;
    uint32_t sizepsf3 = sizepsf2 * sizepsfz;
    uint32_t sdiv2 = sdiv * sdiv;
    uint32_t sdiv3 = sdiv2 * sdivz;
    uint32_t pixsize = sdiv * oversamp;
    uint32_t pixsizez = sdivz * oversamp;
    uint32_t sizeimg = (sizepsfxy + 2) * pixsize;
    uint32_t sizeimgz = (sizepsfz + 2) * pixsizez;
    uint32_t sizeimg2 = sizeimg * sizeimg;
    uint32_t sizeimg3 = sizeimg2 * sizeimgz;
    float * psfhighres = malloc(sizeimg3 * sizeof(float));
    float alphare = alphasigz / oversamp;

    /* Calculation of the psf value */
    for (uint32_t z = 0; z < sizeimgz; ++z) {
        float dz = z - (sizeimgz - 1) * 0.5f;
        for (uint32_t y = 0; y < sizeimg; ++y) {
            float dy = y - (sizeimg - 1) * 0.5f;
            for (uint32_t x = 0; x < sizeimg; ++x) {
                float dx = x - (sizeimg - 1) * 0.5f;
                float r2 = dx * dx + dy * dy;
                float sigma2res = sigmaxy * pixsize * (1.0f + alphare * fabsf(dz));
                sigma2res *= sigma2res;
                float val = expf(-r2 / 2 / sigma2res) / (2 * M_PIf * sigma2res);
                psfhighres[z * sizeimg2 + y * sizeimg + x] = val;
            }
        }
    }
    writetiff_f("raw3dpsf.tif", sizeimg, sizeimg, sizeimgz, psfhighres);

    float * psfpicsdiv = (float*)brecs_alloc(sdiv3 * sizepsf3 * sizeof(float));
    uint32_t offset = 3 * pixsize / 2 - oversamp / 2;
    uint32_t offsetz = 3 * pixsizez / 2 - oversamp / 2;
    for (uint32_t i = 0; i < sdiv3; ++i) {
        uint32_t sx = (i % sdiv2) % sdiv * oversamp;
        uint32_t sy = (i % sdiv2) / sdiv * oversamp;
        uint32_t sz = i / sdiv2 * oversamp;
        for (uint32_t jz = 0; jz < sizepsfz; ++jz) {
            uint32_t zcoarse = jz * pixsizez;
            uint32_t zresum = zcoarse - sz + offsetz;
            float sum = 0;
            for (uint32_t j = 0; j < sizeimg2 * pixsizez; ++j) {
                sum += psfhighres[zresum * sizeimg2 + j];
            }
            for (uint32_t j = 0; j < sizepsf2; ++j) {
                uint32_t xcoarse = j % sizepsfxy * pixsize;
                uint32_t ycoarse = j / sizepsfxy * pixsize;
                float val = 0;
                for (uint32_t l = 0; l < pixsizez; ++l) {
                    uint32_t zres = l + zcoarse - sz + offsetz;
                    for (uint32_t k = 0; k < pixsize * pixsize; ++k) {
                        uint32_t xres = k % pixsize + xcoarse - sx + offset;
                        uint32_t yres = k / pixsize + ycoarse - sy + offset;
                        val += psfhighres[zres * sizeimg2 + yres * sizeimg + xres];
                    }
                }
                psfpicsdiv[j + jz * sizepsf2 + i * sizepsf3] = val;
            }
        }
    }
    free(psfhighres);
    return(psfpicsdiv);
}
