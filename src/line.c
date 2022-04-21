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

Item buildLine(FILE *arq, Line vline) {
    printf("--- ENTROU buildLine ---\n");

    char *color;
    int idAux;

    GLine *line = (GLine*) vline;
    
    fscanf(arq, "%d", &idAux);
    line->id = &idAux;
    
    fscanf(arq, "%lf", &line->initX);
    // line->initX = strtod(infos, &eptr);

    fscanf(arq, "%lf", &line->initY);
    // line->initY = strtod(infos, &eptr);
    
    fscanf(arq, "%lf", &line->finalX);
    // line->finalX = strtod(infos, &eptr);

    fscanf(arq, "%lf", &line->finalY);
    // line->finalY = strtod(infos, &eptr);

    fscanf(arq, "%s", color);
    line->color = (char*) malloc(sizeof(char*)+strlen(color)+1);
    strcpy(line->color, color);
    
    line->id = idAux;
    printf("Id: %d\n", line->id);
    printf("initX: %.2lf\n", line->initX);
    printf("initY: %.2lf\n", line->initY);
    printf("finalX: %.2lf\n", line->finalX);
    printf("finalY: %.2lf\n", line->finalY);
    printf("Cor: %s\n", line->color);

    printf("--- FIM buildLine ---\n");

    return line;
}

int getIdLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->id;
}

double getInitXLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->initX;
}

double getInitYLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->initY;
}

double getFinalXLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->finalX;
}

double getFinalYLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->finalY;
}

char *getColorLine(Line *line) {
    GLine *gLine = (GLine*)line;

    return gLine->color;
}