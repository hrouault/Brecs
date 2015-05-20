/* parses brecs parameters from a text file

Grammer:

document = EOF | line | line document
line = comment EOL | kv EOL
comment = [/] [text]
kv = keyname [any non-alphanumeric] [0-9.] | kv comment
keyname = [alphanumeric]

*/
#include <stdio.h>
#include <stdlib.h>
#include "brecs.h"

#include "sqlite3.h"

#define LOG(msg) printf("%s(%d): %s()\n\t%s\n",__FILE__,__LINE__,__FUNCTION__,msg)
#define HERE LOG("HERE");
#define SQLITE_ERR(e) do{ int ecode_=(e); if(ecode_!=SQLITE_OK){onsqliteerr(ecode_); goto Error;}}while(0)

static void onsqliteerr(int ecode) {
    LOG(sqlite3_errstr(ecode));
}

struct params read_params(const char* filename) {
    struct params params={0};
    sqlite3 *db=0;
    sqlite3_stmt *stmt=0;    
    int ecode=0;
    printf("###############\n");
    SQLITE_ERR(sqlite3_open(filename,&db));
    SQLITE_ERR(sqlite3_prepare_v2(db,"select pixmean from parameters where _rowid_==3;",-1,&stmt,0));
    while((ecode=sqlite3_step(stmt))==SQLITE_ROW) {
        printf("%f\n",sqlite3_column_double(stmt,0));
    }
    if(ecode!=SQLITE_DONE)
        SQLITE_ERR(ecode);
Finalize:
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    printf("###############\n");
    return params;
Error:
    params.isok=0;
    goto Finalize;
}