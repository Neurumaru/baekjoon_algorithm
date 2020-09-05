#include <stdio.h>

#define MAX_HEIGHT 10001

#define STACK_MAX_SIZE 65536
#define push(data) stack[stack_size++] = data
#define pop(data) data = stack[--stack_size]
#define is_empty() (stack_size == 0)

typedef struct DATA {
	int x, y, d;
}DATA;

DATA stack[STACK_MAX_SIZE];
int stack_size;

int N, M;
int map[500][500];
int dp[500][500];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int input() {
	register int i, j;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	
}

int cal() {
	int i, j, ax, ay;
	DATA d, tmp;
	
	dp[N-1][M-1] = 1;
	tmp.x = 0; tmp.y = 0; tmp.d = 0;
	push(tmp);
	while(!is_empty()) {
		pop(d);
		//printf("%d %d %d\n", d.x, d.y, d.d);
		for(i = d.d;i < 4; i++) {
			ax = d.x + dx[i]; ay = d.y + dy[i];
			if(0 <= ax && ax < N && 0 <= ay && ay < M) {
				if(map[d.x][d.y] > map[ax][ay]) {
					if(dp[ax][ay] == -1) {
						d.d = i; push(d);
						tmp.x = ax; tmp.y = ay; tmp.d = 0;
						push(tmp);
						break;
					}
					else {
						if(dp[d.x][d.y] == -1) dp[d.x][d.y] = dp[ax][ay];
						else dp[d.x][d.y] += dp[ax][ay];
					}
				}
			}
		}
		if(i == 4 && dp[d.x][d.y] == -1)
			dp[d.x][d.y] = 0;
		
		/*
		for(i = 0; i < N; i++) {
			for(j = 0; j < M; j++) 
				printf("%4d", dp[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
	}
}

int output() {
	printf("%d", dp[0][0]);
}

int main() {	
	input();
	cal();
	output();
}