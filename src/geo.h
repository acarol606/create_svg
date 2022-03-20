#ifndef GEO_H
#define GEO_H
#include <stdlib.h>

struct circle {
    char id;
    float x;
    float y;
    float radius;
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
    float radius;
    char *corp;
    char *corb;
};

typedef struct rectangle GRectangle;


#endif