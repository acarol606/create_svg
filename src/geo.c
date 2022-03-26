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

struct object {
    Item *value;
    struct object *next;
    struct object *prev;
};

typedef struct object Object;
typedef struct circle GCircle;
typedef struct text GText;
typedef struct line GLine;
typedef struct rectangle GRectangle;

void buildRectangle(FILE *arq, GRectangle *rectangle, char infos[], char *eptr) {

      printf("--- ENTROU buildRectangle ---\n");

      rectangle->type = infos[0];

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      printf("Type: %c\n", rectangle->type);
      rectangle->id = atoi(infos);
      printf("Id: %d\n", rectangle->id);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->x = strtod(infos, &eptr);
      printf("X: %lf\n", rectangle->x);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->y = strtod(infos, &eptr);
      printf("Y: %lf\n", rectangle->y);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->width = strtod(infos, &eptr);
      printf("Width: %lf\n", rectangle->width);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->height = strtod(infos, &eptr);
      printf("Height: %lf\n", rectangle->height);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corb = infos;
      printf("Corb: %s\n", rectangle->corb);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corp = infos;
      printf("Corp: %s\n", rectangle->corp);

      strcpy(infos, "");

      return rectangle;
}

void buildCircle(FILE *arq, GCircle *circle, char infos[], char *eptr) {
    printf("--- ENTROU buildCircle ---\n");

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
void buildGeometricForm(FILE *arq, List *list) {
    printf("--- ENTROU buildGeometricForm ---\n");
    int count = 0;
    GCircle *circle = (GCircle*) calloc(1, sizeof(GCircle*));
    GRectangle *rectangle = (GRectangle*) calloc(2, sizeof(GRectangle*));

    while(!feof(arq)) {
        char infos[10];
        char *eptr;
        fscanf(arq, "%s", infos);

        if (infos[0] == 'c' && infos[1] == NULL) {
            
            buildCircle(arq, circle, infos, eptr);
            list = insertItemInFinal(list, circle);
        } else if(infos[0] == 'r' && infos[1] == NULL) {
            
            buildRectangle(arq, rectangle, infos, eptr);
            list = insertItemInFinal(list, rectangle);
        }
    }
    printSizeList(list);
}