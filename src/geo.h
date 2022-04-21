
#ifndef GEO_H
#define GEO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"
#include "svg.h"

int buildGeometricForm(FILE *arq, char *outputDir, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);

#endif