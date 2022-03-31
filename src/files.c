#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

FILE *loadFile(char path[]) {
    FILE *arq = fopen(path, "r");
    if(arq == NULL) {
        printf("Problemas na abertura do arquivo!\n");
        return NULL;
    }
    return arq;
}

FILE *createSVG() {
    FILE *svg = fopen("/home/vfsilva/estudo/repositories/project/output/teste.svg", "a");
    if (svg == NULL) {
        printf("Problemas na criação do arquivo!\n");
        return NULL;
    }

    return svg;
}

char *buildFilePath(char *directory, char *fileName) {
    char separator[] = "/";
    char *result = malloc(strlen(directory)+strlen(fileName)+1);

    strcpy(result, directory);
    strcat(result, separator);
    strcat(result, fileName);

    return result;
}