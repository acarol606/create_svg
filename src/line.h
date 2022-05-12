#ifndef LINE_H
#define LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Line;

Item buildLine(char *command, Line line);
Item buildLineParameters(Line vline, int id, double initX, double initY, double finalX, double finalY, char *corb);
Line createLine();

int getIdLine(Line line);
double getInitXLine(Line line);
double getInitYLine(Line line);
double getFinalXLine(Line line);
double getFinalYLine(Line line);
char *getColorLine(Line line);
void freeLine(Line l);

#endif