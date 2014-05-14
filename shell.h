#ifndef NETDISKS_SHELL_H_
#define NETDISKS_SHELL_H_

#include <string>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define BUFFSIZE 1024
#define MAX_PATH_LENGTH 1024

extern char pwd[];
extern char npwd[];
extern char **cmdArgs;
extern int cmdArgc;

typedef enum
{
    LS,
    NLS,
    PWD,
    NPWD,
    PUT,
    GET,
    CD,
    NCD,
    MKDIR,
    NMKDIR,
    TOUCH,
    NTOUCH,
    RM,
    NRM,
    MV,
    NMV,
    CP,
    NCP,
    VERSION,
    USAGE,
}ACCESS_TYPE;

void getPwd(char*, int);
int executeLocalCommand(string);

#endif
