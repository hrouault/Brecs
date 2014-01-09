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

#include "inoutimg.h"

void gaussker()
{
    for (int z = -sizez / 2; z < sizez / 2 ; ++z) {
        for (int y = -sizey / 2; y < sizey / 2; ++y) {
            for (int x = -sizex / 2; x < sizex / 2 ; ++x) {
                float dx2 = x * x;
                float dy2 = y * y;
                float dz2 = z * z;

                float val = exp(-radius2 / 2 / (sigpsf * sigpsf))
                    / (2 * M_PI * sigpsf * sigpsf);
                int line = x;
                int col = y;
                if (x < 0) line += sizex;
                if (y < 0) col += sizey;

                ker[col + line * sizey] = val;
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    uint16_t * img;
    int sx, sy, sz;
    img = opentiff("psf9-15.tif", &sx, &sy, &sz);

    uint16_t * img2 = malloc(sx * sy * sz * sizeof(uint16_t));

    for (size_t k = 0; k < sz; ++k) {
        for (size_t j = 0; j < sy; ++j) {
            for (size_t i = 0; i < sx; ++i) {
                int x = (i + 8 * k + 25) % sx;
                img2[x + j * sx + k * sx * sy] = img[i + j * sx + k * sx * sy];
            }
        }
    }

    writetiff_gray("shiftedimg.tif", sx, sy, sz, img2);

    return 0;
}
