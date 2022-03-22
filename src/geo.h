#ifndef GEO_H
#define GEO_H

#include <stdlib.h>
#include <stdio.h>

struct circle {
    char type;
    int id;
    double x;
    double y;
    double radius;
    char *corp;
    char *corb;
};

typedef struct circle GCircle;

struct text {
    char type;
    int id;
    float x;
    float y;
    char anchor;
    char *corp;
    char *corb;
    char *text;
};

typedef struct text GText;

struct line {
    char type;
    int id;
    float initX;
    float initY;
    float finalX;
    float finalY;
    char *color;
};

typedef struct line GLine;

struct rectangle {
    char type;
    int id;
    float x;
    float y;
    float width;
    float height;
    char *corb;
    char *corp;
};

typedef struct rectangle GRectangle;

void buildCircle(FILE *arq, GCircle *circle, char infos[], char *eptr);
GCircle *createGCircleEmpty();

#endif