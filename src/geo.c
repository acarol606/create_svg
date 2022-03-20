#include <stdio.h>
#include "geo.h"

void buildGeometricForm(FILE *arq) {
    while(!feof(arq)) {
        char geoId[100];
        fscanf(arq, "%s", geoId);
        printf("%s \n", geoId);
    }
}