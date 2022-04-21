#ifndef QRY_H
#define QRY_H
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"
#include "svg.h"

void queryCommands(FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);

#endif