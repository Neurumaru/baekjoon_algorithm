#define QUEUE_MAX_SIZE 250000
#define push(data) queue[head++] = data; head %= QUEUE_MAX_SIZE
#define pop(data) data = queue[tail++]; tail %= QUEUE_MAX_SIZE
#define is_empty() (head == tail)

typedef struct DATA{
	int x, y;
}DATA;

DATA queue[QUEUE_MAX_SIZE];
int head, tail;