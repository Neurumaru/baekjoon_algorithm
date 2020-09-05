#define STACK_MAX_SIZE 65536
#define push(data) stack[stack_size++] = data
#define pop(data) data = stack[--stack_size]
#define is_empty() (stack_size == 0)

typedef struct DATA {
	int x, y, d;
}DATA;

DATA stack[STACK_MAX_SIZE];
int stack_size;