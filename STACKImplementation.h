typedef char item;

typedef struct{
	int count;
	char Input[100];
} Stack;

void InitializeStack(Stack*);
int Empty(Stack*);
int FUll(Stack*);
void pop(Stack*, item*);
void push(Stack*, item);
char get_top(Stack*,int);
