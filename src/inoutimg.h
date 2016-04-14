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

#ifndef INOUTIMG_H_86QYO34Z
#define INOUTIMG_H_86QYO34Z

#include <stdint.h>
#include <stdlib.h>

/* (ngc) are these functions used? */
#if 0
void plot_image(int sx, int sy,
                float * img,
                const char * filen,
                int flags);

void plot_imagergb(int sx, int sy,
                   unsigned char * img,
                   const char * filen);

void saveimage(float * img, int size, const char * fname);
#endif

uint16_t* opentiff(const char* fname, size_t* sx, size_t* sy, size_t* sz);
float* opentiff_f(const char* fname, size_t* sx, size_t* sy, size_t* sz);
void writetiff_f(const char* fname,
                 unsigned int sx, unsigned int sy, unsigned int sz,
                 float* img);
void writetiff_gray(const char* fname,
                    unsigned int sx, unsigned int sy, unsigned int sz,
                    uint16_t* img);
void writetiff_rgb(const char* fname,
                   unsigned int sx, unsigned int sy, unsigned int sz,
                   uint8_t* img);

#endif /* end of include guard: INOUTIMG_H_86QYO34Z */
