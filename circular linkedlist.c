#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *tail=NULL;
void insert_beg ();   
void insert_end ();  
void insert_pos();  
void delete_beg();  
void delete_end();  
void delete_pos();  
void display();
void main ()  
{  
    int choice=0;  
    while(1)   
    {  
        printf("\nENTER\n");  
        printf("1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Show\n8.Exit\n");  
        printf("Enter your choice:");         
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert_beg();      
            break;  
            case 2:  
            insert_end();         
            break;  
            case 3:  
            insert_pos();       
            break;  
            case 4:  
            delete_beg();       
            break;  
            case 5:  
            delete_end();        
            break;  
            case 6:  
            delete_pos();          
            break;  
            case 7:  
            display();        
            break;  
            case 8:  
            exit(0);  
            break;
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
} 

void insert_beg() 
{
    int num;
    struct node *newnode=malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d",&num);
    if(tail==NULL)
    {
        newnode->data=num;
        newnode->next=newnode;
        tail=newnode;
    }
    else
    {
        newnode->data=num;
        newnode->next=tail;
        tail->next=newnode;
        printf("inserted\n");
    }
}
void insert_end()
{
    int num;
    struct node *newnode=malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    printf("inserted\n");
    
}
void insert_pos()
{
    int i,pos,num;
    struct node *newnode=malloc(sizeof(struct node));
    struct node *ptr=tail->next;
    printf("enter position:");
    scanf("%d",&pos);
    printf("enter value:");
    scanf("%d",&num);
    for(i=1;i<pos;i++)
    {
        ptr=ptr->next;
    }
    newnode->data=num;
    newnode->next=ptr->next;
    ptr->next=newnode;
    printf("inserted\n");
}
void delete_beg()
{
    struct node *ptr=tail->next;
    tail->next=ptr->next;
    printf("deleted\n");
}
void delete_end()
{
    struct node *ptr=tail->next;
    while(ptr->next!=tail)
    {
        ptr=ptr->next;
    }
    ptr->next=tail->next;
    ptr=tail;
    printf("deleted\n");
}
void delete_pos() 
{
    int i,pos;
    struct node *ptr=tail->next;
    printf("enter position:");
    scanf("%d",&pos);
    for(i=1;i<pos;i++)
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
    printf("deleted\n");
    
}
void display()
{
    struct node *ptr;
    if(tail==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        ptr=tail->next;
        do
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=tail->next);
    }
}

