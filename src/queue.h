#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef void *Queue;

Queue createQueue(int capacity);
void queueRemove(Queue q);
void clearQueue(Queue q);
void insertQueue(Queue q, int value);
bool queueIsEmpty(Queue q);
bool queueIsFull(Queue q);
int getCapacity(Queue queue);
bool hasNext(Queue queue, int index);
int getData(Queue queue, int index);

#endif