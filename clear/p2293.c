#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k, i, j, l;
	int * price;
	int ** calc;
	
	scanf("%d %d", &n, &k);
	
	price = (int *)malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++) {
		scanf("%d", &price[i]);
	}
	
	for(i = 0; i < n - 1; i++) 
		for(j = i + 1; j < n; j++)
			if(price[i] > price[j]) {
				l = price[i];
				price[i] = price[j];
				price[j] = l;
			}
	
	calc = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n && price[i] <= k; i++) {
		calc[i] = (int *)malloc(sizeof(int) * (price[i] + 1));
		for(j = 0; j <= price[i]; j++) calc[i][j] = 0;
	}
	n = i;
	
	for(i = 1; i <= k; i++) {
		for(j = 0; j < n; j++) {
 			for(l = 0; l < price[j]; l++)
				calc[j][l] = calc[j][l+1];
			calc[j][l] = 0;
		}
		for(j = 0; j < n; j++) {
			if(price[j] == i)
				calc[j][0] = 1;
			for(l = 0; l <= j; l++) {
				calc[l][price[l]] += calc[j][0];
			}
		}
	}
	
	for(i = j = 0; i < n; i++) {
		j += calc[i][0];
	}
	
	printf("%d", j);
	
	return 0;
}
