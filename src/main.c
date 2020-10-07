#include <stdio.h>

#define QUEUE_MAX_SIZE 250000
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

typedef struct DATA{
	int x, y, z;
}DATA;

DATA queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int M, N, H, i, j, k, ax, ay, az, result;
	int map[100][100][100];
	
	DATA data, tmp;

	int dx[] = {-1, 1, 0, 0, 0, 0};
	int dy[] = {0, 0, -1, 1, 0, 0};
	int dz[] = {0, 0, 0, 0, -1, 1};

	scanf("%d %d %d", &M, &N, &H);

	for(i = 0; i < H; i++)
		for(j = 0; j < N; j++) 
			for(k = 0; k < M; k++)
				scanf("%d", &map[i][j][k]);

	for(i = 0; i < H; i++)
		for(j = 0; j < N; j++)
			for(k = 0; k <  M; k++)
				if(map[i][j][k] == 1) {
					tmp.z = i; tmp.y = j; tmp.x = k;
					push(tmp);
				}
	
	while(!is_empty()) {
		pop(data);
		for(i = 0; i < 6; i++) {
			ax = data.x + dx[i];
			ay = data.y + dy[i];
			az = data.z + dz[i];

			if(ax < 0 || ax >= M) continue;
			if(ay < 0 || ay >= N) continue;
			if(az < 0 || az >= H) continue;

			if(map[az][ay][ax] == -1) continue;

			if(map[az][ay][ax] == 0 || map[az][ay][ax] > map[data.z][data.y][data.x]+1) {
				map[az][ay][ax] = map[data.z][data.y][data.x] + 1;
				tmp.z = az; tmp.y = ay; tmp.x = ax;
				push(tmp);
			}
		}
	}

	/*
	for(i = 0; i < H; i++) {
		for(j = 0; j < N; j++) {
			for(k = 0; k < M; k++) {
				printf("%2d", map[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/

	result = 0;
	for(i = 0; i < H; i++)
		for(j = 0; j < N; j++)
			for(k = 0; k < M; k++) {				
				if(map[i][j][k] == 0) {
					printf("-1\n");
					return 0;
				}

				if(map[i][j][k] > result)
					result = map[i][j][k];	
			}

	printf("%d\n", result-1); 
}
