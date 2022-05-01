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
	printf("-- Entrou createQueue --\n");
    LQueue *q = calloc(1, sizeof(LQueue));

	q->capacity = capacity;
	q->data = malloc(sizeof(int) * capacity);
	q->first = 0;
	q->last = -1;
	q->totalItems = 0; 

    return q;
}

bool hasNext(Queue queue, int index) {
	LQueue *q = (LQueue*) queue;

	if(q->totalItems==index+1) {
		return false;
	}

	return true;
}

bool isFinal(Queue queue, int index) {
	LQueue *q = (LQueue*) queue;

	if(q->totalItems==index) {
		return false;
	}

	return true;
}

int getData(Queue queue, int index) {
	LQueue *q = (LQueue*) queue;

	return q->data[index];
}

int getSizeQueue(Queue queue) {
	LQueue *q = (LQueue*) queue;

	return q->totalItems;
}

void insertQueue(Queue queue, int value) {
    LQueue *q = (LQueue*) queue;

	if(queueIsFull(q)) {
		printf("Fila está cheia!");
        return;
    }

	q->last++;
	q->data[q->last] = value; // incrementa ultimo e insere
	q->totalItems++; // mais um item inserido
}

void queueRemove(Queue queue) { // pega o item do comeÃ§o da fila
    LQueue *q = (LQueue*) queue;
	LQueue *temp = q->data[q->first++]; // pega o valor e incrementa o primeiro

	q->totalItems--;  // um item retirado
}

void clearQueue(Queue queue) {
	LQueue *q = (LQueue*) queue;

	free(q->data); // limpa dados da fila
	q->totalItems = 0;
}

bool queueIsEmpty(Queue queue) { // retorna verdadeiro se a fila estÃ¡ vazia
    LQueue *q = (LQueue*) queue;
	return (q->totalItems==0);

}

bool queueIsFull(Queue queue) { // retorna verdadeiro se a fila estÃ¡ cheia
    LQueue *q = (LQueue*) queue;
	return (q->totalItems == q->capacity);
}