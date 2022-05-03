#ifndef LIST_H
#define LIST_H

typedef void *List;
typedef void *Item;
typedef void *Cell;

/* Cria uma lista vazia */
List createList();

/* Método responsável por adicionar itens no final da lista */
List *insertItemInFinal(List *list, Item *item);

/* Método responsável por pegar o tamanho atual da lista */
int getSizeList(List *list, char *type);

/* Método responsável por pegar o primeiro item da lista */
Cell getFirst(List list);

/* Método responsável por pegar o proximo item da lista */
Cell getNextCell(Cell cell);

/* Método responsável por pegar o valor do item da lista */
Item getCellValue(Cell cell);

#endif