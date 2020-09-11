#include <stdio.h>

#define QUEUE_MAX_SIZE 256
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

int queue[QUEUE_MAX_SIZE];
int head, tail;

int main(void) {
	int i, j, k, N, M;
	int c[101][101];
	int visited[101];
	
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++)
		for(j = 1; j <= N; j++)
			c[i][j] = 0;
	for(i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		c[j][k] = c[k][j] = 1;
	}
	
	push(1);
	visited[1] = 1;
	k = 0;
	while(!is_empty()) {
		pop(j);
		for(i = 1; i <= N; i++) {
			if(c[j][i] == 1 && visited[i] != 1) {
				push(i);
				visited[i] = 1;
				k++;
			}
		}
	}
	
	printf("%d", k);
}