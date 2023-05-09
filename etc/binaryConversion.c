#include <stdio.h>

int main(void) {
	unsigned long long input;
	unsigned int outputIndex = 0;
	char output[64] = {-1};

	scanf("%d", &input);

	while(input != 0) {
		if(input % 2) {
			output[outputIndex++] = '1';
		}

		input /= 2;
	}

	for(int i = 63; i != -1; i--) {


		putchar(output[i]);
	}

	return 0;
}