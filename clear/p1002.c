#include <stdio.h>
#include <math.h>

int main(void) {
	int T;
	double x1, y1, r1, x2, y2, r2, i;
	
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		
		if(x1 == x2 && y1 == y2 && r1 == r2) printf("-1\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) + r1 < r2) printf("0\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) + r2 < r1) printf("0\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) + r1 == r2) printf("1\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) + r2 == r1) printf("1\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) < r1 + r2) printf("2\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) == r1 + r2) printf("1\n");
		else if(sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) > r1 + r2) printf("0\n");
	}
	
	return 0;
}
