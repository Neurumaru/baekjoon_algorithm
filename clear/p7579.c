#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

#define STACK_MAX_SIZE 10000
#define push_stack(data) stack[stack_size++] = data
#define pop_stack(data) data = stack[--stack_size]
#define is_empty() (stack_size == 0)

typedef struct DATA {
	int memory, cost;
}DATA;

typedef struct node * node_ptr; 
typedef struct node {
	int memory, cost;
	node_ptr next;
}node;

node_ptr root;

DATA stack[STACK_MAX_SIZE];
int stack_size;

int N, M;
int c[100];
int m[100];

void connect(node_ptr prev, node_ptr new, node_ptr curr) {
	if(prev == NULL)
		root = new;
	else
		prev->next = new;
	new->next = curr;
}

void new_node(int m, int c, node_ptr prev, node_ptr curr) {
	node_ptr new = (node_ptr)malloc(sizeof(node));
	new->memory = m; new->cost = c;
	connect(prev, new, curr);
}

void push(int m, int c) {
	node_ptr prev = NULL;
	node_ptr curr = NULL;
	node_ptr tmp = NULL;
	
	if(root == NULL) {
		new_node(m, c, NULL, NULL);
		return;
	}
	
	if(c > INF) return;
	
	for(curr = root; curr != NULL && curr->memory < m; prev = curr, curr = curr->next) {
		if(curr->cost >= c) {
			curr->memory = m;
			curr->cost = c;
			prev = curr;
			curr = curr->next;
			while(curr != NULL && curr->memory <= m) {
				tmp = curr;
				curr = curr->next;
				free(tmp);
			}
			prev->next = curr;
			return;
		}
	}
	if(curr == NULL)
		new_node(m, c, prev, NULL);
	else if(curr->cost > c) {
		if(curr->memory == m)
			curr->cost = c;
		else if(curr->memory > m)
			new_node(m, c, prev, curr);
	}
}

int main() {
	int i, j, k;
	DATA tmp;
	node_ptr curr;
	
	scanf("%d %d", &N, &M);
	for(i = 0; i < N; i++) 
		scanf("%d", &m[i]);
	for(i = 0; i < N; i++) 
		scanf("%d", &c[i]);
	
	push(0, 0);
	push(60, INF);
	for(i = 0; i < N; i++) {
		for(curr = root; curr != NULL; curr = curr->next) {
			tmp.memory = curr->memory + m[i];
			tmp.cost = curr->cost + c[i];
			push_stack(tmp);
		}
		while(!is_empty()) {
			pop_stack(tmp);
			push(tmp.memory, tmp.cost);
		}
	}
	for(curr = root; curr != NULL; curr = curr->next) 
		if(curr->memory >= M) break;
	printf("%d", curr->cost);
}