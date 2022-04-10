#ifndef SYSTEM_H
#define SYSTEM_H

typedef void* Parameters;

Parameters *createParameters();
char *makePathGeoFile(Parameters p);
char *makePathQryFile(Parameters p);
char *getOutputDir(Parameters p);

#endif