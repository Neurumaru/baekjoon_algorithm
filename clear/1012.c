#include <stdio.h>

#define QUEUE_MAX_SIZE 2500
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

typedef struct DATA{
	int x, y;
}DATA;

DATA queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int T, M, N, K, X, Y, i, j, k, result, ax, ay;
	int map[50][50];
	int dx[] = {0, 0, -1, 1};
	int dy[] = {-1, 1, 0, 0};

	DATA data, tmp;


	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &M, &N, &K);
	
		result = 0;	
		for(i = 0; i < N; i++) {
			for(j = 0; j < M; j++) {
				map[i][j] = 0;
			}
		}

		for(i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);

			map[Y][X] = 1;
		}

		for(i = 0; i < N; i++) {
			for(j = 0; j < M; j++) {
				if(map[i][j] == 1) {
					map[i][j] = 0;
					result++;
					tmp.y = i; tmp.x = j;
					push(tmp);
					while(!is_empty()) {
						pop(data);
						for(k = 0; k < 4; k++) {
							ay = data.y + dy[k]; ax = data.x + dx[k];
							if(0 > ay || ay >= N || 0 > ax || ax >= M)
								continue;

							if(map[ay][ax] == 1) {
								map[ay][ax] = 0;
								tmp.y = ay; tmp.x = ax;
								push(tmp);
							}
						}
					}
				}
			}
		}

		printf("%d\n", result);
	}

	return 0;
}
