#ifndef SYSTEM_H
#define SYSTEM_H

typedef void* Parameters;

Parameters *createParameters();
char *makePathGeoFile(Parameters *p);

#endif