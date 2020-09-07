#include <stdio.h>

int N;
int r[500];
int c[500];

int num[500][500];

int input() {
	register int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d %d", &r[i], &c[i]);
	}
}
int solve() {
	register int i, j, k;
	int a, b;
	
	for(i = 1; i < N; i++) {
		for(j = 0; j < N-i; j++) {
			num[i][j] = num[0][j] + r[j]*c[j]*c[i+j] + num[i-1][j+1];
			for(k = 1; k < i; k++) {
				a = num[k][j] + r[j]*c[j+k]*c[i+j] + num[i-k-1][j+k+1];
				if(a < num[i][j]) num[i][j] = a;
			}
		}
	}
}
int output() {
	printf("%d", num[N-1][0]);
}

int main() {
	input();
	solve();
	output();
}