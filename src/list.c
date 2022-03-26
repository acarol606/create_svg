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

    ListL *list = (ListL *) malloc(1*sizeof(ListL*));
    list->init = NULL;
    list->final = NULL;
    return list;
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
    printf("--- ENTROU NO INSERT ITEM ---\n");
    ListL *localList = (ListL*) list;

    Data *newData = (Data*) malloc(sizeof(Data));
    newData->next = NULL;
    newData->prev = NULL;
    newData->value = item;

    if(localList->init == NULL) { // Valida se a lista está vazia, caso estiver o item passado será o inicio
        localList->init = newData;
        localList->final = NULL;

    } else if (localList->final == NULL) { // Valida se o final da lista está preenchido, caso não preencher com o item que está passando por parâmetro
        newData->prev = localList->init;
        newData->next = NULL;
        
        localList->final = newData;

    } else { // Caso a lista já tenha inicio e fim, adiciona o novo item no final da lista
        

        Data *prevData = getPreviusData(localList);

        newData->prev = prevData;

        prevData->next = newData;

        localList->final = newData;

    }
    
    return localList;
}

void printSizeList(List *list) {
    printf("--- ENTROU NO PRINT ---\n");
    ListL *localList = (ListL*) list;
    Data *data = localList->init;

    while(data != NULL) {
        printf("%p\n", data);
        data = data->next;
    }
}