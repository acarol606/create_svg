#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "system.h"

Parameters *createParameters() {
    
    Parameters *param = calloc(1, sizeof(Parameters));

    param->outputDir = calloc(1, sizeof(char*));
    param->inputDir = calloc(1, sizeof(char*)*100);
    param->nameGeoFile = calloc(1, sizeof(char*));
    param->nameQryFile = calloc(1, sizeof(char*));

    strcpy(param->inputDir, getcwd(NULL, 0));

    return param;
}

Parameters *setParameters(int argc, char** argv, Parameters *param) {
    if(argc < 2) {
        return NULL;
    }

    for(int index=1; index<argc; index++) {
        
        if(!strcmp(argv[index], "-e") == 1) {
            strcpy(param->inputDir, argv[index+1]);

        } else if(!strcmp(argv[index], "-f") == 1) {
            strcpy(param->nameGeoFile, argv[index+1]);

        } else if(!strcmp(argv[index], "-q") == 1) {
            strcpy(param->nameQryFile, argv[index+1]);

        } else if(!strcmp(argv[index], "-o") == 1) {
            strcpy(param->outputDir, argv[index+1]);

        }
    }

    return param;
}