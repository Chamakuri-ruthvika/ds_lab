#include<stdio.h>
#include<stdlib.h>
 
#define MAX 50
int size;
 
struct stack
{
	int arr[MAX];
   	int top;
};
 
void init_stk(struct stack *st) 
{
   	st->top = -1;
}
 

void push(struct stack *st, int num) 
{
   	if (st->top == size - 1) 
	{
		printf("Stack overflow\n");
   	}
   	st->top++;
	st->arr[st->top] = num;
}
 
int pop(struct stack *st) 
{
	int num;
   	if (st->top == -1) 
	{
      		printf("Stack underflow\n");
      		
   	}
   	num = st->arr[st->top];
   	st->top--;
   	return num;
}
 
void display(struct stack *st) 
{
	int i;
   	for (i = st->top; i >= 0; i--)
	{
		printf("%d\n", st->arr[i]);
	}
}
 
int main() 
{
   	int element,opt,val;
   	struct stack ptr;
   	init_stk(&ptr);
   	printf("\nEnter Stack Size :");
   	scanf("%d", &size);
   	while (1) 
	{
      		printf("Enter 1 for push, 2 for pop, 3 for display, 4 for exit:\n ");
      		scanf("%d", &opt);
      		switch (opt)
       		{
			case 1:
         			printf("Enter the element into stack:");
         			scanf("%d", &val);
         			push(&ptr, val);
         			break;
      			case 2:
         			element = pop(&ptr);
         			printf("The element popped from stack is : %d\n", element);
         			break;
      			case 3:
         			printf("stack elements are:\n");
         			display(&ptr);
         			break;
      			case 4:
         			exit(0);
      			default:
         			printf("\nEnter correct option!Try again.");
      		}
   	}
   	return (0);
}