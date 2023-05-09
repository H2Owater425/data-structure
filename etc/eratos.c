#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
	unsigned long long range;
	bool *isPrimes;

	scanf("%lld", &range);

	isPrimes = (bool*)malloc(sizeof(bool) * (range + 1));

	for(unsigned long long i = 2; i < range; isPrimes[i++] = true);

	for(unsigned long long i = 2; i * i <= range; i++) {
		if(isPrimes[i]) {
			for(unsigned long long j = i * i; j <= range; j += i) {
				isPrimes[j] = false;
			}
		}
	}

	for(unsigned long long i = 2; i <= range; i++) {
		if(isPrimes[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}