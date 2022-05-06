#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "files.h"

typedef void* Parameters;

Parameters *createParameters();
char *getOutputDir(Parameters p, char type);
char *getGeoPath(Parameters p);
char *getQryPath(Parameters p);
char *getTxtPath(Parameters p);

#endif