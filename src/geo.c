#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geo.h"

struct circle {
    char type;
    int id;
    double x;
    double y;
    double radius;
    char *corp;
    char *corb;
};

struct text {
    char type;
    int id;
    float x;
    float y;
    char anchor;
    char *corp;
    char *corb;
    char *text;
};

struct line {
    char type;
    int id;
    float initX;
    float initY;
    float finalX;
    float finalY;
    char *color;
};

struct rectangle {
    char type;
    int id;
    float x;
    float y;
    float width;
    float height;
    char *corb;
    char *corp;
};

typedef struct circle GCircle;
typedef struct text GText;
typedef struct line GLine;
typedef struct rectangle GRectangle;

Item *buildRectangle(FILE *arq, char infos[], char *eptr) {

      GRectangle *rectangle = calloc(1, sizeof(GRectangle*));

      rectangle->type = infos[0];

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->id = atoi(infos);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->x = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->y = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->width = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->height = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corb = infos;

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corp = infos;

      strcpy(infos, "");

      return rectangle;
}

Item *buildCircle(FILE *arq, char infos[], char *eptr) {
    printf("-- ENTROU buildCircle ---\n");

    GCircle *circle = calloc(1, sizeof(GCircle*));

    circle->type = infos[0];
    printf("Type: %c\n", circle->type);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->id = atoi(infos);
    printf("Id: %d\n", circle->id);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->x = strtod(infos, &eptr);
    printf("X: %lf\n", circle->x);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->y = strtod(infos, &eptr);
    printf("Y: %lf\n", circle->y);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->radius = strtod(infos, &eptr);
    printf("Radius: %lf\n", circle->radius);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corb = infos;
    printf("Corb: %s\n", circle->corb);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corp = infos;
    printf("Corp: %s\n", circle->corp);

    strcpy(infos, "");

    printf("--------------------------------\n");

    return circle;
}

Item *buildGeometricForm(FILE *arq) {
    printf("-- ENTROU buildGeometricForm ---\n");
    char infos[10];
    char *eptr;
    fscanf(arq, "%s", infos);

    if (infos[0] == 'c' && infos[1] == NULL) {
        return buildCircle(arq, infos, eptr);

    } else if(infos[0] == 'r' && infos[1] == NULL) {
        return buildRectangle(arq, infos, eptr);

    }
}