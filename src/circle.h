#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Circle;

Item buildCircle(FILE *arq, Circle circle, char infos[], char *eptr);
Circle createCircle();

int getIdCircle(Circle circle); 
char *getCorBCircle(Circle circle);
char *getCorPCircle(Circle circle);
double getXCircle(Circle circle);
double getYCircle(Circle circle);
double getRadiusCircle(Circle circle);

#endif