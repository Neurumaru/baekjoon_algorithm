#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int N, a[1000], dp[1000];

int input() {
	int i;
	
	scanf("%d", &N);
	//N = rand()%7 + 1;
	for(i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		//a[i] = rand()%1000+1;
		dp[i] = 0;
	}
}

int solve() {
	register int i, j;
	
	dp[0] = a[N-1];
	for(i = N-2; i >= 0; i--) {
		for(j = 0; j < N && dp[j] != 0; j++) {
			if(a[i] >= dp[j]) {
				dp[j] = a[i];
				break;
			}
		}
		if(dp[j] == 0)
			dp[j] = a[i];
	}

	for(i = 0; i < N && dp[i] != 0; i++);
	
	return i;
}
/*
int bruteforce() {
	int prev, i, j, k;
	int remove[1000];
	
	for(i = 1; i < N; i++)
		if(a[i-1] >= a[i]) break;
	if(i == N) return N;
	
	for(i = 0; i < N; i++) {
		for(j = 0; j <= i; j++)
			remove[j] = j;
		
		
		while(remove[i] < N) {			
			prev = 0;
			for(j = 0; j < N; j++) {
				for(k = 0; k <= i; k++) 
					if(j == remove[k]) break;
				
				if(k <= i) continue;
				if(a[j] <= prev) break;
				prev=a[j];
			}
			if(j == N) return N - i - 1;
			
			if(remove[i] == N-1) {
				for(k = i; k > 0; k--)
					if(remove[k]-1 != remove[k-1])
						break;
				
				if(k == 0) break;
				remove[k-1]++;
				for(; k <= i; k++)
					remove[k] = remove[k-1] + 1;
			}
			else {
				remove[i]++;
			}
		}
	}
	return 0;
}
*/
int main() {
	input();
	printf("%d", solve());	
}