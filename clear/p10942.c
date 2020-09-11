#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, i, j;
	int *num;
	int **dp;
	
	scanf("%d", &N);
	num = (int *)malloc(sizeof(int) * N);
	dp = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		dp[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++) {
			dp[i][j] = 0;
		}
		dp[i][i] = 1;
		
		scanf("%d", &num[i]);
	}
	
	for(i = 0; i < N-1; i++)
		if(num[i] == num[i+1])
			dp[i][i+1] = 1;
	
	for(i = 2; i < N; i++) 
		for(j = 0; j < N-i; j++) 
			if(dp[j+1][j+i-1] == 1 && num[j] == num[j+i])
				dp[j][j+i] = 1;
		
	scanf("%d", &M);
	while(M--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", dp[i-1][j-1]);
	}
}