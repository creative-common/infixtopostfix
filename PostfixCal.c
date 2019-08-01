#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "Stack.h"
#include "Stack.c"

#include "Queue.h"
#include "Queue.c"


/****
 * *
 * Here inside the queue I will store either char or digit
 * For digit place as null I would use secret number 7001
 * For char as null I would use secret character n
 * */
int isOperator(char c);
queue * infixToPostfix(char infix[], int infixSize);
queue * infixToPostfix2(char infix[], int infixSize);
int evaluateInfix(char infix[], int infixSize);


int main(int argc, char *argv[]) {
  printf("Running the program...\n");

char infix[18] = {'(','8' ,'+' ,'2' ,'*' ,'5',')' ,'/' ,'(','1', '+' ,'3' ,'*' ,'2' ,'-' ,'4' ,')' };

           

  int isValid = evaluateInfix(infix, 18);

  //Validating the characters inside the array
  printf("infix is  %s \n", isValid ? "valid": "invalid");

  if(isValid){
    queue *q = infixToPostfix2(infix, 18); //Get the return type queue
    printf("******************************\n"); 
    printf("Displaying the Final Queue:\n");
    printf("******************************\n"); 
    display(q->front);
    printf("Now the arithmetic calculation begins:\n");
    arithmeticCalc(q);
  }

  return EXIT_SUCCESS;
}

void arithmeticCalc(queue * q){
    
    Stack *newStack = initStack(); //Created the stack
    
        // while(!isempty(q)){ // While queue is not empty
        //     node *value = dequeue(q);
        //     //    if(!isempty(q)){
        //     //     display(q->front);
        //     // }
        //     printf("Dequeued value %c %i \n", value->data, value->data2 );
         
        // }

    while(!isempty(q)){ // While queue is not empty
        node *value = dequeue(q);
        printf("Dequeued value %c %i \n", value->data, value->data2 );
        // display(q->front);
        if(value->data == 'n'){  
            printf("Pushing the value %i in newStack\n", value->data2);
            push(newStack, 'n', value->data2);
            printf("stack now contain: \n");
            printStack(newStack); 
        }
        // //value would be operator number in char section of the node
        if(value->data != 'n'){
              Node * op1 = pop(newStack);
              Node * op2 = pop(newStack);

              int operand1 = op1->data2; //right hand side variable
              int operand2 = op2->data2; //left hand side variable

              printf("operand1 is %i\n", operand1);
              printf("operand2 is %i\n", operand2);

            if(value->data == '+'){
               printf("doing the addition\n");
               int result = operand2 + operand1;
               printf("result is %i and pushing it into stack\n", result);
               push(newStack, 'n', result);
               printf("stack now contain: \n");
               printStack(newStack);
            }

            if(value->data == '-'){
               printf("doing the substraction\n");
               int result = operand2 - operand1;
                 printf("result is %i and pushing it into stack\n", result);
               push(newStack, 'n', result);
               printf("stack now contain: \n");
               printStack(newStack);
            }

            if(value->data == '/'){
               printf("doing the division\n");
               int result = operand2 / operand1;
               printf("result is %i and pushing it into stack\n", result);
               push(newStack, 'n', result);
               printf("stack now contain: \n");
               printStack(newStack);
            }

            if(value->data == '*'){
               printf("doing the multiplication\n");
               int result = operand2 * operand1;
               printf("result is %i and pushing it into stack\n", result);
               push(newStack, 'n', result);
               printf("stack now contain: \n");
               printStack(newStack);
            }
        }   
    }
}

queue * infixToPostfix2(char infix[], int infixSize){
    Stack *s = initStack(); //Created the stack
    queue *q;//Created the queue
    q = malloc(sizeof(queue)); //Allocate the size
    initialize(q);  //Intialized the queue
    int i = 0;
    while (i < infixSize){

        if(infix[i] == '('){
            printf("pushing %c to the stack\n", infix[i]);
            push(s, infix[i], 7001);

            printf("stack now contain: \n");
            printStack(s);     
        }

       if(isdigit(infix[i])){
            //char to int conversion
            char number[10];
            char arr[2];
            arr[0] = infix[i];
            arr[1] = '\0';
            strcpy(number, arr);
            int val = atoi(number);
            int val2 = val + 0;
            printf("adding %i to the queue\n", val);
            enqueue(q, 'n', val2);

            printf("queue now contain: \n");
            display(q->front);
        }

        if(infix[i] == ")"){
            while(1){
                    if(isEmpty(s)){
                        printf("stack is empty\n");
                        break;
                    }
                    // Pop the values from the stack until we don't get the ')' as value
		            Node * temp = pop(s);
                    //Add the all operators except ')'
                    printf("Poping the %c from stack\n", temp->data);
                    char x = temp->data;
                    if(isOperator(x)){
                          printf("adding %c to the queue\n", x);
                          enqueue(q, 'n', x);

                          printf("queue now contain: \n");
                          display(q->front);
                    }else{
                        break; // end the while loop
                    }
            }
        }

        if(infix[i] == '*' || infix[i] == '/'){
             printf("Inside the infix i == * or /");
            printf("infix value is %c", infix[i]);
            while(1){
                    if(isEmpty(s)){
                        printf("stack is empty\n");
                        break;
                    }
                    // Pop the values from the stack until we don't get the ')' as value
		            Node * temp = pop(s);
                    //Add the all operators except ')'
                    printf("Poping the %c from stack\n", temp->data);
                    char x = temp->data;

                    if(x == '('){
                        break; //endwhile loop
                    }
                    if(x == '-' || x == '+'){
                        printf("pushing %c to the stack\n", x);
                        push(s, x, 7001);

                        printf("stack now contain: \n");
                        printStack(s);     

                        printf("pushing %c to the stack\n", infix[i]);
                        push(s, infix[i], 7001);

                        printf("stack now contain: \n");
                        printStack(s);    
                    }
                    if(x == '*' || x == '/'){
                         printf("adding %c to the queue\n", x);
                         enqueue(q, x, 7001);

                        printf("queue now contain: \n");
                        display(q->front);
                    }
            }
        }

        if(infix[i] == '-' || infix[i] == '+'){
            printf("Inside the infix i == - or +");
            printf("infix value is %c", infix[i]);
            while(1){
                    // Pop the values from the stack until we don't get the ')' as value
                    if(isEmpty(s)){
                        printf("stack is empty\n");
                        break;
                    }

                    Node * temp = pop(s);
                    //Add the all operators except ')'
                    printf("Poping the %c from stack\n", temp->data);
                    char x = temp->data;

                    if(isOperator(x)){
                         printf("adding %c to the queue\n", x);
                         enqueue(q, x, 7001);

                        printf("queue now contain: \n");
                        display(q->front);
                    }else{
                        printf("pushing %c to the stack\n", x);
                        push(s, x, 7001);

                        printf("stack now contain: \n");
                        printStack(s);     

                        printf("pushing %c to the stack\n", infix[i]);
                        push(s, infix[i], 7001);

                        printf("stack now contain: \n");
                        printStack(s);   

                        break;
                    }
            }
        }
        i++; //increment
    }
    return q;

}

int isOperator(char c){
    if(c == '*' || c == '/' || c == '-' || c == '+'){
        return 1;
    }else{
        return 0;
    }
}

queue * infixToPostfix(char infix[], int infixSize){
  
    Stack *s = initStack(); //Created the stack
    queue *q;//Created the queue
     q = malloc(sizeof(queue)); //Allocate the size
    initialize(q);  //Intialized the queue

    for(int i=0; i<infixSize; i++){
      //  If character is number than insert into queue
        if(isdigit(infix[i])){
            //char to int conversion
            char number[10];
            char arr[2];
            arr[0] = infix[i];
            arr[1] = '\0';
            strcpy(number, arr);
            int val = atoi(number);
            int val2 = val + 0;
            printf("adding %i to the queue\n", val);
            enqueue(q, 'n', val2);

            printf("queue now contain: \n");
            display(q->front);
        }

        if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+'  || infix[i] == '-' || infix[i] == '('){
            
            printf("pushing %c to the stack\n", infix[i]);
            push(s, infix[i], 7001);

            printf("stack now contain: \n");
            printStack(s);            

        }

        if(infix[i] == ')'){
                while(1){
                    // Pop the values from the stack until we don't get the ')' as value
		            Node * temp = pop(s);
                    //Add the all operators except ')'
                    printf("Poping the %c from stack\n", temp->data);

                    if(temp->data != '('){
                        printf("Adding %c to queue\n", temp->data);
                        enqueue(q, temp->data, 7001);
                        printf("queue now contain: \n");
                        display(q->front);
                    }
                   
		            if(temp->data == '('){ 
                        printf("Got the break ( in stack \n");
                        break;
		            }
		        }
              
        }

        // If iteration is about to finish and stack is not empty than 
        // Add the remaining characters into the queue except the ')'
        if((i+1) == infixSize && stackSize(s) != 0){
             printf("End of array and stack is not empty & stack size is %d\n", stackSize(s));	
             printf("remaining stack elements: \n");
             printStack(s);

                while(stackSize(s)!=0){
                    // Pop the values from the stack until we don't get the '(' as value
		            Node * temp2 = pop(s);
                  
                    // Add the all operators except '('
                    if(temp2->data != '('){
                         enqueue(q, temp2->data, 7001);
                         printf("popped data is %c \n", temp2->data);
                         
                         printf("latest postfix is: \n");
                         display(q->front);
                    }
                   
		        }
        }
    }

    return q;
}


/***********
* To check there is no character other than number and * / + - operators
************/
int evaluateInfix(char infix[], int infixSize){
    for(int i = 0; i<infixSize; i++){
        //If digit is number or given operator then return true otherwise false;
        if(!isdigit(infix[i]) && infix[i] != '*' && infix[i] != '/' && infix[i] != "+"  && infix[i] != "-" && infix[i] == '(' && infix[i] == ')'){
            return 0; //False Invalid Infix value
        }
    }
    return 1; //True infix is valid 
}






