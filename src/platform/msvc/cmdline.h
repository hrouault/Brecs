#pragma once

struct gengetopt_args_info {
    char * filename_arg;
    char * psf_arg;
    char * output_arg;
    char * background_arg;
};


int cmdline_parser(int argc, char** argv, struct gengetopt_args_info* brecs_args);

/* 

A Note from Nathan Clack on why this file exists.
-------------------------------------------------

In the beginning, a Makefile generated a cmdline.h from cmdline.ggo

I don't want to rely on the command line generation tool for the windows build,
especially since I'm concentrating on making a library.

Perhaps I will replace the command line parser.

*/