#include <stdio.h>

char stack[100];
int stackIndex = -1;

void push(char value) {
	stack[++stackIndex] = value;
}

int isEmpty() {
	return stackIndex == -1;
}

int pop() {
	return !isEmpty() ? stack[stackIndex--] : -1;
}

int peek() {
	return !isEmpty() ? stack[stackIndex] : -1;
}

int main(void) {
	char input[100] = {0};
	char result[100] = {0};
	unsigned int resultIndex = 0;

	scanf("%s", &input);
	
	for(int i = 0; input[i]; i++) {
		switch(input[i]) {
			case '(': {
				push(input[i]);

				break;
			}

			case ')': {
				while(!isEmpty() && peek() != '(') {
					result[resultIndex++] = pop();
				}

				pop();

				break;
			}

			case '*':
			case '/': {
				while(!isEmpty() && (peek() == '*' || peek() =='/')) {
					result[resultIndex++] = pop();
				}

				push(input[i]);

				break;
			}

			case '+':
			case '-': {
				while(!isEmpty() && peek() != '(') {
					result[resultIndex++] = pop();
				}

				push(input[i]);
				
				break;
			}

			default: {
				result[resultIndex++] = input[i];

				break;
			}
		}
	}

	while(!isEmpty()) {
		result[resultIndex++] = pop();
	}

	printf("%s", result);

	return 0;
}