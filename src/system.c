#include "system.h"

#define TAM_EXTENTION 3

struct parameters {
    char *outputDir;
    char *inputDir;
    char *nameGeoFile;
    char *nameQryFile;
    char *geoFilePath;
    char *qryFilePath;
    char *textFilePath;
};

typedef struct parameters ParametersL;

char *removeExtention(char *nameFile) {
    int i;
    int len = strlen(nameFile);

    for(i=1; i<=TAM_EXTENTION+1; i++) {
        nameFile[len-i] = '\0';
    }

    return nameFile;
}

char *invertString(char *str) {
    int i = strlen(str);
    printf("String: %s\n", str);
    char *result = malloc(sizeof(char*)*200);

    while (i >= 0) {
        strncat(result, &str[i], 1);
        i--;
    }
    return result;
}

char *removeLastDirectory(char *dir) {
    int i = strlen(dir);
    char *auxPath = malloc(sizeof(char*)*200);
    char *geoNameInverted = malloc(sizeof(char*)*200);
    int count = 0;

    strcpy(auxPath, dir);

    while (i >= 0) {
        if (auxPath[i]=='/') {
            break;
        }
        strncat(geoNameInverted, &auxPath[i], 1);
        dir[i]='\0';
        i--;
        count++;
    }
    return invertString(geoNameInverted);
}

Parameters *setParameters(int argc, char** argv, ParametersL *param) {

    if(argc < 2) {
        return NULL;
    }
    
    bool hasGeoFileName = false;
    bool hasQryFileName = false;

    for(int index=1; index<argc; index++) {
        
        if(!strcmp(argv[index], "-e")) {
            param->inputDir = argv[index+1];

        } else if(!strcmp(argv[index], "-f")) {
            hasGeoFileName = true;
            param->nameGeoFile = argv[index+1];

        } else if(!strcmp(argv[index], "-q")) {
            hasQryFileName = true;
            param->nameQryFile = argv[index+1];

        } else if(!strcmp(argv[index], "-o")) {
            param->outputDir = argv[index+1];

        }
    }

    strcpy(param->geoFilePath, param->inputDir);
    
    if (!hasGeoFileName) {
        param->nameGeoFile = removeLastDirectory(param->inputDir);
    }
    

    
    strcpy(param->textFilePath, param->outputDir);
    strcpy(param->qryFilePath, param->inputDir);

    char* textFileName = malloc(sizeof(char*)+strlen(param->nameGeoFile)+strlen(param->nameQryFile));

    if (!hasGeoFileName) {
        strcat(param->geoFilePath, ".geo");
        strcpy(textFileName, param->nameGeoFile);
        strcat(textFileName, "-");

    } else {
        /* Montando caminho do arquivo GEO */
        strcat(param->geoFilePath, "/");
        strcat(param->geoFilePath, param->nameGeoFile);

        /* Montando caminho do arquivo TXT */
        removeExtention(param->nameGeoFile);
        strcpy(textFileName, param->nameGeoFile);
        strcat(textFileName, "-");
    }

    if (!hasQryFileName) {
        strcat(param->qryFilePath, ".qry");

    } else {
        if (hasGeoFileName) {
            strcat(param->qryFilePath, "/");
        }
        
        /* Montando caminho do arquivo QRY */
        strcat(param->qryFilePath, param->nameQryFile);

        /* Contatenando o nome do qry para o nome do TXT */
        strcat(textFileName, removeExtention(param->nameQryFile));
        strcat(textFileName, ".txt");
        strcat(param->textFilePath, "/");
        strcat(param->textFilePath, textFileName);
    }

    

    return param;
}

Parameters *createParameters(int argc, char** argv) {
    
    ParametersL *param = malloc(sizeof(ParametersL));

    param->outputDir = malloc(sizeof(char*));
    param->inputDir = malloc(sizeof(char*)*200);
    param->nameGeoFile = malloc(sizeof(char*));
    param->nameQryFile = malloc(sizeof(char*));
    param->geoFilePath = malloc(sizeof(char*)*100);
    param->qryFilePath = malloc(sizeof(char*)*100);
    param->textFilePath = malloc(sizeof(char*)*100);

    strcpy(param->inputDir, getcwd(NULL, 0));
    return setParameters(argc, argv, param);
}

char *getGeoPath(Parameters p) {
    ParametersL *param = (ParametersL*) p;

    return param->geoFilePath;
}

char *getQryPath(Parameters p) {
    ParametersL *param = (ParametersL*) p;

    return param->qryFilePath;
}

char *getTxtPath(Parameters p) {
    ParametersL *param = (ParametersL*) p;

    return param->textFilePath;
}

char *getOutputDir(Parameters p, char type) {
    ParametersL *param = (ParametersL*) p;

    char *result = malloc(sizeof(char*)*strlen(param->outputDir));

    strcpy(result, param->outputDir);
    strcat(result, "/");

    switch (type)
    {
    case 's':
        strcat(result, param->nameGeoFile);
        break;
    case 'q':
        strcat(result, param->nameGeoFile);
        strcat(result, "-");
        strcat(result, param->nameQryFile);
        break;
    }

    strcat(result, ".svg");

    return result;
}