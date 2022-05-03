#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Rectangle;

/* Constroi o retangulo no formato de código */
Item buildRectangle(char *command, Rectangle rectangle);

/* Cria retangulo vazio */
Rectangle createRectangle();

/* Recupera ID do retangulo */
int getIdRectangle(Rectangle *rectangle);

/* Recupera cor da borda do retangulo */
char *getCorBRectangle(Rectangle *rectangle);

/* Recupera cor de preenchimento do retangulo */
char *getCorPRectangle(Rectangle *rectangle);

/* Recupera x do retangulo */
double getXRectangle(Rectangle *rectangle);

/* Recupera y do retangulo */
double getYRectangle(Rectangle *rectangle);

/* Recupera a largura do retangulo */
double getWidthRectangle(Rectangle *rectangle);

/* Recupera a altura do retangulo */
double getHeightRectangle(Rectangle *rectangle);

#endif