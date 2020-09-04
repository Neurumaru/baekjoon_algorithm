#include <stdio.h>
#include <stdlib.h>

#define MAX_N (1001)

int main(void) {
	int T, N, K, X, Y, W, i, j, k;
	int D[MAX_N], check[MAX_N], delay[MAX_N];
	int XY[MAX_N][MAX_N];

	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		for(j = 0; j < MAX_N; j++) {
			D[j] = check[j] = delay[j] = 0;
			for(k = 0; k < MAX_N; k++)
				XY[j][k] = 0;
		}
		
		scanf("%d %d", &N, &K);
		for(j = 1; j <= N; j++)
			scanf("%d", &D[j]);
		for(j = 0; j < K; j++) {
			scanf("%d %d", &X, &Y);
			XY[X][Y] = 1;
			check[Y]++;
		}
		scanf("%d", &W);
		
		for(j = 1; j <= N; j++)
			if(check[j] == 0) delay[j] = D[j];
		
		while(check[W] != 0) {
			for(X = 1; X <= N && check[X] != 0; X++);
			for(Y = 1; Y <= N; Y++) {
				if(XY[X][Y] == 1) {
					if(delay[Y] < delay[X] + D[Y])
						delay[Y] = delay[X] + D[Y];
					XY[X][Y] = 0;
					check[Y]--;
				}
			}
			check[X] = -1;
		}
		
		printf("%d\n", delay[W]);
	}
	
	return 0;
}