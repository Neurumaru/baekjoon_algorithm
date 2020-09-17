#include <stdio.h>

int main(void) {
	int N, K, w, v, i, dp[100001];
	
	
	scanf("%d %d", &N, &K);
	for(i = 0; i <= K; i++)
		dp[i] = 0;
	while(N--) {
		scanf("%d %d", &w, &v);
		for(i = K; i >= w; i--)
			if(dp[i] < dp[i-w] + v)
				dp[i] = dp[i-w] + v;
	}
	printf("%d", dp[K]);
}