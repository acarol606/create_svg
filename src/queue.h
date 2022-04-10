#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "list.h"

typedef void *Queue;

Queue createQueue(int capacity);
bool queueRemove(Queue q);
bool insertQueue(Queue q, int value);
bool queueIsEmpty(Queue q);
bool queueIsFull(Queue q);

#endif