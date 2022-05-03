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

<<<<<<< HEAD
/* 
    Método responsável por ler o arquivo qry e executar seus comandos 
 */
void queryCommands(FILE *txtFile, FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);
=======
void queryCommands(FILE *newSVG, FILE *readSVG, FILE *txtFile, FILE *qryFile, int capacity, List circleList, List rectangleList, List lineList, List textList, FILE *svgFile);
>>>>>>> f70074aa9d7760fb6a431c7a2dd9c79e0a133a1c

#endif