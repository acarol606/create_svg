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

List *createList() {

    ListL *list = (ListL *) malloc(1*sizeof(ListL*));
    list->init = NULL;
    list->final = NULL;
    return list;
}

List *insertItem(List *list, Item item) {
    ListL *localList = (ListL*) list;
    Data *data = (Data*) item;

    if(localList->init == NULL) { // Valida se a lista está vazia, caso estiver o item passado será o inicio
        localList->init = data;
        localList->final = NULL;

    } else if (localList->final == NULL) { // Valida se o final da lista está preenchido, caso não preencher com o item que está passando por parâmetro
        data->prev = localList->init;
        data->next = NULL;
        
        localList->final = data;

    } else { // Caso a lista já tenha inicio e fim, adiciona o novo item no final da lista
        Data *prev = localList->final;

        prev->next = data;

        data->prev = prev;
        data->next = NULL;

        localList->final = data;

    }
    
    return localList;
}