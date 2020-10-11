// p1697.c

#include <stdio.h>

#define INF 1000000
#define min(a,b) ((a)>(b)?(b):(a))

#define QUEUE_MAX_SIZE 100001
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

int queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int N, K, i;
	int dp[100001];

	for(i = 0; i <= 100000; i++) {
		dp[i] = INF;
	}

	scanf("%d %d", &N, &K);

	push(N);
	dp[N] = 0;
	while(!is_empty()) {
		pop(i);
		if(i-1 >= 0 && dp[i-1] == INF) {
			dp[i-1] = dp[i] + 1;
			push(i-1);
		}
		if(i+1 <= 100000 && dp[i+1] == INF) {
			dp[i+1] = dp[i] + 1;
			push(i+1);
		}
		if(i*2 <= 100000 && dp[i*2] == INF) {
			dp[i*2] = dp[i] + 1;
			push(i*2);
		}
	}

	printf("%d\n", dp[K]);
}
