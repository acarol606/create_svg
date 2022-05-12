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

Item buildRectangleParameters(Rectangle vrectangle, int id, char *corb, char *corp, double width, double height, double y, double x) {
    GRectangle *rectangle = (GRectangle*) vrectangle;

    rectangle->id = id;
    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;
    rectangle->corb = malloc(sizeof(char*)*strlen(corb));
    strcpy(rectangle->corb, corb);
    rectangle->corp = malloc(sizeof(char*)*strlen(corp));
    strcpy(rectangle->corp, corp);

    return rectangle;
}

Item buildRectangle(char *command, Rectangle vrectangle) {
    printf("--- ENTROU buildRectangle ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    char *eptr;
    GRectangle *rectangle = (GRectangle*) vrectangle;

    rectangle->id = atoi(ptr);
    ptr = strtok(NULL, " ");
    
    rectangle->x = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    rectangle->y = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    rectangle->width = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    rectangle->height = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    rectangle->corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(rectangle->corb, ptr);
    ptr = strtok(NULL, " ");

    rectangle->corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(rectangle->corp, ptr);

    /* printf("Id: %d\n", rectangle->id);
    printf("X: %f\n", rectangle->x);
    printf("Y: %f\n", rectangle->y);
    printf("Width: %lf\n", rectangle->width);
    printf("Height: %lf\n", rectangle->height);
    printf("Corb: %s\n", rectangle->corb);
    printf("Corp: %s\n", rectangle->corp);

    printf("--- FIM buildRectangle ---\n"); */

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

void freeRectangle(Rectangle r) {
    GRectangle *rectangle = (GRectangle*) r;

    free(rectangle->corb);
    free(rectangle->corp);
    free(rectangle);
}