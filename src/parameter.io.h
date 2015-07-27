#ifndef PARAMETER_IO_H_VUSLP0XQ
#define PARAMETER_IO_H_VUSLP0XQ



#include "Brecs.h"
int           initialize_params_file(const char* filename);

/* Returns a parameter set corresponding to the dataset from the file at
 * filename. */
params_t * read_params(const char* filename,int dataset);

#endif /* end of include guard: PARAMETER_IO_H_VUSLP0XQ */
