#include <stdio.h>

#define QUEUE_MAX_SIZE 10000
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

typedef struct DATA{
	int x, y;
}DATA;

DATA queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int N, i, j, k, ax, ay, cur, result;
	int num[350];
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	
	char map[25][26];
	
	DATA tmp, data;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%s", map[i]);
	cur = 0;
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(map[i][j] == '1') {
				map[i][j] = '0';
				result = 0;
				tmp.x = i; tmp.y = j;
				push(tmp);
				while(is_empty()) {
					pop(data);
					for(k = 0; k < 4; k++) {
						ax = data.x + dx[k];
						ay = data.y + dy[k];
						
						if(ax < 0 || ax >= N || ay < 0 || ay >= N)
							continue;
						
						if(map[ax][ay] == '1') {
							map[ax][ay] = '0';
							result++;
							tmp.x = ax; tmp.y = ay;
							push(tmp);
						}
					}
				}
				num[cur++] = result;
			}
		}
	}
	for(i = 0; i < cur; i++) {
		for(j = i+1; j < cur; j++) {
			if(num[i] > num[j]) {
				k = num[i];
				num[i] = num[j];
				num[j] = k;
			}
		}
	}
	for(i = 0 ; i < cur; i++) {
		printf("%d\n", num[i]);
	}
}