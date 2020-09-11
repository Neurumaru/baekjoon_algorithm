#include <stdio.h>

int main(void) {
	int A, B;
	while(scanf("%d %d", &A, &B), A != 0 || B != 0)
		printf("%d\n", A+B);
}