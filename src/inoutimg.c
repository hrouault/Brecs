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
#include <tiffio.h>
#include <png.h>
#include <bzlib.h>



void plot_image(int sx, int sy,
                float * img,
                const char * filen,
                int flags)
{
    FILE * fp = fopen(filen, "wb");
    if (!fp) exit(EXIT_FAILURE);

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
                                                  NULL, NULL, NULL);
    if (!png_ptr) exit(EXIT_FAILURE);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        exit(EXIT_FAILURE);
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, sy, sx,
                 8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    /*
     * At this point, we have to rewrite the image to convert it to ints
     * Then the image date array is passed to the info struct
     */
    int i, x;
    png_byte * img_data = malloc(sx * sy * sizeof(png_byte));
    float max = 0;
    float min = 0;
    for (i = 0 ; i < sx * sy ; i++) {
        if (max < img[i]) max = img[i];
        if (min > img[i]) min = img[i];
    }
    for (x = 0 ; x < sx * sy ; x++) {
        img_data[x] = 255 / (max - min) * (img[x] - min);
    }
    png_bytep row_pointers[sx];
    for (x = 0 ; x < sx ; x++) row_pointers[x] = img_data + x * sy;
    png_set_rows(png_ptr, info_ptr, row_pointers);

    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
    free(img_data);
}

void plot_imagergb(int sx, int sy,
                   png_byte * img,
                   const char * filen)
{
    FILE * fp = fopen(filen, "wb");
    if (!fp) exit(EXIT_FAILURE);

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
                                                  NULL, NULL, NULL);
    if (!png_ptr) exit(EXIT_FAILURE);
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
        exit(EXIT_FAILURE);
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    png_init_io(png_ptr, fp);

    png_set_IHDR(png_ptr, info_ptr, sy, sx,
                 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    png_bytep row_pointers[sx];
    for (size_t x = 0 ; x < sx ; x++) row_pointers[x] = img + 3 * x * sy;
    png_set_rows(png_ptr, info_ptr, row_pointers);

    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(fp);
}

void saveimage(float * img, int size, const char * fname)
{
    FILE * fout = fopen(fname, "wb");
    if (!fout) exit(EXIT_FAILURE);

    BZFILE* b;
    int nBuf = 256 * 1024;
    char buf[nBuf];
    int bzerror;
    int j = 0;

    b = BZ2_bzWriteOpen(&bzerror, fout, 9, 0, 30);
    if (bzerror != BZ_OK) {
        BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
        exit(EXIT_FAILURE);
    }
    int nbtot = 0;

    while (j < size) {
        /* get data to write into buf, and set nBuf appropriately */
        size_t i;
        for (i = 0; i < nBuf && j < size; i += 2) {
            *(uint16_t *)(buf + i) = (uint16_t)(img[j]);
            j++;
        }
        BZ2_bzWrite(&bzerror, b, buf, i);
        if (bzerror == BZ_IO_ERROR) {
            BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
            exit(EXIT_FAILURE);
        }
        nbtot += i;
    }

    BZ2_bzWriteClose(&bzerror, b, 0, NULL, NULL);
    if (bzerror == BZ_IO_ERROR) {
            exit(EXIT_FAILURE);
    }
}

uint16_t * opentiff(const char * fname, int * sx, int * sy, int * sz)
{
    TIFF * tif = TIFFOpen(fname, "r");
    uint16_t * img;
    if (tif) {
        uint32 imagelength;
        tsize_t scanline;
        tdata_t buf;
        uint32 row;
        uint32 col;

        TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
        *sy = imagelength;
        scanline = TIFFScanlineSize(tif);
        *sx = scanline / 2;
        int dircount = 0;
        do {
            dircount++;
        } while (TIFFReadDirectory(tif));
        TIFFSetDirectory(tif, 0);
        *sz = dircount;
        img = malloc(*sx * *sy * *sz * sizeof(uint16_t));
        buf = _TIFFmalloc(scanline);
        for (size_t z = 0; z < dircount; ++z) {
            for (row = 0; row < imagelength; row++) {
                TIFFReadScanline(tif, buf, row, 0);
                for (col = 0; col < scanline / 2; col++)
                    img[col + row * scanline / 2 + z * *sx * *sy]
                        = ((uint16 *)buf)[col];
            }
            TIFFReadDirectory(tif);
        }
        _TIFFfree(buf);
        TIFFClose(tif);
    } else {
        exit(EXIT_FAILURE);
    }

    return img;
}

float * opentiff_f(const char * fname, int * sx, int * sy, int * sz)
{
    TIFF * tif = TIFFOpen(fname, "r");
    float * img;
    if (!tif) exit(EXIT_FAILURE);

    uint32 imagelength;
    tsize_t scanline;
    tdata_t buf;
    uint32 row;
    uint32 col;

    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &imagelength);
    *sy = imagelength;
    scanline = TIFFScanlineSize(tif);
    *sx = scanline / 4;
    int dircount = 0;
    do {
        dircount++;
    } while (TIFFReadDirectory(tif));
    TIFFSetDirectory(tif, 0);
    *sz = dircount;
    posix_memalign((void **)&img, 32,
            *sx * *sy * *sz * sizeof(float));

    buf = _TIFFmalloc(scanline);
    for (size_t z = 0; z < dircount; ++z) {
        for (row = 0; row < imagelength; row++) {
            TIFFReadScanline(tif, buf, row, 0);
            for (col = 0; col < scanline / 4; col++)
                img[col + row * scanline / 4 + z * *sx * *sy]
                    = ((float *)buf)[col];
        }
        TIFFReadDirectory(tif);
    }
    _TIFFfree(buf);
    TIFFClose(tif);

    return img;
}

void writetiff_f(const char * fname, int sx, int sy, int sz, float * img)
{
    TIFF * outf = TIFFOpen(fname, "w");
    for (size_t i = 0; i < sz; ++i) {
        TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, sx);
        TIFFSetField(outf, TIFFTAG_IMAGELENGTH, sy);
        TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 1);
        TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 32);
        TIFFSetField(outf, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_IEEEFP);
        TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
        TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
        TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
        TIFFSetField(outf, TIFFTAG_COMPRESSION, COMPRESSION_LZW);

        TIFFSetField(outf,
                TIFFTAG_ROWSPERSTRIP,
                TIFFDefaultStripSize(outf, 4 * sx));

        for (uint32 row = 0; row < sy; row++) {
            if (TIFFWriteScanline(outf,
                                  img + sx * row + sx * sy * i,
                                  row, 0) < 0)
                break;
        }
        TIFFWriteDirectory(outf);
    }
    TIFFClose(outf);
}

void writetiff_gray(const char * fname, int sx, int sy, int sz, uint16_t * img)
{
    TIFF * outf = TIFFOpen(fname, "w");
    for (size_t i = 0; i < sz; ++i) {
        TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, sx);
        TIFFSetField(outf, TIFFTAG_IMAGELENGTH, sy);
        TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 1);
        TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 16);
        TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
        TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
        TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
        //TIFFSetField(outf, TIFFTAG_COMPRESSION, COMPRESSION_LZW);

        TIFFSetField(outf,
                TIFFTAG_ROWSPERSTRIP,
                TIFFDefaultStripSize(outf, 2 * sx));

        for (uint32 row = 0; row < sy; row++) {
            if (TIFFWriteScanline(outf,
                                  img + sx * row + sx * sy * i,
                                  row, 0) < 0)
                break;
        }
        TIFFWriteDirectory(outf);
    }
    TIFFClose(outf);
}

void writetiff_rgb(const char * fname, int sx, int sy, int sz, uint8_t * img)
{
    TIFF * outf = TIFFOpen(fname, "w");
    for (size_t i = 0; i < sz; ++i) {
        TIFFSetField(outf, TIFFTAG_IMAGEWIDTH, sx);
        TIFFSetField(outf, TIFFTAG_IMAGELENGTH, sy);
        TIFFSetField(outf, TIFFTAG_SAMPLESPERPIXEL, 3);
        TIFFSetField(outf, TIFFTAG_BITSPERSAMPLE, 8);
        TIFFSetField(outf, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
        TIFFSetField(outf, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
        TIFFSetField(outf, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_RGB);
        TIFFSetField(outf, TIFFTAG_COMPRESSION, COMPRESSION_NONE);

        TIFFSetField(outf,
                TIFFTAG_ROWSPERSTRIP,
                TIFFDefaultStripSize(outf, 3 * sx));

        for (uint32 row = 0; row < sy; row++) {
            if (TIFFWriteScanline(outf,
                                  img + 3 * sx * row + 3 * sx * sy * i,
                                  row, 0) < 0)
                break;
        }
        TIFFWriteDirectory(outf);
    }
    TIFFClose(outf);
}
