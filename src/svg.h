
#ifndef SVG_H
#define SVG_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"

void buildSVG(FILE *svgFile, List circle, List rectangle ,List line , List text);
void insertSVGAnchor(double x, double y, FILE *svg);
void insertSVGAnchorSelect(double x, double y, FILE *svg);
void createSVGLine(int id, double initX, double initY, double finalX, double finalY, char *color, FILE *svg);
void createSVGCircle(int id, char *corb, char *corp, double radius, double y, double x, FILE *svg);

#endif