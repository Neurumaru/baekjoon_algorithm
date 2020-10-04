#include <stdio.h>

#define MAX (10001)
#define INIT(S,D) \
D[0][0] = S[N][0]; D[0][1] = S[N][1]; \
for(j = 1; j <= N; j++) { \
	D[j][0] = S[j][0]; \
	D[j][1] = S[j][1]; \
}
#define COVER(a,b,c,d) D[a][b]+D[c][d]<=W

int getmin(int ** D, int N, int W) {
	int a[MAX], b[MAX], c[MAX], i;
	
	b[0] = c[0] = 1;
	a[0] = D[0][0] + D[0][1] <= W?1:2;
	c[1] = a[0] + 1;
	if(D[0][0] + D[1][0] <= W && D[0][1] + D[1][1] <= W)
		a[1] = 2;
	
	for(i = 1; i <= N; i++) {
		c[i] = a[i-1] + 1;
		if(D[i-1][0] + D[i][0] <= W && c[i] > b[i-1] + 1)
			c[i] = b[i-1] + 1;
	
		b[i] = a[i-1] + 1;
		if(D[i-1][1] + D[i][1] <= W && b[i] > c[i-1] + 1)
			b[i] = c[i-1] + 1;
	
		a[i] = (b[i]>c[i]?c[i]:b[i]) + 1;
		if(D[i-1][0] + D[i][0] <= W && D[i-1][1] + D[i][1] <= W &&
			i > 1 && a[i] > a[i-2] + 2)
			a[i] = a[i-2] + 2;
		if(D[i][0] + D[i][1] <= W && a[i] > a[i-1] + 1)
			a[i] = a[i-1] + 1;
	}
	
	return a[N]-2;
}

int main(void) {
	int T, N, W, i, j, k, n;
	int E[MAX][2], D[MAX][2];
	
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d", &N, &W);
		for(j = 0; j < N; j++)
			scanf("%d", &E[j][0]);
		for(j = 0; j < N; j++)
			scanf("%d", &E[j][0]);
		
		INIT(D, E);
		D[0][0] = D[0][1] = W;
		n = getmin(D, N, W);
		
		INIT(D, E);
		D[N][0] = D[0][1] = W;
		j = getmin(D, N, W);
		if(n > j) n = j;
		
		INIT(D, E);
		D[0][0] = D[N][1] = W;
		j = getmin(D, N, W);
		if(n > j) n = j;
		
		INIT(D, E);
		D[N][0] = D[N][1] = W;
		j = getmin(D, N, W);
		if(n > j) n = j;
		
		printf("%d", n);
	}
	
	return 0;
}
    