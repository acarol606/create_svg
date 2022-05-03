#ifndef FILES_H
#define FILES_H

/* Abre um arquivo que estiver no parametro */
FILE *loadFile(char path[]);

/* Abre um arquivo no modo escrita para criar o svg */
FILE *createSVG();

/* Monta o caminho dos arquivos de input*/
char *buildFilePath(char *directory, char *fileName);

#endif