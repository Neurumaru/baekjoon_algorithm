#include <stdio.h>

int dp[1000];
int cache[1000];

void lis(int *arr, int N) {
	int i, j;
	
	for(i = 0; i < N; i++) dp[i] = 0;
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N && dp[j] != 0; j++)
			if(dp[j] >= arr[i])
				break;
		dp[j] = arr[i];
		
		cache[i] += j;
	}
}

int lds(int *arr, int N) {
	int i, j;
	
	for(i = 0; i < N; i++) dp[i] = 0;
	
	for(i = N-1; i >= 0; i--) {
		for(j = 0; j < N && dp[j] != 0; j++)
			if(dp[j] >= arr[i])
				break;
		dp[j] = arr[i];
		cache[i] += j;
	}
}

int main(void) {
	int N, i, j, result, arr[1000];
	
	scanf("%d", &N);
	
	for(i = 0; i < N; i++) 
		scanf("%d", &arr[i]);
	
	lis(arr, N); lds(arr, N);
	
	result = 0;
	for(i = 0 ; i < N; i++)
		result = result>cache[i]?result:cache[i];
	printf("%d", result+1);
}