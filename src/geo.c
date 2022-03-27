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
      printf("X: %f\n", rectangle->x);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->y = strtod(infos, &eptr);
      printf("Y: %f\n", rectangle->y);

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
      rectangle->corb = (char*) malloc(sizeof(char*)+strlen(infos)+1);
      strcpy(rectangle->corb, infos);
      printf("Corb: %s\n", rectangle->corb);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corp = (char*) malloc(sizeof(char*)+strlen(infos)+1);
      strcpy(rectangle->corp, infos);
      printf("Corp: %s\n", rectangle->corp);

      strcpy(infos, "");

      createSVGRectangle(rectangle->corb, rectangle->corp, rectangle->width, rectangle->height, rectangle->y, rectangle->x);

      free(rectangle->corp);
      free(rectangle->corb);

      rectangle->corp = NULL;
      rectangle->corb = NULL;

      free(rectangle->corp);
      free(rectangle->corb);
      
      return rectangle;
}

void buildCircle(FILE *arq, GCircle *circle, char infos[], char *eptr) {
    printf("--- ENTROU buildCircle ---\n");


    circle->type = infos[0];

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->id = atoi(infos);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->x = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->y = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->radius = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corb = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(circle->corb, infos);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corp = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(circle->corp, infos);

    strcpy(infos, "");

    printf("Type: %c\n", circle->type);
    printf("Id: %d\n", circle->id);
    printf("X: %lf\n", circle->x);
    printf("Y: %lf\n", circle->y);
    printf("Radius: %lf\n", circle->radius);
    printf("Corb: %s\n", circle->corb);
    printf("Corp: %s\n", circle->corp);

    createSVGCircle(circle->corb, circle->corp, circle->radius, circle->y, circle->x);

    free(circle->corp);
    free(circle->corb);
    circle->corp = NULL;
    circle->corb = NULL;
    free(circle->corp);
    free(circle->corb);

    return circle;
}
void buildGeometricForm(FILE *arq, List *list) {
    printf("--- ENTROU buildGeometricForm ---\n");
    int count = 0;
    GCircle *circle = (GCircle*) calloc(1, sizeof(GCircle*));
    GRectangle *rectangle = (GRectangle*) calloc(2, sizeof(GRectangle*));

    insertHeaderSVG();

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
        printf("--------------------------------\n");
    }
    printSizeList(list);
}