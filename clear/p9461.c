#include <stdio.h>

int main(void) {
	int N, T;
	long long int dp[100];
	
	dp[0] = dp[1] = dp[2] = 1;
	dp[3] = dp[4] = 2;
	
	for(N = 5; N < 100; N++)
		dp[N] = dp[N-1] + dp[N-5];
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		printf("%lld\n", dp[N-1]);
	}
}