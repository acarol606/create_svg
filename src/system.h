#ifndef SYSTEM_H
#define SYSTEM_H

struct parameters {
    char *outputDir;
    char *inputDir;
    char *nameGeoFile;
    char *nameQryFile;
};

typedef struct parameters Parameters;

Parameters *createParameters();

Parameters *setParameters(int argc, char** argv, Parameters *param);

#endif