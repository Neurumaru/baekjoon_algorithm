#include <stdio.h>

int main(void) {
	long long int Fn, Fn_1, Fn_2;
	int i, n;
	
	scanf("%d", &n);
	
	Fn = Fn_1 = 1; Fn_2 = 0;
	for(i = 2; i <= n; i++) {
		Fn = Fn_1 + Fn_2;
		Fn_2 = Fn_1;
		Fn_1 = Fn;
	}
	printf("%lld", Fn);
	
	return 0;
}
