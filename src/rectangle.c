#include "rectangle.h"
#include <stdio.h>

struct rectangle {
    int id;
    float x;
    float y;
    float width;
    float height;
    char corb[20];
    char corp[20];
};

typedef struct rectangle GRectangle;

Rectangle createRectangle() {
    GRectangle *rectangle = calloc(1, sizeof(GRectangle*));

    return rectangle;
}

Item buildRectangle(FILE *arq, Rectangle vrectangle, char infos[], char *eptr) {
      printf("--- ENTROU buildRectangle ---\n");

      GRectangle *rectangle = (GRectangle*) vrectangle;

      fscanf(arq, "%s", infos);
      rectangle->id = atoi(infos);
      
      fscanf(arq, "%s", infos);
      rectangle->x = strtod(infos, &eptr);

      fscanf(arq, "%s", infos);
      rectangle->y = strtod(infos, &eptr);
      
      fscanf(arq, "%s", infos);
      rectangle->width = strtod(infos, &eptr);

      
      fscanf(arq, "%s", infos);
      rectangle->height = strtod(infos, &eptr);

      
      fscanf(arq, "%s", infos);
      strcpy(rectangle->corb, infos);

      
      fscanf(arq, "%s", infos);
      strcpy(rectangle->corp, infos);

      

      printf("Id: %d\n", rectangle->id);
      printf("X: %f\n", rectangle->x);
      printf("Y: %f\n", rectangle->y);
      printf("Width: %lf\n", rectangle->width);
      printf("Height: %lf\n", rectangle->height);
      printf("Corb: %s\n", rectangle->corb);
      printf("Corp: %s\n", rectangle->corp);

      printf("--- FIM buildRectangle ---\n");

      return rectangle;
}


int getIdRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->id;
}
char *getCorBRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->corb;
}
char *getCorPRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->corp;
}
double getXRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->x;
}

double getYRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->y;
}

double getWidthRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->width;
}

double getHeightRectangle(Rectangle *rectangle) {
    GRectangle *grectangle = (GRectangle*) rectangle;

    return grectangle->height;
}