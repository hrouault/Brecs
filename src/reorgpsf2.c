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
#include <inttypes.h>
#include <string.h>
#include <tiffio.h>

#include "inoutimg.h"

#ifdef BRECS_KERSIZE
static int const kersize = BRECS_KERSIZE;
#else
static int const kersize = 16;
#endif

#ifdef BRECS_KERSIZEZ
static int const kersizez = BRECS_KERSIZEZ;
#else
static int const kersizez = 4;
#endif

#ifdef BRECS_PIXSDIV
static int const pixsdiv = BRECS_PIXSDIV;
#else
static int const pixsdiv = 4;
#endif

#ifdef BRECS_PIXSDIVZ
static int const pixsdivz = BRECS_PIXSDIVZ;
#else
static int const pixsdivz = 8;
#endif

static int const kersize2 = kersize * kersize;
static int const kersize3 = kersize * kersize * kersizez;

static int const pixsdiv2 = pixsdiv * pixsdiv;
static int const pixsdiv3 = pixsdiv2 * pixsdivz;

char * prog_name;


int main(int argc, char ** argv)
{
    char * arg0 = argv[0];
    arg0 = strrchr(arg0, '/');
    if (arg0)
        prog_name = arg0 + 1;
    else
        prog_name = argv[0];

    /* Remove libtiff warnings */
    TIFFSetWarningHandler(NULL);


    int sx, sy, sz;
    float * inpsf = opentiff_f(argv[1], &sx, &sy, &sz);
    float * outpsf = malloc(kersize2 * sz * pixsdiv2 * sizeof(float));

    printf("starting reorg\n");

    for (size_t z = 0; z < sz; ++z) {
        for (unsigned int i = 0; i < pixsdiv2; ++i) {
            int l = i / pixsdiv;
            int c = i % pixsdiv;
            for (unsigned int j = 0; j < kersize2; ++j) {
                float sum = 0;
                for (unsigned int k = 0; k < pixsdiv2; ++k) {
                    int lk = k / pixsdiv;
                    int ck = k % pixsdiv;
                    int width = pixsdiv * (kersize + 1) - 1;
                    int indx = pixsdiv - 1 - c + ck + (j % kersize) * pixsdiv;
                    int indy = pixsdiv - 1 - l + lk + (j / kersize) * pixsdiv;
                    sum += inpsf[indx + indy * width + z * width * width];
                }
                outpsf[j + i * kersize2 + z * kersize2 * pixsdiv2] = sum;
            }
        }
    }

    writetiff_f("outreorg.tif", kersize, kersize, pixsdiv2 * sz, outpsf);

    return EXIT_SUCCESS;
}
