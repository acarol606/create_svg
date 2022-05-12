#ifndef LIST_H
#define LIST_H

typedef void *List;
typedef void *Item;
typedef void *Cell;

List createList();
List *insertItemInFinal(List *list, Item *item);
int getSizeList(List *list, char *type);
Cell getFirst(List list);
Cell getNextCell(Cell cell);
Item getCellValue(Cell cell);
void freeItem(Item item);
void freeList(List l);
List reallocSize(List l);

#endif