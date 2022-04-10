#include "queue.h"

struct queue {

	int capacity;
	int *data;
	int first;
	int last;
	int totalItems; 
};

typedef struct queue LQueue;

Queue createQueue(int capacity) { 
    LQueue *q = calloc(1, sizeof(LQueue));

	q->capacity = capacity;
	q->data = malloc(sizeof(int) * q->capacity);
	q->first = 0;
	q->last = -1;
	q->totalItems = 0; 

    return q;
}

bool insertQueue(Queue queue, int value) {
    LQueue *q = (LQueue*) queue;

	if(queueIsFull(q)) {
        return false;
    }

	q->last++;
	q->data[q->last] = value; // incrementa ultimo e insere
	q->totalItems++; // mais um item inserido

    return true;
}

bool queueRemove(Queue queue) { // pega o item do comeÃ§o da fila
    LQueue *q = (LQueue*) queue;
	LQueue *temp = q->data[q->first++]; // pega o valor e incrementa o primeiro

	if(queueIsEmpty(q)) {
		return false;
    }

	q->totalItems--;  // um item retirado
	return true;

}

bool queueIsEmpty(Queue queue) { // retorna verdadeiro se a fila estÃ¡ vazia
    LQueue *q = (LQueue*) queue;
	return (q->totalItems==0);

}

bool queueIsFull(Queue queue) { // retorna verdadeiro se a fila estÃ¡ cheia
    LQueue *q = (LQueue*) queue;
	return (q->totalItems == q->capacity);
}