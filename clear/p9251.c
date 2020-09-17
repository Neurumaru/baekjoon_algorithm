#include <stdio.h>
#include <string.h>

int main(void) {
	int dp[1001];
	char arr1[1001], arr2[1001];
	int i, j, N, M, prev, tmp;
	
	scanf("%s %s", arr1, arr2);
	N = strlen(arr1);
	M = strlen(arr2);
	for(i = 0; i <= M; i++) dp[i] = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j <= M; j++) {
			if(j == 0) {
				prev = 0;
				continue;
			}
			if(arr1[i] == arr2[j-1]) {
				tmp = prev;
				prev = dp[j];
				dp[j] = tmp + 1;
			} else {
				prev = dp[j];
				if(dp[j] < dp[j-1])
					dp[j] = dp[j-1];
			}
			printf("%d ", dp[j]);
		}
		printf("\n");
	}
	printf("%d", dp[M]);
}