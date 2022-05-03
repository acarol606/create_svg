#ifndef LINE_H
#define LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Line;

/* Constroi a linha lida no geo file em código para armazenar na lista */
Item buildLine(char *command, Line line);

/* Cria um tipo linha vazia */
Line createLine();

/* Recupera o ID da linha */
int getIdLine(Line line);

/* Recupera o x inicial da linha */
double getInitXLine(Line line);

/* Recupera o y inicial da linha */
double getInitYLine(Line line);

/* Recupera o x final da linha */
double getFinalXLine(Line line);

/* Recupera o y final da linha */
double getFinalYLine(Line line);

/* Recupera a cor da linha */
char *getColorLine(Line line);

#endif