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

/* 
    Método responsável por ler o arquivo qry e executar seus comandos 
 */
void queryCommands(FILE *txtFile, FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);

#endif