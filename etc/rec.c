#include <stdio.h>

void r(int n) {
	if(n > 0) {
		r(n - 1);
		printf("%d\n", n);
		r(n - 2);
	}

	return;
}

int main(void) {
	r(4);

	return 0;
}
