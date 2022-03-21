#include <stdio.h>
#include <string.h>
#include "geo.h"

void buildGeometricForm(FILE *arq) {
    List *list = malloc(sizeof(List));

    while(!feof(arq)) {

        char geoId[10];
        fscanf(arq, "%s", geoId);

        switch(geoId[0]) {
            case 'c':
                list->circle = buildCircle(arq);
                break;
            case 't':
                break;
            case 'l':
                break;
            case 'r':
                break;
        }
    }
    printf("%d\n", list->circle->x);
}

GCircle *buildCircle(FILE *arq) {
    GCircle *circle = calloc(1, sizeof(GCircle*));

    strcpy(circle->id, 'c');
    fscanf(arq, "%.2f", circle->x);
    fscanf(arq, "%.2f", circle->y);
    fscanf(arq, "%.2f", circle->radius);
    fscanf(arq, "%s", circle->corp);
    fscanf(arq, "%s", circle->corb);

    return circle;
}

