#ifndef LINE_H
#define LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Line;

Item buildLine(char *command, Line line);
Line createLine();

int getIdLine(Line line);
double getInitXLine(Line line);
double getInitYLine(Line line);
double getFinalXLine(Line line);
double getFinalYLine(Line line);
char *getColorLine(Line line);

#endif