#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Rectangle;

Item buildRectangle(char *command, Rectangle rectangle);
Item buildRectangleParameters(Rectangle vrectangle, int id, char *corb, char *corp, double width, double height, double y, double x);
Rectangle createRectangle();

int getIdRectangle(Rectangle *rectangle);
char *getCorBRectangle(Rectangle *rectangle);
char *getCorPRectangle(Rectangle *rectangle);
double getXRectangle(Rectangle *rectangle);
double getYRectangle(Rectangle *rectangle);
double getWidthRectangle(Rectangle *rectangle);
double getHeightRectangle(Rectangle *rectangle);
void freeRectangle(Rectangle r);

#endif