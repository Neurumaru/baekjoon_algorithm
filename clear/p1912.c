/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node * node_ptr;
typedef struct node {
	int pos, neg;
	node_ptr next;
} node;

node_ptr new_node(int pos, int neg) {
	node_ptr nn;
	
	nn = (node_ptr)malloc(sizeof(node));
	nn->pos = pos; nn->neg = neg;
	nn->next = NULL;
	
	return nn;
}

int main(void) {
	int N, i, j, sum;
	node_ptr ptr, tmp, cur;
	
	scanf("%d", &N);
	sum = 0;
	cur = ptr = new_node(-1000000000, 0);
	for(i = 0; i < N; i++) {
		scanf("%d", &j);
		sum += j;
		//printf("%d %d %d\n", sum, cur->pos, cur->neg);
		if(cur->pos < sum)
			cur->pos = sum;
		
		if(cur->neg > sum) {
			cur->next = new_node(-1000000000, sum);
			cur=cur->next;
		}
	}
	
	i = -1000000000;
	for(tmp = ptr; tmp != NULL; tmp=tmp->next)
		i = i>tmp->pos-tmp->neg?i:tmp->pos-tmp->neg;
	
	printf("%d", i);
}
*/
#include <stdio.h>
#include <math.h>

#define max(a,b)  (((a) > (b)) ? (a) : (b))

int main()
{
	int n;
	int val = 0, ans = -99999999, tmp;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		val = max(val + tmp, tmp);
		ans = max(ans, val);
		printf("%d %d\n", val, ans);
	}
	
	printf("%d", ans); 
	
	return 0;
}