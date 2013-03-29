#ifndef BRECS_H_GWC5RGBI
#define BRECS_H_GWC5RGBI

typedef unsigned short int lab_t;

typedef struct {
    int nbcomp;
    lab_t * imglab;
    int * coordcomp;
    int * nbact;
    int ** activepixcomp;
} ccomp_dec;

ccomp_dec connectcomp_decomp(float * img, float radius);

extern char * prog_name;

float min(float * img, int size);
float max(float * img, int size);
float maxra(float * num, float * den, int size);
float minra(float * num, float * den, int size);

#define PLOT_NO_RESCALE 0
#define PLOT_RESCALE 1

#define MAX_LABEL 65355


#endif /* end of include guard: BRECS_H_GWC5RGBI */
