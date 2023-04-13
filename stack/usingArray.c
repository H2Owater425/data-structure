#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
	int* array;
	unsigned long long size;
	unsigned long long index;

	void (*push)(struct Stack*, int);
	int (*pop)(struct Stack*);
	int (*peek)(struct Stack*);
	bool (*isEmpty)(struct Stack*);
	bool (*isFull)(struct Stack*);
	void (*print)(struct Stack*);
} Stack;

bool _isEmpty(Stack* stack) {
	return stack->index == -1;
}

bool _isFull(Stack* stack) {
	return stack->index == stack->size;
}

void _push(Stack* stack, int value) {
	if(!stack->isFull(stack)) {
		stack->array[++(stack->index)] = value;
	}
	
	return;
}

int _pop(Stack* stack) {
	return !stack->isEmpty(stack) ? stack->array[stack->index--] : -1;
}

int _peek(Stack* stack) {
	return stack->index != -1 ? stack->array[stack->index] : -1;
}


void _print(Stack* stack) {
	if(stack->index != -1) {
		for(unsigned long long i = 0; i <= stack->index; i++) {
			printf("%d ", stack->array[i]);
		}
	}

	return;
}

void initializeStack(Stack* stack, unsigned long long size) {
	stack->size = size;
	stack->array = (int*)malloc(size * sizeof(int));
	stack->index = -1;

	stack->push = _push;
	stack->pop = _pop;
	stack->peek = _peek;
	stack->isEmpty = _isEmpty;
	stack->isFull = _isFull;
	stack->print = _print;

	return;
}


int main(void) {
	Stack stack;

	initializeStack(&stack, 10);

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

	printf("%d", stack.pop(&stack));

	return 0;
}