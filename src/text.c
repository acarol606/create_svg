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
    GText *text = calloc(1, sizeof(GText));

    return text;
}

Item buildText(char *command, Text vtext) {
    // printf("--- ENTROU buildText --- command: %s\n", command);

    GText *text = (GText*) vtext;

    char *ptr = strtok(command, " ");
    ptr = strtok(NULL, " ");
    
    char *eptr;

    text->id = atoi(ptr);
    ptr = strtok(NULL, " ");
    printf("Id: %d\n", text->id);
    
    text->x = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");
    printf("X: %lf\n", text->x);

    text->y = strtod(ptr, &eptr);
    ptr = strtok(NULL, " ");

    text->corb = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(text->corb, ptr);
    ptr = strtok(NULL, " ");

    text->corp = (char*) malloc(sizeof(char*)+strlen(ptr)+1);
    strcpy(text->corp, ptr);
    ptr = strtok(NULL, " ");
    
    text->anchor = ptr[0];
    ptr = strtok(NULL, " ");

    text->value = (char*) malloc(sizeof(char*)+ 20*10);
    strcpy(text->value, ptr);

    while(ptr != NULL) {
        strcat(text->value, " ");
        strcat(text->value, ptr);
        ptr = strtok(NULL, " ");
    }

   /* 
    printf("Y: %lf\n", text->y);
    printf("Corb: %s\n", text->corb);
    printf("Corp: %s\n", text->corp);
    printf("Ancora: %c\n", text->anchor);
    printf("Valor: %s\n", text->value);

    printf("--- FIM buildText ---\n"); 
    
    */


    return text;

}

int getIdText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->id;
}

char getAnchorText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->anchor;
}

double getXText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->x;
}

double getYText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->y;
}

char *getValueText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->value;
}

char *getCorBText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->corb;
}

char *getCorPText(Text text) {
    GText *gtext = (GText*) text;

    return gtext->corp;
}