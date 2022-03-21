#include <stdio.h>
#include <string.h>
#include "geo.h"

void buildGeometricForm(FILE *arq) {

    GCircle *circle = calloc(1, sizeof(GCircle*));
    GRectangle *rectangle = calloc(1, sizeof(GRectangle*));

    while(!feof(arq)) {

        char infos[10];
        char *eptr;
        fscanf(arq, "%s", infos);

        
        if (infos[0] == 'c' && infos[1] == NULL) {

            printf("Type: %s\n", infos);    

            buildCircle(arq, circle, infos, eptr);

            printf("Id: %d\n", circle->id);
            printf("Pos X: %.2lf\n", circle->x);
            printf("Pos Y: %.2lf\n", circle->y);
            printf("Radius: %.2lf\n", circle->radius);
            printf("Border color: %s\n", circle->corb);
            printf("Fill color: %s\n", circle->corp);

        } else if(infos[0] == 'r' && infos[1] == NULL) {

            printf("Type: %s\n", infos);    

            buildRectangle(arq, rectangle, infos, eptr);
            
            printf("Id: %d\n", rectangle->id);
            printf("Pos X: %.2lf\n", rectangle->x);
            printf("Pos Y: %.2lf\n", rectangle->y);
            printf("Width: %.2lf\n", rectangle->width);
            printf("Height: %.2lf\n", rectangle->height);
            printf("Border color: %s\n", rectangle->corb);
            printf("Fill color: %s\n", rectangle->corp);
            
           
        }
        printf("*****************************************************\n");
    }
}

void buildRectangle(FILE *arq, GRectangle *rectangle, char infos[], char *eptr) {

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->id = atoi(infos);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->x = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->y = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->width = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->height = strtod(infos, &eptr);

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corb = infos;

      strcpy(infos, "");
      fscanf(arq, "%s", infos);
      rectangle->corp = infos;

      strcpy(infos, "");
}

void buildCircle(FILE *arq, GCircle *circle, char infos[], char *eptr) {

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->id = atoi(infos);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->x = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->y = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->radius = strtod(infos, &eptr);

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corb = infos;

    strcpy(infos, "");
    fscanf(arq, "%s", infos);
    circle->corp = infos;

    strcpy(infos, "");
}