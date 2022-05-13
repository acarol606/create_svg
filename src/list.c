#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct data {
    Item value;
    struct data *next;
    struct data *prev;
};
typedef struct data Data;


struct list {
    struct Data *init;
    struct Data *final;
};
typedef struct list ListL;

List createList() {

    ListL *list = (ListL *) malloc(1*sizeof(ListL));
    list->init = NULL;
    list->final = NULL;
    return list;
}



void removeElement(List l, Item i) {

    ListL* list = (ListL*) l;
    Data* cell = (Data*) i;
    Data* auxPrev = cell->prev;

    if (cell == list->init) {

        list->init = NULL;

    } else if (cell == list->final) {

        list->final = NULL;

    } else {

        auxPrev->next = cell->next; // 1 0 8 // 1 8
        cell->next->prev = auxPrev;

    }

    free(cell);
}

Data *getPreviusData(ListL *list) {
    Data *data = list->init;

    while(data != NULL) {

        if (data->next == NULL) {
            return data;
        }

        data = data->next;
    }

    return data;
}

List *insertItemInFinal(List *list, Item *item) {

    ListL *localList = (ListL*) list;
    Data *newData = (Data*) malloc(sizeof(Data)*1);
    newData->next = NULL;
    newData->prev = NULL;
    newData->value = item;

    if(localList->init == NULL) { // Valida se a lista está vazia, caso estiver o item passado será o inicio
        printf("Lista vazia\n");
        localList->init = newData;
        localList->final = newData;

    } else { // Caso a lista já tenha inicio e fim, adiciona o novo item no final da lista
        

        Data *prevData = getPreviusData(localList);
        newData->prev = prevData;

        prevData->next = newData;

        localList->final = newData;

    }

    return localList;
}

Cell getNextCell(Cell cell) {
    Data *data = (Data*) cell;

    if(data == NULL) {
        return NULL;
    }

    return data->next;
}

Cell getFirst(List list) {
    ListL *localList = (ListL*) list;
    if (localList==NULL) {
        return NULL;
    }
    
    return localList->init;
}

Item getCellValue(Cell cell) {
    Data *data = (Data*)cell;

    return data->value;
}

int getSizeList(List *list, char *type) {
    ListL *localList = (ListL*) list;

    if (localList == NULL) {
        printf("Lista com %d elementos na lista de %s.\n", 0, type);
        return 0;
    }
    
    Data *aux = localList->init;
    int counter = 0;

    while (aux != NULL){

        counter++;
        aux = (Data*) getNextCell(aux);
    }

    printf("\nLista com %d elementos na lista de %s.\n", counter, type);
    return counter;
}

void freeList(List l) {
    
    if (sizeof(l)==sizeof(ListL*)) {
        printf("funciona\n\n");
    }
    
    Cell cell = getFirst(l);
    Cell removedcell;

    // percorrendo a lista e dando free em todas as células
    while (cell != NULL) {

        removedcell = cell;
        cell = getNextCell(cell);
        free(removedcell);
    }
    free(l);
    // depois de ter liberado todas as células, libera a lista
}