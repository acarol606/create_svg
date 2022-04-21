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

Item buildCircle(FILE *arq, Circle vcircle) {
    printf("--- ENTROU buildCircle ---\n");

    GCircle *circle = (GCircle*) vcircle;

    int idAux;
    char *corb;
    char *corp;

    fscanf(arq, "%d", &idAux);
    
    fscanf(arq, "%lf", &circle->x);

    fscanf(arq, "%lf", &circle->y);
    
    fscanf(arq, "%lf", &circle->radius);

    fscanf(arq, "%s", corb);
    circle->corb = (char*) malloc(sizeof(char*)+strlen(corb)+1);
    strcpy(circle->corb, corb);

    fscanf(arq, "%s", corp);
    circle->corp = (char*) malloc(sizeof(char*)+strlen(corp)+1);
    strcpy(circle->corp, corp);

    circle->id = idAux;

    printf("Id: %d\n", circle->id);
    printf("X: %lf\n", circle->x);
    printf("Y: %lf\n", circle->y);
    printf("Radius: %lf\n", circle->radius);
    printf("Corb: %s\n", circle->corb);
    printf("Corp: %s\n", circle->corp);

    printf("--- FIM buildCircle ---\n");

    return circle;
}

int getIdCircle(Circle circle) {
    // printf("\n--- Entrou getIdCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->id;
}

double getXCircle(Circle circle) {
    // printf("\n--- Entrou getXCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->x;
}

double getYCircle(Circle circle) {
    // printf("\n--- Entrou getYCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->y;
}

double getRadiusCircle(Circle circle) {
    // printf("\n--- Entrou getRadiusCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->radius;
}

char *getCorBCircle(Circle circle) {
    // printf("\n--- Entrou getCorBCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->corb;
}

char *getCorPCircle(Circle circle) {
    // printf("\n--- Entrou getCorPCircle ---\n");
    GCircle *gcircle = (GCircle*) circle;

    return gcircle->corp;
}