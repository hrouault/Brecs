/*
 * =====================================================================================
 *
 *       Filename:  sum.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 23:52:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    const int nbpix = 136 * 8 * 136 * 8;
    float * restot = malloc(nbpix * sizeof(float));
    float * restmp = malloc(nbpix * sizeof(float));
    for (unsigned int i = 0; i < nbpix; ++i)
    {
        restot[i] = 0;
    }
    printf("init\n");
    for (unsigned int i = 1; i < 22; ++i) {
        char fname[20];

        snprintf(fname, 19, "out%05d.raw", i);
        printf("%s\n", fname);

        FILE * fin = fopen(fname,"rb");

        fread(restmp, sizeof(float), nbpix, fin);
        fclose(fin);

        for (unsigned int i = 0; i < nbpix; ++i) {
            restot[i] += restmp[i];
        }
    }
    for (unsigned int i = 0; i < nbpix; ++i)
    {
        if (restot[i] > 1){
            restot[i] = log(restot[i]);
        } else {
            restot[i] = 0;
        }
    }
    errno = 0;
    FILE * fout = fopen("sumtot.raw", "wb");
    if (!fout) {
        fprintf(stderr, "%s: Couldn't open file %s: %s\n",
                "sum", "sumtot.raw", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fwrite(restot, sizeof(float), nbpix, fout);
    fclose(fout);
    
    return 0;
}
