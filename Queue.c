void initialize(queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q){
    return (q->rear == NULL);
}

void enqueue(queue *q, char operator, int digit){
    if (q->count < FULL)
    {
        node *tmp;
        tmp = malloc(sizeof(node));
        tmp->data = operator;
        tmp->data2 = digit;
        tmp->next = NULL;
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else
    {
        printf("List is full\n");
    }
}

node * dequeue(queue *q){
    node *tmp;
    char n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    // free(tmp);
    return tmp;
}

void display(node *head){
    
    if(head != NULL)
    {
        if(head->data2 == 7001){
            printf("%c ", head -> data);
        }
        if(head->data == 'n'){
            printf("%i ", head -> data2);
        }
        
        display(head->next);
    }else{
        // when NULL print the next line
        printf("\n");
    }
   
}