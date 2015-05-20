#pragma once 

#include "brecs.h"
struct params read_params(const char* filename);
void write_params(const char* filename,const struct params *params);
