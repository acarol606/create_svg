
#ifndef SVG_H
#define SVG_H
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include "text.h"

/* 
    Método responsável por gerar o svg baseado nas listas populadas anteriomente
 */
void buildSVG(FILE *svgFileClean, FILE *svgFile, List circle, List rectangle ,List line , List text);

/* Método responsável por adicionar ancora no svg */
void insertSVGAnchor(double x, double y, FILE *svg);

/* Método responsável por adicionar seleção da ancora no svg */
void insertSVGAnchorSelect(double x, double y, FILE *svg);

/* Método responsável por adicionar uma linha no svg */
void createSVGLine(int id, double initX, double initY, double finalX, double finalY, char *color, FILE *svg);

#endif