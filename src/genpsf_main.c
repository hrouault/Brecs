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

#include "genpsf.h"
#include "inoutimg.h"

int main()
{
    printf("This executable generates a PSF: everything is hard-coded.\n");

    /* For 2d psf generation */
    float sigma = 1.2f; /* std of the gaussian psf, in pixel units */
    uint16_t sh = 8; /* degree of superres: division of an imaged pixel */
    uint16_t size = 8; /* width of the psf in unit of measured pixels */
    uint16_t oversamp = 4;

    printf("Generating 2d psf...\n");
    float* psf2d = gaussker2d(sigma, sh, size, oversamp);
    writetiff_f("psf2d.tif", size, size, sh * sh, psf2d);
    free(psf2d);

    printf("Generating 3d astigmatic psf...\n");
    uint16_t nbplz = 7;
    uint16_t sdiv = 4;
    float* psf3dast = astigmker3d(1.0f, 0.0625, 1.5f, sdiv, nbplz, size, oversamp);
    writetiff_f("psf3dastig.tif", size, size, sdiv * sdiv * nbplz, psf3dast);
    free(psf3dast);

    /* float alphasigz = 0.8f; */
    /* sh = 2; */
    /* uint16_t shz = 1; */
    /* uint16_t sizez = 6; */
    /* printf("Generating 3d psf...\n"); */
    /* float* psf3d = gaussker3dwf(sigma, alphasigz, sh, shz, size, sizez, 4); */
    /* printf("Writing tiff file for 3d psf...\n"); */
    /* writetiff_f("psf3d.tif", size, size * sizez, sh * sh * shz, psf3d); */
    /* free(psf3d); */
    
    return 0;
}
