#include <stdio.h>

int inside(int x, int y, int cx, int cy, int r) {
	if((cx-x)*(cx-x) + (cy-y)*(cy-y) < r*r)
		return 1;
	else
		return 0;
}

int main(void) {
	int T, x1, y1, x2, y2, n, cx, cy, r;
	int i, j, tmp, result;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++) {
		result = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for(j = 0; j < n; j++) {
			scanf("%d %d %d", &cx, &cy, &r);
			tmp = inside(x1, y1, cx, cy, r) + inside(x2, y2, cx, cy, r);
			if(tmp == 1) result++;
		}
		printf("%d\n", result);
	}
	
	return 0;
}
