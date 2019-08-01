
// Queue Test
void run_all_tests();
void test_all_queue();
void test_all_stack();

void run_all_tests() {
  test_all_stack();
  test_all_queue();
}


void test_all_queue() {
  printf("Inside the test all queue...\n");

    queue *q;
    q = malloc(sizeof(queue));
    initialize(q);
    enqueue(q,'q');
    enqueue(q,'w');
    enqueue(q,'e');
    printf("Queue before dequeue\n");
    display(q->front);
    char c = dequeue(q);
     printf("Dequeued value %c \n", c);
    printf("Queue after dequeue\n");
    display(q->front);
    return 0;
}


//Test the Stack.c and Stack.h


void test_all_stack(){
  printf("Creating new stack\n");
  Stack * stack = initStack();
	
	push(stack, 'A');
	push(stack, 'Z');
	push(stack, 'a');
  push(stack, 'z');
	
	printStack(stack);
	
	while(1)
	{
		Node * temp = pop(stack);
		
		if(temp == 0)
		{
			break;
		}
		
		printf("Popped element: %c\n", temp->data);
	}
	
	destroyStack(stack);


  
}