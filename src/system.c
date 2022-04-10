#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "system.h"
#include "files.h"

#define TAM_EXTENTION 3

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
            param->inputDir = argv[index+1];

        } else if(!strcmp(argv[index], "-f")) {
            param->nameGeoFile = argv[index+1];

        } else if(!strcmp(argv[index], "-q")) {
            param->nameQryFile = argv[index+1];

        } else if(!strcmp(argv[index], "-o")) {
            param->outputDir = argv[index+1];

        }
    }

    return param;
}

Parameters *createParameters(int argc, char** argv) {
    
    ParametersL *param = malloc(sizeof(ParametersL));

    param->outputDir = malloc(sizeof(char*));
    param->inputDir = malloc(sizeof(char*)*200);
    param->nameGeoFile = malloc(sizeof(char*));
    param->nameQryFile = malloc(sizeof(char*));

    strcpy(param->inputDir, getcwd(NULL, 0));

    return setParameters(argc, argv, param);
}

char *getOutputDir(Parameters p) {
    ParametersL *param = (ParametersL*) p;

    if(endsWith(param->outputDir) == 0) {
        return param->outputDir;
    }
    
    char *nameSVG;
    memcpy(nameSVG, param->nameGeoFile, strlen(param->nameGeoFile)-TAM_EXTENTION);
    strcat(param->outputDir, "/");
    strncat(param->outputDir, nameSVG, strlen(param->nameGeoFile)-TAM_EXTENTION);
    strcat(param->outputDir, "svg");
    return param->outputDir;
}

char *makePathGeoFile(Parameters p) {
    ParametersL *param = (ParametersL*) p;
    return buildFilePath(param->inputDir, param->nameGeoFile);
}

int endsWith(char *string) {
  string = strrchr(string, '.');

  if(string != NULL) {
    return (strcmp(string, ".svg"));
  }
  return -1;
}