#include <stdio.h>
#include <stdlib.h>

/*==================================================*/

#define INF 2100000000

/*==================================================*/

typedef struct node * NODE_PTR;
typedef struct node {
	int v, w;
	NODE_PTR n;
} NODE;

/*==================================================*/

typedef struct priority_queue * PQ_PTR;
typedef struct priority_queue {
	int *key, *data, capacity, size;
	PQ_PTR prev, next;
} PQ;

/*==================================================*/

void insert(NODE_PTR * P, int u, int v, int w);
NODE_PTR search(NODE_PTR * P, int u);

/*==================================================*/

void init(PQ_PTR * ptr);
void push(PQ_PTR ptr, int key, int data);
void pop(PQ_PTR ptr);
void extend(PQ_PTR ptr);

/*==================================================*/

int main(void) {
	int V, E, K, i, u, v, w;
	int * d;
	NODE_PTR tmp;
	NODE_PTR * P;
	PQ_PTR pq;
	
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	
	d = (int *)malloc(sizeof(int)*(V+1));
	P = (NODE_PTR *)malloc(sizeof(NODE_PTR)*(V+1));
	for(i = 0; i < V+1; i++) {
		d[i] = INF;
		P[i] = NULL;
	}
	for(i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insert(P, u, v, w);
	}
	init(&pq);
	
	d[K] = 0;
	push(pq, 0, K);
	while(pq->size != 0) {
		i = pq->data[0];
		if(pq->key[0] > d[i]) {
			pop(pq);
			continue;
		}
		tmp = search(P, i);
		while(tmp != NULL) {
			if(d[tmp->v] > d[i] + tmp->w) {
				d[tmp->v] = d[i] + tmp->w;
				push(pq, d[tmp->v], tmp->v);
			}
			tmp = search(NULL, i);
		}
		pop(pq);
	}
	
	for(i = 1; i <= V; i++) {
		if(d[i] != INF)
			printf("%d\n", d[i]);
		else
			printf("INF\n");
	}
	
	return 0;
}

/*==================================================*/

void insert(NODE_PTR * P, int u, int v, int w) {
	NODE_PTR tmp;
	if(P == NULL) return;
	tmp = (NODE_PTR)malloc(sizeof(NODE));
	tmp->v = v; tmp->w = w;
	tmp->n = P[u]; P[u] = tmp;
}
NODE_PTR search(NODE_PTR * P, int u) {
	static NODE_PTR static_ptr;
	if(P == NULL) {
		if(static_ptr == NULL) return NULL;
		static_ptr = static_ptr->n;
	} else {
		static_ptr = P[u];
	}
	return static_ptr;
}

/*==================================================*/

void init(PQ_PTR * ptr) {
	*ptr = (PQ_PTR)malloc(sizeof(PQ));
	(*ptr)->key = (int *)malloc(sizeof(int));
	(*ptr)->data = (int *)malloc(sizeof(int));
	(*ptr)->capacity = 1;
	(*ptr)->size = 0;
	(*ptr)->prev = NULL;
	(*ptr)->next = NULL;
}
void push(PQ_PTR ptr, int key, int data) {
	int index, tmp;
	
	if(ptr == NULL) return;
	while(ptr->capacity == ptr->size) {
		if(ptr->next == NULL)
			extend(ptr);
		ptr = ptr->next;
	}
	
	index = ptr->size++;
	ptr->key[index] = key;
	ptr->data[index] = data;
	while(ptr->prev != NULL && ptr->prev->key[index/2] > ptr->key[index]) {
		tmp = ptr->prev->key[index/2];
		ptr->prev->key[index/2] = ptr->key[index];
		ptr->key[index] = tmp;
		
		tmp = ptr->prev->data[index/2];
		ptr->prev->data[index/2] = ptr->data[index];
		ptr->data[index] = tmp;
		
		ptr = ptr->prev;
		index /= 2;
	}
}
void pop(PQ_PTR ptr) {
	int index, tmp;
	PQ_PTR ptr_tmp = ptr;
	
	if(ptr == NULL) return;
	while(ptr_tmp->capacity == ptr_tmp->size && ptr_tmp->next != NULL) 
		ptr_tmp = ptr_tmp->next;
	if(ptr_tmp->size == 0 && ptr_tmp->prev != NULL)
		ptr_tmp = ptr_tmp->prev;
	
	index = --(ptr_tmp->size);
	ptr->key[0] = ptr_tmp->key[index];
	ptr->data[0] = ptr_tmp->data[index];
	index = 0;
	while(ptr->next != NULL && ptr->next->size > index * 2) {
		if(ptr->next->size == index * 2 + 1 &&
				ptr->key[index] > ptr->next->key[index * 2]) {
			tmp = ptr->key[index];
			ptr->key[index] = ptr->next->key[index * 2];
			ptr->next->key[index * 2] = tmp;
			
			tmp = ptr->data[index];
			ptr->data[index] = ptr->next->data[index * 2];
			ptr->next->data[index * 2] = tmp;
			
			index = index * 2;
			ptr = ptr->next;
		} else if(ptr->key[index] > ptr->next->key[index * 2] || 
				ptr->key[index] > ptr->next->key[index * 2 + 1]) {
			if(ptr->next->key[index * 2] < ptr->next->key[index * 2 + 1]) {
				tmp = ptr->key[index];
				ptr->key[index] = ptr->next->key[index * 2];
				ptr->next->key[index * 2] = tmp;
			
				tmp = ptr->data[index];
				ptr->data[index] = ptr->next->data[index * 2];
				ptr->next->data[index * 2] = tmp;
				
				index = index * 2;
				ptr = ptr->next;
			} else {
				tmp = ptr->key[index];
				ptr->key[index] = ptr->next->key[index * 2 + 1];
				ptr->next->key[index * 2 + 1] = tmp;
			
				tmp = ptr->data[index];
				ptr->data[index] = ptr->next->data[index * 2 + 1];
				ptr->next->data[index * 2 + 1] = tmp;
				
				index = index * 2 + 1;
				ptr = ptr->next;
			}
		} else break;
	}
}
void extend(PQ_PTR ptr) {
	ptr->next = (PQ_PTR)malloc(sizeof(PQ));
	ptr->next->key = (int *)malloc(sizeof(int) * ptr->capacity * 2);
	ptr->next->data = (int *)malloc(sizeof(int) * ptr->capacity * 2);
	ptr->next->capacity = ptr->capacity * 2;
	ptr->next->size = 0;
	ptr->next->prev = ptr;
	ptr->next->next = NULL;
}