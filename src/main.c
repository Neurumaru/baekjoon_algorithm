#include <stdio.h>
#include <stdlib.h>

#define MAX_N 501

int N = 501;
int arr[MAX_N];
int dp[MAX_N];

int lis() {
	int i, j;
	
	for(i = 0; i < N; i++)
		dp[i] = -1;
	
	dp[0] = arr[0];
	for(i = 1; i < N; i++) {
		for(j = 0; j < N & dp[j] != -1; j++) 
			if(arr[i] <= dp[j]) {
				dp[j] = arr[i];
				break;
			}
		
		if(dp[j] == -1) {
			dp[j] = arr[i];
		}
	}
	for(i = 0; i < N && dp[i] != -1; i++);
	return i;
}

/*
int n_LIS(int n) {
	int result = 0;
	
	for(int i=0 ; i<n ; i++) {
		dp[i] = 1;
		for(int j=0 ; j<i ; j++) {
			if(arr[i] > arr[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1; 
				}
			}
		}
		result = result>dp[i]?result:dp[i];
	}
	return result;
}*/


int main(void) {
	int M, i, j, k;
	
	scanf("%d", &M);
	for(i = 0; i < N; i++)
		arr[i] = 0;
	for(i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		arr[j-1] = k;
	}
	for(i = 0, j = 0; i < N & j < M; i++) {
		if(arr[i] == 0) continue;

		arr[j++] = arr[i];
	} 
	N = M;
	printf("%d", N-lis(N));
}