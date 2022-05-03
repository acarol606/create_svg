
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

/* 
    Com base no arquivo geo, esse método percorre
     todo arquivo transformando as linhas do arquivo em código,
     após isso gera o svg com as informações obtidas e adicionadas nas listas.
 */
int buildGeometricForm(FILE *svgFileClean, FILE *arq, char *outputDir, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);

#endif