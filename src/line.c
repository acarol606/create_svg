#include "line.h"
#include <stdio.h>

struct line {
    int id;
    double initX;
    double initY;
    double finalX;
    double finalY;
    char *color;
};

typedef struct line GLine;

Line createLine() {
    GLine *line = calloc(1, sizeof(GLine));

    return line;
}

Item buildLine(char *command, Line vline) {
    // printf("--- ENTROU buildLine ---\n");

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");

    char *eptr;

    GLine *line = (GLine*) vline;
    
    line->id = atoi(ptr);
    ptr = strtok(NULL, " ");
    
    line->initX = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    line->initY = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");
    
    line->finalX = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    line->finalY = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    line->color = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(line->color, ptr);
    
    /* printf("Id: %d\n", line->id);
    printf("initX: %.2lf\n", line->initX);
    printf("initY: %.2lf\n", line->initY);
    printf("finalX: %.2lf\n", line->finalX);
    printf("finalY: %.2lf\n", line->finalY);
    printf("Cor: %s\n", line->color);

    printf("--- FIM buildLine ---\n"); */

    return line;
}

int getIdLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->id;
}

double getInitXLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->initX;
}

double getInitYLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->initY;
}

double getFinalXLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->finalX;
}

double getFinalYLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->finalY;
}

char *getColorLine(Line line) {
    GLine *gLine = (GLine*)line;

    return gLine->color;
}