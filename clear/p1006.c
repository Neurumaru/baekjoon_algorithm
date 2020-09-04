#include <stdio.h>

#define MAX (10001)
#define COVER(a,b,c,d) D[a][b]+D[c][d]<=W

int getmin(int D[MAX][2], int N, int W) {
	int a[MAX], b[MAX], c[MAX], i;
	
	b[0] = c[0] = 1;
	a[0] = COVER(0,0,0,1)?1:2;
	c[1] = a[0] + 1;
	
	for(i = 1; i <= N; i++) {
		c[i] = a[i-1] + 1;
		if(COVER(i-1, 0, i, 0) && c[i] > b[i-1] + 1)
			c[i] = b[i-1] + 1;
		
		b[i] = a[i-1] + 1;
		if(COVER(i-1, 1, i, 1) && b[i] > c[i-1] + 1)
			b[i] = c[i-1] + 1;
		
		a[i] = (b[i]>c[i]?c[i]:b[i]) + 1;
		if(COVER(i-1, 0, i, 0) && COVER(i-1, 1, i, 1) &&
			i > 1 && a[i] > a[i-2] + 2)
			a[i] = a[i-2] + 2;
		else if(i == 1 && COVER(0,0,1,0) && COVER(0,1,1,1))
			a[1] = 2;
		if(COVER(i, 0, i, 1) && a[i] > a[i-1] + 1)
			a[i] = a[i-1] + 1;
			
		
	}
	
	return a[N]-2;
}

int main(void) {
	int T, N, W, i, j, k, n;
	int E[MAX][2];
	
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%d %d", &N, &W);
		for(j = 0; j < N; j++)
			scanf("%d", &E[j][0]);
		for(j = 0; j < N; j++)
			scanf("%d", &E[j][1]);
		
		E[N][0] = E[0][0];
		E[N][1] = E[0][1];
		E[0][0] = E[0][1] = W;
		n = getmin(E, N, W);
		
		E[0][0] = E[N][0];
		E[0][1] = E[N][1];
		E[N][0] = E[0][1] = W;
		j = getmin(E, N, W);
		if(n > j) n = j;
		
		E[N][0] = E[0][0];
		E[0][1] = E[N][1];
		E[0][0] = E[N][1] = W;
		j = getmin(E, N, W);
		if(n > j) n = j;
		
		E[0][0] = E[N][0];
		E[N][1] = E[0][1];
		E[N][0] = E[N][1] = W;
		j = getmin(E, N, W);
		if(n > j) n = j;
		
		printf("%d\n", n);
	}
	
	return 0;
}