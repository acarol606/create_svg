#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Rectangle;

Item buildRectangle(FILE *arq, Rectangle rectangle, char infos[], char *eptr);
Rectangle createRectangle();

int getIdRectangle(Rectangle *rectangle);
char *getCorBRectangle(Rectangle *rectangle);
char *getCorPRectangle(Rectangle *rectangle);
double getXRectangle(Rectangle *rectangle);
double getYRectangle(Rectangle *rectangle);
double getWidthRectangle(Rectangle *rectangle);
double getHeightRectangle(Rectangle *rectangle);

#endif