#define HEAP_MAX_heap_size 65536
#define push(data) heap[++heap_size] = data; sort_push();
#define pop(data) data = heap[1]; heap[1] = heap[heap_size--]; sort_pop();

typedef struct DATA {
	int key;
}data;

data heap[65536];
int heap_size;

void sort_push() {
	register int i, j;
	data tmp;
	
	i = heap_size;
	while(i != 1) {
		j = i / 2;
		if(heap[i].key < heap[j].key) {
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
	while(j = i * 2, j < heap_size) {
		j = heap[j].key<heap[j+1].key?j:j+1;
		if(heap[i].key > heap[j].key) {
			tmp = heap[j];
			heap[j] = heap[i];
			heap[i] = tmp;
			i = j;
		}
		else break;
	}
	if(j == heap_size)
		if(heap[i].key > heap[j].key) {
			tmp = heap[j];
			heap[j] = heap[i];
			heap[i] = tmp;
		}
}