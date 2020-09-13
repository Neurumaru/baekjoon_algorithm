#include <stdio.h>

int calculated_combination[30][30];

int combination(int n, int r) {
	if(n == r || r == 0) 
		return 1;
		
	if(calculated_combination[n][r] == 0)
		calculated_combination[n][r] = combination(n-1, r-1) + combination(n-1, r);
	
	return calculated_combination[n][r];
}

int main(void) {
	int T, N, M, i;
	long long int result;
	scanf("%d", &T);
	
	for(i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		
		printf("%d\n", combination(M, N));
	}
	
	return 0;
}
