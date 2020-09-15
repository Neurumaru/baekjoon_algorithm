int dp[1000];

int lds(int *arr, int N) {
	int i, j, result;
	
	for(i = 0; i < N; i++) dp[i] = 0;
	
	result = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N && dp[j] != 0; j++)
			if(dp[j] <= arr[i])
				break;
		dp[j] = arr[i];
		result = result>j?result:j;
	}
	return result+1;
}
