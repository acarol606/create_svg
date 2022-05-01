#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "files.h"

typedef void* Parameters;

Parameters *createParameters();
char *makePathGeoFile(Parameters p);
char *makePathQryFile(Parameters p);
char *getQryName(Parameters p);
char *getOutputDir(Parameters p, char *extention);
char *getOutputDir2(Parameters p, char *extention);

#endif