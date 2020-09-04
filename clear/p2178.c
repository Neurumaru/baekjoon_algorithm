#include <stdio.h>
#include <stdlib.h>

#define AVAIL(A,B) (0 <= A && A < N && 0 <= B && B < M && maze[A][B] == 1 && S[A][B] == 0)

int main(void) {
	char c;
	int N, M, i, j, head, rear, dist;
	int *qi, *qj, *d;
	int **maze, **S;
	
	scanf("%d %d", &N, &M);
	
	qi = (int *)malloc(sizeof(int) * N * M);
	qj = (int *)malloc(sizeof(int) * N * M);
	d = (int *)malloc(sizeof(int) * N * M);
	maze = (int **)malloc(sizeof(int *) * N);
	S = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		maze[i] = (int *)malloc(sizeof(int) * M);
		S[i] = (int *)malloc(sizeof(int) * M);
		for(j = 0; j < M; j++) {
			while(scanf("%c", &c), c != '1' && c != '0');
			maze[i][j] = c - '0';
			S[i][j] = 0;
		}
	}
	
	head = 0;
	rear = 1;
	qi[0] = qj[0] = 0;
	d[0] = 1;
	S[0][0] = 1;
	while(head != rear) {
		i = qi[head]; j = qj[head]; dist = d[head++];
		if(i == N-1 && j == M-1) break;
		if(AVAIL(i+1, j)) {
			S[i+1][j] = 1;
			qi[rear] = i+1; qj[rear] = j; d[rear++] = dist+1;
		}
		if(AVAIL(i, j+1)) {
			S[i][j+1] = 1;
			qi[rear] = i; qj[rear] = j+1; d[rear++] = dist+1;
		}
		if(AVAIL(i-1, j)) {
			S[i-1][j] = 1;
			qi[rear] = i-1; qj[rear] = j; d[rear++] = dist+1;
		}
		if(AVAIL(i, j-1)) {
			S[i][j-1] = 1;
			qi[rear] = i; qj[rear] = j-1; d[rear++] = dist+1;
		}
	}
	
	printf("%d", dist);
	
	return 0;
}