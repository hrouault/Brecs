
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <png.h>

#define PLOT_NO_RESCALE 0
#define PLOT_RESCALE 1

#define MAX_LABEL 65535

typedef unsigned short int lab_t;

lab_t * roundker(int diam)
{
    int center = diam / 2;
    lab_t * ker = malloc(diam * diam * sizeof(lab_t));
    for (size_t i = 0; i < diam; i++) {
        for (size_t j = 0; j < diam; j++) {
            int x = j - diam / 2;
            int y = i - diam / 2;
            float rad2 = x * x + y * y;
            int ind = j + i * diam;
            if (rad2 < diam * diam / 4){
                ker[ind] = 1;
            } else {
                ker[ind] = 0;
            }
        }
    }
    return ker;
}

void maskpix(lab_t * img, int width, lab_t * ker, int diam, int x, int y){
    for (size_t i = 0; i < diam; i++) {
        for (size_t j = 0; j < diam; j++) {
            int ind = x + j - diam / 2 + (y + i - diam / 2) * width;
            img[ind] = img[ind] || ker[j + i * diam];
        }
    }
}

lab_t neighb(lab_t * img, int width, int x, int y)
{
    if (!img[x + (y - 1) * width - 1]
        || !img[x + (y - 1) * width]
        || !img[x + (y - 1) * width + 1]
        || !img[x + y * width - 1]
        || !img[x + y * width + 1]
        || !img[x + (y + 1) * width - 1]
        || !img[x + (y + 1) * width]
        || !img[x + (y + 1) * width + 1])
        return 1;
    return 0;
}

lab_t * dilate(lab_t * img, int width, int height, lab_t * ker, int diam)
{
    lab_t * res = malloc(width * height * sizeof(lab_t));
    for (size_t i = 0; i < width * height; ++i)
    {
        res[i] = img[i];
    }
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (img[j + i * width] && neighb(img, width, j, i)){
                maskpix(res, width, ker, diam, j, i);
            }
        }
    }
    return res;
}

void unionsets(lab_t * labs, int lastlab, int parentlab, int lab)
{
    printf("%i %i\n", parentlab, lab);
    if (lab != parentlab){
        for (int i = lab - 1; i < lastlab; ++i)
        {
            if (labs[i] == lab){
                labs[i] = parentlab;
            }
        }
    }
}

lab_t * aggregate(lab_t * img, int width, int height)
{
    lab_t labs[MAX_LABEL];
    lab_t neighblab[4];

    lab_t * imglabs = malloc(width * height * sizeof(lab_t));
    
    for (int i = 0; i < width * height; i++) {
        imglabs[i] = 0;
    }

    lab_t lastlab = 0;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int ind = j + i * width;
            if (img[ind]){
                lab_t lab4[4] = {0, 0, 0, 0};
                lab_t lab4p[4] = {0, 0, 0, 0};
                size_t nlab = 0;
                lab4[0] = imglabs[ind - width - 1];
                lab4[1] = imglabs[ind - width];
                lab4[2] = imglabs[ind - width + 1];
                lab4[3] = imglabs[ind - 1];
                lab_t minlab = MAX_LABEL;
                if (lab4[0]){
                    minlab = lab4[0];
                    lab4p[0] = lab4[0];
                    nlab++;
                }
                if (lab4[1]){
                    if (lab4[1] < minlab) minlab = lab4[1];
                    lab4p[nlab] = lab4[1];
                    nlab++;
                }
                if (lab4[2]){
                    if (lab4[2] < minlab) minlab = lab4[2];
                    lab4p[nlab] = lab4[2];
                    nlab++;
                }
                if (lab4[3]){
                    if (lab4[3] < minlab) minlab = lab4[3];
                    lab4p[nlab] = lab4[3];
                    nlab++;
                }
                if (nlab > 2){
                    for (int k = 0; k < nlab; ++k)
                    {
                        unionsets(labs, lastlab, minlab, lab4p[k]);
                    }
                }
                if (!nlab){
                    lastlab++;
                    labs[lastlab - 1] = lastlab;
                    imglabs[ind] = lastlab;
                } else {
                    imglabs[ind] = minlab;
                }
            }
        }
    }

    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int ind = j + i * width;

            if (imglabs[ind]){
                imglabs[ind] = labs[imglabs[ind] - 1];
            }
        }
    }

    return imglabs;
}

int main(int argc, const char *argv[])
{
    int imgsize = 300;
    int kersize = 51;
    lab_t * ker = roundker(kersize);

    lab_t * img = malloc(imgsize * imgsize * sizeof(lab_t));
    for (int i = 0; i < imgsize * imgsize; ++i)
    {
        img[i] = 0;
    }
    img[imgsize / 2 + imgsize * imgsize / 4] = 1;
    img[imgsize / 2 + imgsize * imgsize / 2] = 1;
    img[imgsize / 2 + imgsize * imgsize / 2 + 35] = 1;
    img[imgsize / 2 + imgsize * imgsize / 2 - 70] = 1;

    lab_t * imgdil = dilate(img, imgsize, imgsize, ker, kersize);

    aggregate(imgdil, imgsize, imgsize);

    free(ker);
    free(img);
    free(imgdil);
    
    return 0;
}
