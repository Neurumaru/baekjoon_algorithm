// p1697.c

#include <stdio.h>

#define min(a,b) ((a)>(b)?(b):(a))

int main(void) {
	int N, K;
	int i, j, k;
	int dp[100001];

	scanf("%d %d", &N, &K);
	
	for(i = 0; i < N; i++)
		dp[i] = N - i;
	dp[N] = 0;
	for(i = N+1; i <= K; i++) {
		if(i%2 == 0)
			dp[i] = min(dp[i/2], dp[i-1]) + 1;
		else
			dp[i] = dp[i-1] + 1;
	}
	
	printf("%d\n", dp[K]);
}
