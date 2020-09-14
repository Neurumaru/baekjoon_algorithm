#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500

int N = 500;
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