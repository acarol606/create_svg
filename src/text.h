#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef void *Text;

Item buildText(FILE *arq, Text text);
Text createText();

int getIdText(Text text); 
char getAnchorText(Text text);
double getXText(Text text);
double getYText(Text text);
char *getValueText(Text text);
char *getCorBText(Text text);
char *getCorPText(Text text);

#endif