#ifndef FILES_H
#define FILES_H

FILE *loadFile(char path[]);
FILE *createSVG();

char *buildFilePath(char *directory, char *fileName);

#endif