#pragma once 

#include "brecs.h"
int           initialize_params_file(const char* filename);
struct params read_params(const char* filename,int dataset);
//int          write_params(const char* filename,const struct params *params, const char *description);


/* NOTES

The parameters file is able to store multiple parameter sets, one each for different data sets of
interest.  Under-the-hood, the file is a sqlite3[1] database.  It can be edited by freely available tools
such as SqliteBrowser[2].


int initialize_params_file(const char* filename)

    Returns 1 on success, otherwise 0.
    Opens a parameter database at filename, and initializes it with a default parameter set.

struct params read_params(const char* filename,int dataset)

    Returns a parameter set corresponding to the dataset from the file at filename.
    
    The returned structure has an 'isok' field that will be 1 on success, and 0 otherwise.

    If the dataset id is less than 0, the first one found in filename will be read.  
    Otherwise, if the requested dataset is not found, the returned structure will indicate failure.

int write_params(const char* filename,const struct params *params, const char *description);

    (Not implemented)

    The idea is that this would record the parameter set to filename as well as an optional description.
    It wouldn't be too hard to add.

*/

/* REFERENCES
[1]: https://www.sqlite.org/
[2]: http://sqlitebrowser.org/
*/