#include "text.h"
#include <stdio.h>
#include <stdlib.h>

struct text {
    int id;
    double x;
    double y;
    char anchor;
    char *corp;
    char *corb;
    char *value;
};

typedef struct text GText;

Text createText() {
    GText *text = calloc(1, sizeof(GText*));

    return text;
}

Item buildText(FILE *arq, Text vtext, char infos[], char *eptr) {
    printf("--- ENTROU buildText ---\n");

    GText *text = (GText*) vtext;

    fscanf(arq, "%s", infos);
    text->id = atoi(infos);
    
    fscanf(arq, "%s", infos);
    text->x = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    text->y = strtod(infos, &eptr);

    fscanf(arq, "%s", infos);
    text->corb = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(text->corb, infos);

    fscanf(arq, "%s", infos);
    text->corp = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(text->corp, infos);
    
    fscanf(arq, "%s", infos);
    text->anchor = infos[0];

    fscanf(arq, "%s", infos);
    text->value = (char*) malloc(sizeof(char*)+strlen(infos)+1);
    strcpy(text->value, infos);

    

    printf("Id: %d\n", text->id);
    printf("X: %lf\n", text->x);
    printf("Y: %lf\n", text->y);
    printf("Corb: %s\n", text->corb);
    printf("Corp: %s\n", text->corp);
    printf("Ancora: %c\n", text->anchor);
    printf("Valor: %s\n", text->value);

    printf("--- FIM buildText ---\n");


    return text;

}

int getIdText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->id;
}

char getAnchorText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->anchor;
}

double getXText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->x;
}

double getYText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->y;
}

char *getValueText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->value;
}

char *getCorBText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->corb;
}

char *getCorPText(Text *text) {
    GText *gtext = (GText*) text;

    return gtext->corp;
}