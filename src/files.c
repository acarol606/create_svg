#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"

FILE *loadFile(char path[]) {
    FILE *arq = fopen(path, "r");
    return arq;
}

char *buildFilePath(char *directory, char *fileName) {
    char separator[] = "/";
    char *result = malloc(strlen(directory)+strlen(fileName)+1);

    strcpy(result, directory);
    strcat(result, separator);
    strcat(result, fileName);

    return result;
}