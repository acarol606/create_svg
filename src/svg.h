#include <stdio.h>
#include <stdlib.h>

#ifndef SVG_H
#define SVG_H

void insertHeaderSVG(FILE *svg);
void insertFooterSVG(FILE *svg);
void createSVGCircle(char *corb, char *corp, double radius, double y, double x, FILE *svg);
void createSVGRectangle(char *corb, char *corp, double width, double height, float y, float x, FILE *svg);
 
#endif