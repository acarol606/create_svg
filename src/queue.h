#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef void *Queue;

/* Cria fila encadeada vazia */
Queue createQueue(int capacity);

/* Remove ultima ancora adicionada na fila */
void queueRemove(Queue q);

/* Remove todas as ancoras da fila */
void clearQueue(Queue q);

/* Insere mais uma ancora na fila */
void insertQueue(Queue q, int value);

/* Verifica se a fila está vazia */
bool queueIsEmpty(Queue q);

/* Verifica se a fila está cheia */
bool queueIsFull(Queue q);

/* Verifica se é a ultima ancora da fila */
bool isFinal(Queue queue, int index);

/* Verifica se tem ancora posterior a atual  */
bool hasNext(Queue queue, int index);

/* Recupera o valor da ancora adicionada */
int getData(Queue queue, int index);

/* Recupera o tamanho da fila (Quantidade de elementos na fila) */
int getSizeQueue(Queue queue);

/* Recupera a ultima ancora da fila */
int getLast(Queue queue);

#endif