#ifndef QRY_H
#define QRY_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"
#include "svg.h"

void queryCommands(List selList, List anchorList, FILE* txtFile, FILE* qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList);

#endif