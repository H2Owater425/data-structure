#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *previous;
	int value;
} Node;

typedef struct Stack {
	Node *lastNode;
	unsigned long long size;

	void (*push)(struct Stack*, int);
	int (*pop)(struct Stack*);
	int (*peek)(struct Stack*);
	bool (*isEmpty)(struct Stack*);
	bool (*isFull)(struct Stack*);
	void (*print)(struct Stack*);
} Stack;

bool _isEmpty(Stack *stack) {
	return stack->size == 0;
}

void _push(Stack *stack, int value) {
	if(stack->lastNode != (Node*)-1) {
		Node* _lastNode = stack->lastNode;

		stack->lastNode = (Node*)malloc(sizeof(Node));

		stack->lastNode->previous = _lastNode;
	} else {
		stack->lastNode = (Node*)malloc(sizeof(Node));

		stack->lastNode->previous = (Node*)-1;
	}

	stack->lastNode->value = value;

	stack->size++;

	return;
}

int _pop(Stack *stack) {
	if(!stack->isEmpty(stack)) {
		Node *_lastNode = stack->lastNode;
		int value = _lastNode->value;

		stack->lastNode = _lastNode->previous;

		free(_lastNode);

		stack->size--;

		return value;
	} else {
		return -1;
	}
}

int _peek(Stack *stack) {
	return !stack->isEmpty(stack) ? stack->lastNode->value : -1;
}

void _print(Stack *stack) {
	int *values = (int*)malloc(sizeof(int) * stack->size);
	Node *lastNode = stack->lastNode;

	for(int i = 0; i < stack->size; i++) {
		values[i] = lastNode->value;

		lastNode = lastNode->previous;
	}

	for(int i = stack->size - 1; i != -1; i--) {
		printf("%d ", values[i]);
	}

	return;
}

void initializeStack(Stack *stack) {
	stack->size = 0;

	stack->push = _push;
	stack->pop = _pop;
	stack->peek = _peek;
	stack->isEmpty = _isEmpty;
	stack->print = _print;

	return;
}

int main(void) {
	Stack stack;

	initializeStack(&stack);

	for(int i = 0; i < 10; i++) {
		stack.push(&stack, i);

		stack.print(&stack);

		puts("");
	}

	for(int i = 0; i < 10; i++) {
		stack.pop(&stack);

		stack.print(&stack);

		puts("");
	}

	printf("%d\n", stack.pop(&stack));

	return 0;
}