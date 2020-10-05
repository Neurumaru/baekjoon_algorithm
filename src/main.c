#include <stdio.h>

#define QUEUE_MAX_SIZE 250000
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

typedef struct DATA{
	int x, y;
}DATA;

DATA queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int M, N, i, j, k, ax, ay, result;
	int map[1000][1000];
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};

	DATA data, tmp;

	scanf("%d %d", &M, &N);

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(map[i][j] == 1) {
				tmp.x = i; tmp.y = j;
				push(tmp);
				while(!is_empty()) {
					pop(data);
					for(k = 0; k < 4; k++) {
						ax = data.x + dx[k]; ay = data.y + dy[k];
						
						if(ax < 0 || ax >= N || ay < 0 || ay >= M)
							continue;

						if(map[ax][ay] == -1)
							continue;

						if(map[ax][ay] > map[data.x][data.y]+1 || map[ax][ay] == 0) {
							map[ax][ay] = map[data.x][data.y]+1;

							tmp.x = ax; tmp.y = ay;
							push(tmp);
						}
					}
				}
			}
		}
	}

	result = 0;
	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			if(map[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
			
			if(map[i][j] > result) {
				result = map[i][j];
			}
		}
	}

	printf("%d\n", result-1);

	return 0;
}
