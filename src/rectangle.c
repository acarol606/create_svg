#include "rectangle.h"
#include <stdio.h>

struct rectangle {
    int id;
    float x;
    float y;
    float width;
    float height;
    char *corb;
    char *corp;
};

typedef struct rectangle GRectangle;

Rectangle createRectangle() {
    GRectangle *rectangle = calloc(1, sizeof(GRectangle));

    return rectangle;
}

Item buildRectangle(FILE *arq, Rectangle vrectangle) {
      printf("--- ENTROU buildRectangle ---\n");

      GRectangle *rectangle = (GRectangle*) vrectangle;

      int idAux;
      char *corb;
      char *corp;

      fscanf(arq, "%d", &idAux);
      
      fscanf(arq, "%lf", &rectangle->x);

      fscanf(arq, "%lf", &rectangle->y);
      
      fscanf(arq, "%lf", &rectangle->width);
      
      fscanf(arq, "%lf", &rectangle->height);
      
      fscanf(arq, "%s", corb);
      rectangle->corb = (char*) malloc(sizeof(char*)+strlen(corb)+1);
      strcpy(rectangle->corb, corb);

      
      fscanf(arq, "%s", corp);
      rectangle->corp = (char*) malloc(sizeof(char*)+strlen(corp)+1);
      strcpy(rectangle->corp, corp);

      
      rectangle->id = idAux;

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