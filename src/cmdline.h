#pragma once

#ifdef __clpusplus
extern "C" {
#endif

struct gengetopt_args_info {
    char * filename_arg;
    char * psf_arg;
    char * output_arg;
    char * background_arg;
};


int cmdline_parser(int argc, char** argv, struct gengetopt_args_info* brecs_args);

#ifdef __clpusplus
}
#endif

/* 

A Note from Nathan Clack on why this file exists.
-------------------------------------------------

In the beginning, a Makefile generated a cmdline.h from cmdline.ggo

I don't want to rely on the command line generation tool for the windows
build, so I wrote my own.

*/