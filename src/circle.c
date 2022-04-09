#include "circle.h"

struct circle {
    int id;
    double x;
    double y;
    double radius;
    char *corp;
    char *corb;
};
typedef struct circle GCircle;

Circle createCircle() {
    GCircle *circle = calloc(1, sizeof(GCircle));
    return circle;
}

Item buildCircle(FILE *arq, Circle vcircle, char infos[], char *eptr) {
    printf("--- ENTROU buildCircle ---\n");

    GCircle *circle = (GCircle*) vcircle;

    fscanf(arq, "%s", infos);
    circle->id = atoi(infos);
    
    fscanf(arq, "%s", infos);
    printf("\nTeste: %s \n\n", infos);
    circle->x = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    circle->y = strtod(infos, &eptr);
    
    fscanf(arq, "%s", infos);
    circle->radius = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    circle->corb = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(circle->corb, infos);

    fscanf(arq, "%s", infos);
    circle->corp = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(circle->corp, infos);

    

    printf("Id: %d\n", circle->id);
    printf("X: %lf\n", circle->x);
    printf("Y: %lf\n", circle->y);
    printf("Radius: %lf\n", circle->radius);
    printf("Corb: %s\n", circle->corb);
    printf("Corp: %s\n", circle->corp);

    printf("--- FIM buildCircle ---\n");

    return circle;
}

int getIdCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->id;
}

double getXCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->x;
}

double getYCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->y;
}

double getRadiusCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->radius;
}

char *getCorBCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->corb;
}

char *getCorPCircle(Circle *circle) {
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->corp;
}