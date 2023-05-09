#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue {
	unsigned long long size;
	unsigned long long maximum;
	int front;
	int rear;
	int* array;


	bool (*isFull)(struct Queue *);
	bool (*isEmpty)(struct Queue *);
	void (*enqueue)(struct Queue *, int value);
	int (*dequeue)(struct Queue *);
	int (*peek)(struct Queue *);
	void (*print)(struct Queue *);
} Queue;

bool _isFull(Queue* queue) {
	return queue->size == queue->maximum;
}

bool _isEmpty(Queue* queue) {
	return queue->size == 0;
}

void _enqueue(Queue* queue, int value) {
	if(!queue->isFull(queue)) {
		queue->size++;
		queue->array[queue->rear++] = value;
	}

	return;
}

int _dequeue(Queue* queue) {
	if(!queue->isEmpty(queue)) {
		queue->size--;

		return queue->array[queue->front++];
	} else {
		return -1;
	}
}

int _peek(Queue* queue) {
	return !queue->isEmpty(queue) ? queue->array[queue->front] : -1;
}

void _print(Queue* queue) {
	for (int i = queue->front; i < queue->rear; i++) {
		printf("%d ", queue->array[i]);
	}

	puts("");

	return;
}

void initializeQueue(Queue* queue, unsigned long long size) {
	queue->size = 0;
	queue->front = 0;
	queue->rear = 0;
	queue->maximum = size;
	queue->array = (int *)malloc(sizeof(int) * size);

	queue->isFull = _isFull;
	queue->isEmpty = _isEmpty;
	queue->enqueue = _enqueue;
	queue->dequeue = _dequeue;
	queue->peek = _peek;
	queue->print = _print;

	return;
}

int main(void) {
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	initializeQueue(queue, 10);

	for(int i = 0; i < 10; i++) {
		queue->enqueue(queue, i);

		queue->print(queue);
	}

	
	for(int i = 0; i < 10; i++) {
		queue->dequeue(queue);

		queue->print(queue);
	}

	return 0;
}