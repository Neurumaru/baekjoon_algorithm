#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, V, i, j, k;
	int **r;
	int *data, *S;
	int start, end;
	
	scanf("%d %d %d", &N, &M, &V);
	
	data = (int *)malloc(sizeof(int) * N);
	S = (int *)malloc(sizeof(int) * (N + 1));
	r = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 1; i <= N; i++) {
		r[i] = (int *)malloc(sizeof(int) * (N + 1));
		for(j = 1; j <= N; j++) r[i][j] = 0;
	}
	
	for(i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		r[j][k] = r[k][j] = 1;
	}
	
	data[0] = V;
	start = 0; end = 1;
	for(i = 1; i <= N; i++) S[i] = 0;
	S[V] = 1;
	printf("%d ", V);
	while(start != end) {
		k = data[end-1];
		for(i = 1; i <= N; i++) {
			if(r[k][i] == 1 && S[i] == 0) {
				S[i] = 1;
				data[end++] = i;
				printf("%d ", i);
				break;
			}
		}
		if(data[end-1] == k)	end--;
	}
	
	printf("\n");
	
	data[0] = V;
	start = 0; end = 1;
	for(i = 1; i <= N; i++) S[i] = 0;
	S[V] = 1;
	printf("%d ", V);
	while(start < end) {
		k = data[start++];
		for(i = 1; i <= N; i++)
			if(r[k][i] == 1 && S[i] == 0) {
				S[i] = 1;
				data[end++] = i;
				printf("%d ", i);
			}
	}
	
	return 0;
}
