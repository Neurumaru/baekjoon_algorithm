#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k, i, j, l;
	int * price;
	int * calc;
	
	scanf("%d %d", &n, &k);
	
	price = (int *)malloc(sizeof(int)*n);
	calc = (int *)malloc(sizeof(int)*(k+1));
	
	for(i = 0; i < n; i++) 
		scanf("%d", &price[i]);
	for(i = 0; i <= k; i++)
		calc[i] = 10001;
	
	for(i = 0; i < n-1; i++)
		for(j = i+1; j < n; j++)
			if(price[i] > price[j]) {
				l = price[i];
				price[i] = price[j];
				price[j] = l;
			}
	
	for(i = 1; i <= k; i++) {
		for(j = 0; j < n; j++)
			if(i == price[j])
				calc[i] = 1;
		for(j = 0; j < n; j++)
			if(i - price[j] > 0)
				if(calc[i] > calc[i-price[j]] + 1)
					calc[i] = calc[i-price[j]] + 1;\
	}
	if(calc[k] == 10001)
		printf("%d", -1);
	else
		printf("%d", calc[k]);
	
	return 0;
}