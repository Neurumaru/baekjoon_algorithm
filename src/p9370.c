#include <stdio.h>

#define INF 10000

#define push(p,d) heap[++size][0] = d; heap[size][0] = p; sort();
#define pop(p,d) d = heap[0][0]; p = heap[0][1]; heap[0][0] = heap[size][0]; heap[0][1] = heap[size--][1]; sort();

int heap[2048][2];
int cost[2001][2001];
int size;

int n, m, t, s, g, h;
int s_d[2001], g_d[2001], h_d[2001];
int result[2001];

void sort() {
	register int i, j, k, tmp;
	
	i = 1;
	while(j = i, j < size) {
		j = heap[j][0] > heap[j+1][0]?j:j+1;
		if(heap[i][0] > heap[j][0]) {
			for(k = 0; k < 2; k++) {
				tmp = heap[j][k];
				heap[j][k] = heap[i][k];
				heap[i][k] = tmp;
				i = j;
			}
		}
		else break;
	}
	if(j == size)
		if(heap[i][0] > heap[j][0]) {
			for(k = 0; k < 2; k++) {
				tmp = heap[j][k];
				heap[j][k] = heap[i][k];
				heap[i][k] = tmp;
			}
		}
}

void dijkstra(int s, int * dist) {
	int i, p, d;
	
	for(i = 1; i <= n; i++) 
		dist[i] = INF;
	push(s, 0);
	while(size != 0) {
		pop(p, d);
		if(dist[p] <= d) continue;
		for(i = 0; i < n; i++)
			if(dist[i] > d + cost[p][i]) {
				dist[i] = d + cost[p][i];
				push(i, dist[i]);
			}
	}
}

void main() {
	int T, i, j, k;
	
	scanf("%d", &T);
	while(T--) {		
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				cost[i][j] = INF;
			}
			cost[i][i] = 0;
			result[i] = 0;
		}
				
		for(i = 0; i < m; i++) {
			scanf("%d %d", &j, &k);
			scanf("%d", &cost[j][k]);
			cost[k][j] = cost[j][k];
		}
		
		dijkstra(s, s_d);
		dijkstra(g, g_d);
		dijkstra(h, h_d);
		
		for(i = 0; i < t; i++) {
			scanf("%d", &j);
			result[j] = 1;
		}
		
		for(i = 1; i <= n; i++) {
			if(result[i])
				if(s_d[g] + cost[g][h] + h_d[i] == s_d[i] ||
				  s_d[h] + cost[h][g] + g_d[i] == s_d[i])
					printf("%d ", i);
		}
	}
}