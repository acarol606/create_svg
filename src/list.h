#ifndef LIST_H
#define LIST_H
#include "geo.h"

struct list {
    GCircle *circle;
    GText *text;
    GLine *line;
    GRectangle *rectangle;
    struct list *next;
    struct list *prev;
};

typedef struct list List;

List *createList();
void insertText(List *oldList, List *newTop, GText *text);
void insertLine(List *oldList, List *newTop, GLine *line);
void insertCircle(List *oldList, List *newTop, GCircle *circle);
void insertRectangle(List *oldList, List *newTop, GRectangle *rectangle);
void printList(List *list);

#endif