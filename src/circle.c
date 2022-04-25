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

Item buildCircle(char *command, Circle vcircle) {
    printf("--- ENTROU buildCircle ---\n");

    char *ptr = strtok(command, " ");

    char *eptr;

    GCircle *circle = (GCircle*) vcircle;

    circle->id = atoi(ptr);
    ptr = strtok(NULL, " ");
    
    circle->x = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    circle->y = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");
    
    circle->radius = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    circle->corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(circle->corb, ptr);
    ptr = strtok(NULL, " ");

    circle->corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(circle->corp, ptr);

    /* printf("Id: %d\n", circle->id);
    printf("X: %lf\n", circle->x);
    printf("Y: %lf\n", circle->y);
    printf("Radius: %lf\n", circle->radius);
    printf("Corb: %s\n", circle->corb);
    printf("Corp: %s\n", circle->corp);

    printf("--- FIM buildCircle ---\n"); */

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