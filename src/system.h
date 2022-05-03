#ifndef SYSTEM_H
#define SYSTEM_H
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "files.h"

typedef void* Parameters;

/* Método responsável por pegar os argumentos e passar para uma variavel do tipo Parameters */
Parameters *createParameters();

/* Constroi o caminho para o arquivo geo */
char *makePathGeoFile(Parameters p);

/* Constroi o caminho para o arquivo qry */
char *makePathQryFile(Parameters p);

/* Recupera o nome do arquivo qry */
char *getQryName(Parameters p);

/* Recupera o diretório de saida com o nome do arquivo svg */
char *getOutputDir(Parameters p, char *extention);

/* Recupera o diretório de saida com o nome do arquivo txt */
char *getOutputDir2(Parameters p, char *extention);

#endif