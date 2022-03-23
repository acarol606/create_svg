#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "system.h"
#include "files.h"

struct parameters {
    char *outputDir;
    char *inputDir;
    char *nameGeoFile;
    char *nameQryFile;
};

typedef struct parameters ParametersL;

Parameters *setParameters(int argc, char** argv, ParametersL *param) {

    if(argc < 2) {
        return NULL;
    }

    for(int index=1; index<argc; index++) {
        
        if(!strcmp(argv[index], "-e")) {
            strcpy(param->inputDir, argv[index+1]);
            printf("Dir Argument: %s\n",param->inputDir);

        } else if(!strcmp(argv[index], "-f")) {
            strcpy(param->nameGeoFile, argv[index+1]);

        } else if(!strcmp(argv[index], "-q")) {
            strcpy(param->nameQryFile, argv[index+1]);

        } else if(!strcmp(argv[index], "-o")) {
            strcpy(param->outputDir, argv[index+1]);

        }
    }

    return param;
}

Parameters *createParameters(int argc, char** argv) {
    
    ParametersL *param = malloc(sizeof(ParametersL));

    param->outputDir = malloc(sizeof(char*));
    param->inputDir = malloc(200);
    param->nameGeoFile = malloc(sizeof(char*));
    param->nameQryFile = malloc(sizeof(char*));

    strcpy(param->inputDir, getcwd(NULL, 0));

    return setParameters(argc, argv, param);
}

char *makePathGeoFile(Parameters *p) {
    ParametersL *param = (ParametersL*) p;
    return buildFilePath(param->inputDir, param->nameGeoFile);
}