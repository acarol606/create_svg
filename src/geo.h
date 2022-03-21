#ifndef GEO_H
#define GEO_H
#include <stdlib.h>

struct circle {
    int id;
    double x;
    double y;
    double radius;
    char *corp;
    char *corb;
};

typedef struct circle GCircle;

struct text {
    char id;
    float x;
    float y;
    char anchor;
    char *corp;
    char *corb;
    char *text;
};

typedef struct text GText;

struct line {
    char id;
    float initX;
    float initY;
    float finalX;
    float finalY;
    char *color;
};

typedef struct line GLine;

struct rectangle {
    char id;
    float x;
    float y;
    float width;
    float height;
    char *corb;
    char *corp;
};

typedef struct rectangle GRectangle;

struct list {
    GCircle *circle;
    GText *text;
    GLine *line;
    GRectangle *rectangle;
    struct list *next;
};

typedef struct list List;

void buildCircle(FILE *arq, GCircle *circle, char infos[], char *eptr);
GCircle *createGCircleEmpty();

#endif