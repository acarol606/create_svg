#ifndef LIST_H
#define LIST_H

typedef void *List;
typedef void *Item;

List *createList();
List *insertItem(List *list, Item item);

void printList(List *list);

#endif