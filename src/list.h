#ifndef LIST_H
#define LIST_H

typedef void *List;
typedef void *Item;

List createList();
List *insertItemInFinal(List *list, Item *item);
void printSizeList(List *list);

#endif