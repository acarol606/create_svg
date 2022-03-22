#include "list.h"
#include "geo.h"
#include <stdio.h>

List *createList() {
    List *list = (List *) malloc(1*sizeof(List*));
    list->circle = NULL;
    list->rectangle = NULL;
    list->text = NULL;
    list->line = NULL;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void insertCircle(List *oldList, List *newTop, GCircle *circle) {

    newTop->circle = circle;
    newTop->next = NULL;
    newTop->prev = oldList;

    oldList->next = newTop;
}

void insertRectangle(List *oldList, List *newTop, GRectangle *rectangle) {

    newTop->rectangle = rectangle;
    newTop->next = NULL;
    newTop->prev = oldList;

    oldList->next = newTop;
}

void insertText(List *oldList, List *newTop, GText *text) {

    newTop->text = text;
    newTop->next = NULL;
    newTop->prev = oldList;

    oldList->next = newTop;
}

void insertLine(List *oldList, List *newTop, GLine *line) {

    newTop->line = line;
    newTop->next = NULL;
    newTop->prev = oldList;

    oldList->next = newTop;
}

void printList(List *list) {

    printf("\n");
    while(list!=NULL) {
        if(list->circle != NULL) {

            printf("Type: %c\n", list->circle->type);    
            printf("Id: %d\n", list->circle->id);
            printf("Pos X: %.2lf\n", list->circle->x);
            printf("Pos Y: %.2lf\n", list->circle->y);
            printf("Radius: %.2lf\n", list->circle->radius);
            printf("Border color: %s\n", list->circle->corb);
            printf("Fill color: %s\n", list->circle->corp);

        } else if(list->rectangle != NULL) {

            printf("Type: %c\n", list->rectangle->type);    
            printf("Id: %d\n", list->rectangle->id);
            printf("Pos X: %.2lf\n", list->rectangle->x);
            printf("Pos Y: %.2lf\n", list->rectangle->y);
            printf("Width: %.2lf\n", list->rectangle->width);
            printf("Height: %.2lf\n", list->rectangle->height);
            printf("Border color: %s\n", list->rectangle->corb);
            printf("Fill color: %s\n", list->rectangle->corp);

        }
        printf("\n");
        list=list->next;
    }
}
