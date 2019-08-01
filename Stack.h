typedef struct 
{
	char data;
	int data2;
	struct Node * next;
} Node;

typedef struct
{
	int size;
	Node * head;
	Node * tail;
} Stack;

Node * initNode(char data, int digit);

void destroyNode(Node *node);

Stack * initStack();

int stackSize(Stack *stack);

int isEmpty(Stack *stack);

void destroyStack(Stack *stack);

void push(Stack *stack, char value, int digit);

Node * pop(Stack *stack);

void printStack(Stack *stack);
