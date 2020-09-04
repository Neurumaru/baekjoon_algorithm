#include <stdio.h>
#include <stdlib.h>

const int MAX_INT = 100000000;

/*==================================================*/
//define struct

typedef struct priority_queue * PQ_PTR;
typedef struct priority_queue {
	int *key, *data, capacity, size;
	PQ_PTR prev, next;
} PQ;

/*==================================================*/
//define function

void init(PQ_PTR * ptr);
void push(PQ_PTR ptr, int key, int data);
void pop(PQ_PTR ptr);
void extend(PQ_PTR ptr);

/*==================================================*/

int mcost[801];
int cost[801][801];
int N, E, i, j, k, l, a, b, fa, fb;
PQ_PTR ptr;

int solve(int start, int end) {
	for(i = 1; i <= N; i++) mcost[i] = MAX_INT;
	mcost[start] = 0;
	push(ptr, mcost[start], start);
	while(ptr->size != 0) {
		i = ptr->key[0];
		j = ptr->data[0];
		if(i > mcost[j]) {
			pop(ptr); continue;
		}
		for(k = 1; k <= N; k++) {
			if(cost[j][k] + i < mcost[k]) {
				mcost[k] = cost[j][k] + i;
				push(ptr, mcost[k], k);
			}
		}
		pop(ptr);
	}
	return mcost[end];
}

int main(void) {
	scanf("%d %d", &N, &E);
	for(i = 0; i <= N; i++)
		for(j = 0; j <= N; j++)
			cost[i][j] = MAX_INT;
	for(i = 0; i < E; i++) {
		scanf("%d %d %d", &l, &j, &k);
		cost[l][j] = cost[j][l] = k;
	}
	scanf("%d %d", &a, &b);
	
	
	init(&ptr);
	
	fa = fb = solve(a, b);
	fa += solve(1, a) + solve(b, N);
	fb += solve(1, b) + solve(a, N);
	
	printf("%d", (fa>fb?fb:fa)>=MAX_INT?-1:fa>fb?fb:fa);
	
	return 0;
}

/*==================================================*/
//function

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

/*==================================================*/
