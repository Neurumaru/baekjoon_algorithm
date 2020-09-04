#include <stdio.h>

#define INF 1000000
#define push(a, b, c) queue[0][head] = a; queue[1][head] = b; queue[2][head++] = c
#define pop(a, b, c) a = queue[0][tail]; b = queue[1][tail]; c = queue[2][tail++]

int N, M, tail, head;
int dist[1000][1000][2];
char visited[1000][1000][2];
char map[1000][1001];
int queue[3][1000000];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
	register int i;
	int x, y, brk, ax, ay, c;
	
	while(tail != head) {
		pop(x, y, brk);
		
		for(i = 0; i < 4; i++) {
			ax = x + dx[i]; ay = y + dy[i];
			if(0 <= ax && ax < N && 0 <= ay && ay < M) {
				if(visited[ax][ay][0] == 1) continue;
				if(brk == 1 && map[ax][ay] == '1') continue;

				if(visited[ax][ay][1] == 0) {
					dist[ax][ay][1] = dist[x][y][brk] + 1;
					visited[ax][ay][1] = 1;
					push(ax, ay, 1);
				}

				if(brk == 0 && map[ax][ay] == '0') {
					dist[ax][ay][0] = dist[x][y][0] + 1;
					visited[ax][ay][0] = 1;
					push(ax, ay, 0);
				}
				
			}
		}
	}
	
	printf("%d", dist[N-1][M-1][1]>=INF?-1:dist[N-1][M-1][1]);
}

int main() {
	int i, j;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) 
		scanf("%s", map[i]);
	
	for(i = 0; i < N; i++)
		for(j = 0; j < M; j++)
			dist[i][j][0] = dist[i][j][1] = INF;
	dist[0][0][0] = dist[0][0][1] = 1;
	visited[0][0][0] = visited[0][0][1] = 1;
	head++;
	bfs();
	
	return 0;
}