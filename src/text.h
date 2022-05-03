#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Text;

/* Constroi o texto no formato de código */
Item buildText(char *command, Text text);

/* Cria texto vazio */
Text createText();

/* Recupera o ID do texto */
int getIdText(Text text);

/* Recupera a ancora do texto */
char getAnchorText(Text text);

/* Recupera o x do texto */
double getXText(Text text);

/* Recupera o y do texto */
double getYText(Text text);

/* Recupera o valor do texto */
char *getValueText(Text text);

/* Recupera a cor da borda do texto */
char *getCorBText(Text text);

/* Recupera a cor do preenchimento do texto */
char *getCorPText(Text text);

#endif