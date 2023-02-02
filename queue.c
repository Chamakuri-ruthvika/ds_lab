#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void delete();
void display();
int front=-1,rear=-1;
int queue[maxsize];
void main()
{
	int choice;
	while(choice!=4)
	{
		printf("--MAIN MENU:\n");
		printf("1.insert an element\n2.delete an element\n3.display queue\n4.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			       break;
			case 2:delete();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
			       break;
			default:printf("enter correct choice!!");
		}
	}
}

void insert()
{
	int item;
	printf("enter element:");
	scanf("%d",&item);
	if(rear==maxsize-1)
	{
		printf("OVERFLOW\n");
		return;
	}
	if(front==-1 && rear == -1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	queue[rear]=item;
	printf("value inserted!\n");
}
void delete()
{
	int item;
	if(front == -1 || front > rear)
	{
		printf("UNDERFLOW");
		return;
	}
	else
	{
		item == queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		printf("value deleted!!");
	}
}
void display()
{
	int i;
	if(rear == -1)
	{
		printf("empty queue");
	}
	else
	{
		printf("printing values:");
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}