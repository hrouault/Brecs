#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

#include "Brecs.h"
#include "parameter.io.h"

typedef struct {
    const char* name;
    const char* type;
    const char* value;
    const size_t off;
    uint8_t check;
} conf_entry_t;

static conf_entry_t default_pars[] = {
      {"pixmean",      "REAL",   "500",   offsetof(params_t, pixmean), 0}
     ,{"pixstd",       "REAL",   "200",   offsetof(params_t, pixstd), 0}
     ,{"rho",          "REAL",   "0.001", offsetof(params_t, rho), 0}
     ,{"beta",         "REAL",   "1.0",   offsetof(params_t, beta), 0}
     ,{"pixsdivz",     "INTEGER","1",     offsetof(params_t, pixsdivz), 0}
     ,{"spixnm",       "REAL",   "133.0", offsetof(params_t, spixnm), 0}
     ,{"spixznm",      "REAL",   "100.0", offsetof(params_t, spixznm), 0}
     ,{"mesoffset",    "REAL",   "80",    offsetof(params_t, mesoffset), 0}
     ,{"mesampli",     "REAL",   "20",    offsetof(params_t, mesampli), 0}
     ,{"noiseoffset",  "REAL",   "1",     offsetof(params_t, noiseoffset), 0}
     ,{"nbiter",       "INTEGER","200",   offsetof(params_t, nbiter), 0}
     ,{"prefacradcc",  "REAL",   "1.0",   offsetof(params_t, prefacradcc), 0}
     ,{"convolpixthr", "REAL",   "40.0",  offsetof(params_t, convolpixthr), 0}
     ,{"ainitpfact",   "REAL",   "1.0",   offsetof(params_t, ainitpfact), 0}
     ,{"meanback",     "REAL",   "0",     offsetof(params_t, meanback), 0}
     ,{"locaintensthr","REAL",   "1000",  offsetof(params_t, locaintensthr), 0}
     ,{"overlaymaxint","REAL",   "50.4",  offsetof(params_t, overlaymaxint), 0}
     ,{"overlayminint","REAL",   "0.1",   offsetof(params_t, overlayminint), 0}
     ,{"relerrthr",    "REAL",   "0.001", offsetof(params_t, relerrthr), 0}
     ,{"nbinternloop", "INTEGER",   "1",  offsetof(params_t, nbinternloop), 0}
     ,{"damp1",        "REAL",   "0.05",  offsetof(params_t, damp1), 0}
     ,{"damp2",        "REAL",   "0.1",   offsetof(params_t, damp2), 0}
     ,{"random_loca",  "INTEGER","0",     offsetof(params_t, random_loca), 0}
};

#define MAXLINE 256

void read_params_txt(const char* filename, params_t* par)
{
    char bufr[MAXLINE];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        perror(filename);
        exit(EXIT_FAILURE);
    }
    size_t nbel = sizeof(default_pars) / sizeof(default_pars[0]);
    while (fgets(bufr, MAXLINE, fp)) {
        char* token = strtok(bufr, "\t =\n\r");
        char* item;
        char* value;
        if (token == NULL || token[0] == '#') continue;

        item = token;
        token = strtok(NULL, "\t =\n\r");
        value = token;

        size_t i;
        for (i = 0; i < nbel; ++i) {
            if (!strcmp(item, default_pars[i].name)) {
                if (default_pars[i].check == 1) {
                    printf("Parameter defined twice: %s\n", item);
                    exit(EXIT_FAILURE);
                }
                if (!strcmp(default_pars[i].type, "REAL")) {
                    *(float*)((char*)par + default_pars[i].off) = (float)atof(value);
                } else {
                    *(uint32_t*)((char*)par + default_pars[i].off) = (uint32_t)atoi(value);
                }
                default_pars[i].check = 1;
                break;
            }
        }
        if (i == nbel) {
            printf("Parameter not recognized: %s\n", item);
            exit(EXIT_FAILURE);
        }
    }
    for (size_t i = 0; i < nbel; ++i) {
        if (default_pars[i].check == 0) {

            if (!strcmp(default_pars[i].type, "REAL")) {
                *(float*)((char*)par + default_pars[i].off) =
                    (float)atof(default_pars[i].value);
            } else {
                *(uint32_t*)((char*)par + default_pars[i].off) =
                    (uint32_t)atoi(default_pars[i].value);
            }
        }
    }
    if (errno != 0) {
        perror("token parsing");
        exit(EXIT_FAILURE);
    }
}
