#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int a[SIZE];
int top = -1;
void push();
void pop();
void show();

void main()
{
	int top=-1,choice;
	while(1)
	{
		printf("enter 1 for push, 2 for pop, 3 for show, 4 for exit\n");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: push();
				break;
			case 2: pop();
		        	break;
			case 3: show();
				break;
			case 4:exit(0);
			default: printf("enter correct choice!!");
		}
	}
}
void push()
{
	int n;
	if(top==SIZE-1)
	{
		printf("stackOverflow\n");
	}
	else
	{
		top=top+1;
		printf("enter the number:");
		scanf("%d",&n);
		a[top]=n;
	}
}
void pop()
{
	if(top == -1)
	{
		printf("stackUnderflow\n");
	}
	else
	{
		printf("number removed is %d\n",a[top]);
		top--;
	}
}

void show()
{
	int i;
	if(top == -1)
	{
		printf("STACK EMPTY\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}