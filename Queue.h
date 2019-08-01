
#define TRUE 1
#define FALSE 0
#define FULL 40

struct node
{
    char data;
    int  data2;
    struct node *next;
};
typedef struct node node;

struct queue
{
    int count;
    node *front;
    node *rear;
};
typedef struct queue queue;

void initialize(queue *q);

int isempty(queue *q);

void enqueue(queue *q, char operator, int digit);

node * dequeue(queue *q);

void display(node *head);