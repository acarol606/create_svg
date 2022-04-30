#include "system.h"

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

char *getOutputDir(Parameters p, char *extention) {
    ParametersL *param = (ParametersL*) p;

    if(endsWith(param->outputDir) == 0) {
        return param->outputDir;
    }

    char *relativePath = malloc(strlen(param->outputDir)+TAM_EXTENTION+2);
    strcpy(relativePath, param->outputDir);
    
    char *nameSVG = malloc(strlen(param->nameGeoFile));
    strcpy(nameSVG, param->nameGeoFile);
    int len = strlen(param->nameGeoFile);
    int i;

    for(i=1; i<=TAM_EXTENTION+1; i++) {
        nameSVG[len-i] = '\0';
    }
    
    strcat(relativePath, "/");
    strcat(relativePath, nameSVG);

    if(param->nameQryFile != NULL) {
    
        char *nameSVGquery = malloc(strlen(param->nameQryFile));
        strcpy(nameSVGquery, param->nameQryFile);
        int len = strlen(param->nameQryFile);
        int i;

        for(i=1; i<=TAM_EXTENTION+1; i++) {
            nameSVGquery[len-i] = '\0';
        }
    
        strcat(relativePath, "-");
        strcat(relativePath, nameSVGquery);
    }

    strcat(relativePath, extention);

    return relativePath;
}

char *makePathGeoFile(Parameters p) {
    ParametersL *param = (ParametersL*) p;

    return buildFilePath(param->inputDir, param->nameGeoFile);
}

char *makePathQryFile(Parameters p) {
    ParametersL *param = (ParametersL*) p;
    return buildFilePath(param->inputDir, param->nameQryFile);
}

char *getQryName(Parameters p) {
    ParametersL *param = (ParametersL*) p;
    return param->nameQryFile;
}

int endsWith(char *string) {
  string = strrchr(string, '.');

  if(string != NULL) {
    return (strcmp(string, ".svg"));
  }
  return -1;
}