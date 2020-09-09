#include <stdio.h>

#define max(a,b) (a>b?a:b)

int main(void) {
	int n, i;
	int input[10001];
	int dp[10001];
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &input[i]);
	
	dp[0] = 0;
	dp[1] = input[1];
	dp[2] = input[1] + input[2];
	dp[3] = max(input[1], input[2]) + input[3];
	
	for(i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i-2], dp[i-3]+input[i-1]), dp[i-4]+input[i-1]) + input[i];
	}
	
	printf("%d", max(dp[n-1],dp[n]));
}