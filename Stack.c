Node * initNode(char data, int digit)
{
	Node * n = malloc(sizeof(Node));
	
	n->data = data;
	n->data2 = digit;
	n->next = 0;
	
	return n;
}

void destroyNode(Node *node)
{
	node->next = 0;
	
	free(node);
}

Stack * initStack()
{
	Stack * s = malloc(sizeof(Stack));
	
	s->head = 0;
	s->tail = 0;
	s->size = 0;
	
	return s;
}

int stackSize(Stack *stack)
{
	if(stack == 0)
	{
		return -1;
	}
	else
	{
		return stack->size;
	}
}

int isEmpty(Stack *stack)
{
	return stackSize(stack) == 0;
}

void destroyStack(Stack *stack)
{
	if(isEmpty(stack))
	{
		free(stack);
	}
	else
	{
		Node * curr = stack->head;
		while(curr != 0)
		{
			Node * temp = curr;
			curr = curr->next;
			
			free(temp);
		}
	}
}

void push(Stack *stack, char value, int digit)
{
	Node * newNode = initNode(value, digit);
	
	if(isEmpty(stack))
	{
		newNode->next = 0;
		
		stack->head = newNode;
		stack->tail = newNode;
	}
	else
	{
		newNode->next = stack->head;
		stack->head = newNode;
	}
	
	stack->size++;
}

Node * pop(Stack *stack)
{
	if(isEmpty(stack))
	{
		return 0;
	}
	else
	{
		Node * result = stack->head;
		
		stack->head = stack->head->next;
		
		stack->size--;
		
		return result;
	}
}

void printStack(Stack *stack)
{
	printf("Stack: ");
	
	if(isEmpty(stack))
	{
		printf("is empty!\n");
	}
	else
	{
		for(Node * temp = stack->head; temp != 0; temp = temp->next)
		{
			if(temp->data2 == 7001){
            printf("%c ", temp -> data);
			}
			if(temp->data == 'n'){
				printf("%i ", temp -> data2);
			}
		}
		
		printf("\n");
	}
}