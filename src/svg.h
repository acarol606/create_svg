
#ifndef SVG_H
#define SVG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"

typedef void *LinkAnchor;
typedef void *Anchor;
typedef void *Sel;

void buildSVG(FILE *svgFile, List circle, List rectangle ,List line , List text, List anchorList, List selList, char *type);
void insertSVGAnchor(double x, double y, FILE *svg);
void insertSVGAnchorSelect(double x, double y, FILE *svg);
void createSVGLine(int id, double initX, double initY, double finalX, double finalY, char *color, FILE *svg);
void createSVGRectangle(int id, char *corb, char *corp, double width, double height, double y, double x, FILE *svg);
void createSVGCircle(int id, char *corb, char *corp, double radius, double y, double x, FILE *svg);
void createSVGText(int id, double x, double y, char archor, char *corb, char *corp, char *text, FILE *svg);
void insertFooterSVG(FILE *svg);

Anchor startAnchor();
int getAnchorId(Anchor a);
void setAnchorId(Anchor anchor, int id);
void setAnchorX(Anchor anchor, double x);
void setAnchorY(Anchor anchor, double y);
void setIsSelection(Anchor anchor, int isSelection);

Sel createSel();
void setSelX(Sel s, double x);
void setSelY(Sel s, double y);
void setSelWidth(Sel s, double width);
void setSelHeight(Sel s, double height);

void freeAnchor(Anchor a);
void freeSel(Sel s);

#endif