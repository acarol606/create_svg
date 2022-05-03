#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Circle;

/* Constroi o circulo no formato de código */
Item buildCircle(char *command, Circle circle);

/* Cria um circulo vazio */
Circle createCircle();

/* Recupera o ID do circulo */
int getIdCircle(Circle circle);

/* Recupera a cor da borda do circulo */
char *getCorBCircle(Circle circle);

/* Recupera a cor do preenchimento do circulo */
char *getCorPCircle(Circle circle);

/* Recupera a coordenada x do circulo */
double getXCircle(Circle circle);

/* Recupera a coordenada y do circulo */
double getYCircle(Circle circle);

/* Recupera o raio do circulo */
double getRadiusCircle(Circle circle);

#endif