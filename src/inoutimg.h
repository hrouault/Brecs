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
#include <inttypes.h>

#include "brecs_export.h"

uint16_t* BRECS_EXPORT opentiff(const char* fname,
                                uint32_t* sx, uint32_t* sy, uint32_t* sz);
float* BRECS_EXPORT opentiff_f(const char* fname,
                               uint32_t* sx, uint32_t* sy, uint32_t* sz);
void BRECS_EXPORT writetiff_f(const char* fname,
                              uint32_t sx, uint32_t sy, uint32_t sz,
                              float* img);
void BRECS_EXPORT writetiff_gray(const char* fname,
                                 uint32_t sx, uint32_t sy, uint32_t sz,
                                 uint16_t* img);
void BRECS_EXPORT writetiff_rgb(const char* fname,
                                uint32_t sx, uint32_t sy, uint32_t sz,
                                uint8_t* img);

#endif /* end of include guard: INOUTIMG_H_86QYO34Z */
