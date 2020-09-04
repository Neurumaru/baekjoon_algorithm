#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, *C, i, j, k, n, m;
	
	scanf("%d %d", &N, &M);
	C = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &C[i]);
	
	for(n = 0, i = 0; i < N-2; i++) {
		for(j = i+1; j < N-1; j++) {
			for(k = j+1; k < N; k++) {
				m = C[i] + C[j] + C[k];
				if(m <= M && n < m)
					n = m;
			}
		}
	}
	
	printf("%d\n", n);
	
	return 0;
}
