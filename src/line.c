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

Item buildLine(FILE *arq, Line vline, char infos[], char *eptr) {
    printf("--- ENTROU buildLine ---\n");

    GLine *line = (GLine*) vline;

    fscanf(arq, "%s", infos);
    line->id = atoi(infos);
    
    fscanf(arq, "%s", infos);
    line->initX = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    line->initY = strtod(infos, &eptr);
    
    fscanf(arq, "%s", infos);
    line->finalX = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    line->finalY = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    line->color = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(line->color, infos);

    

    printf("Id: %d\n", line->id);
    printf("initX: %lf\n", line->initX);
    printf("initY: %lf\n", line->initY);
    printf("finalX: %lf\n", line->finalX);
    printf("finalY: %lf\n", line->finalY);
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