#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INF (1 << 24)

#define push(d) heap[++size] = d; sort_push();
#define pop(d) d = heap[1]; heap[1] = heap[size--]; sort_pop();

typedef struct DATA {
	int p, d;
}data;

data heap[65536];
int cost[2001][2001];
int size;

int n, m, t, s, g, h;
int s_d[2001], g_d[2001], h_d[2001];
int result[2001];

void sort_push() {
	register int i, j;
	data tmp;
	
	i = size;
	while(i != 1) {
		j = i / 2;
		if(heap[i].d < heap[j].d) {
			tmp = heap[j];
			heap[j] = heap[i];
			heap[i] = tmp;
			i = j;
		} else break;
	}
}

void sort_pop() {
	register int i, j;
	data tmp;
	
	i = 1;
	while(j = i * 2, j < size) {
		j = heap[j].d<heap[j+1].d?j:j+1;
		if(heap[i].d > heap[j].d) {
			tmp = heap[j];
			heap[j] = heap[i];
			heap[i] = tmp;
			i = j;
		}
		else break;
	}
	if(j == size)
		if(heap[i].d > heap[j].d) {
			tmp = heap[j];
			heap[j] = heap[i];
			heap[i] = tmp;
		}
}

void dijkstra(int s, int * dist) {
	data d, tmp;
	int i;
	
	for(i = 1; i <= n; i++) 
		dist[i] = INF;
	dist[s] = 0;
	size = 0;
	d.p = s;
	d.d = 0;
	push(d);
	while(size != 0) {
		pop(d);
		if(dist[d.p] < d.d) continue;
		for(i = 1; i <= n; i++)
			if(dist[i] > d.d + cost[d.p][i]) {
				dist[i] = d.d + cost[d.p][i];
				tmp.p = i; tmp.d = dist[i];
				push(tmp);
			}
	}
}

void main() {
	int T, i, j, k;
	data d;
	
	
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
				if(s_d[g] + g_d[h] + h_d[i] == s_d[i] ||
				  s_d[h] + h_d[g] + g_d[i] == s_d[i])
					printf("%d ", i);
		}
		printf("\n");
	}
}