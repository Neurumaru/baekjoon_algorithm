#include <stdio.h>

int main(void) {
	int N, i, max;
	int num[10] = { 0 };
	
	scanf("%d", &N);
	
	if(N == 0) num[0]++;
	while(N != 0) {
		num[N % 10]++;
		N /= 10;
	}
	
	num[6] += num[9];
	num[6] = num[6]/2 + num[6]%2;

	for(i = 0, max = 0; i < 9; i++) 
		if(max < num[i])
			max = num[i];
	
	printf("%d", max);
	
	return 0;
}
