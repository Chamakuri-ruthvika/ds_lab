#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *head;  
  
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
    while(choice != 9)   
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
    struct node *ptr=malloc(sizeof(struct node *));  ;  
    int key;  
    printf("Enter value:");    
    scanf("%d",&key);    
    ptr->data = key;  
    ptr->next = head;  
    head = ptr;  
    printf("Node inserted\n");  
}

void insert_end()  
{  
    struct node *ptr,*temp;  
    int key;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    printf("Enter value:");  
    scanf("%d",&key);  
    ptr->data = key;  
    if(head == NULL)  
    {  
        ptr -> next = NULL;  
        head = ptr;  
        printf("Node inserted\n");  
    }  
    else  
    {  
        temp = head;  
        while (temp -> next != NULL)  
        {  
            temp = temp -> next;  
        }  
        temp->next = ptr;  
        ptr->next = NULL;  
        printf("Node inserted\n");  
      
    }  
}

void insert_pos()  
{  
    int i,loc,key;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    printf("Enter value:");  
    scanf("%d",&key);  
    ptr->data = key;  
    printf("Enter the location after which you want to insert ");  
    scanf("%d",&loc);  
    temp=head;  
    for(i=0;i<loc;i++)  
    {  
        temp = temp->next;  
        if(temp == NULL)  
        {  
            printf("can't insert\n");  
            return;  
        }  
      
    }  
    ptr ->next = temp ->next;   
    temp ->next = ptr;   
    printf("Node inserted\n");  
} 

void delete_beg()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("Node deleted\n");  
    }  
}  
void delete_end()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("list is empty\n");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("node deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("Node deleted\n");  
    }     
}  
void delete_pos()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("Enter the location to perform deletion: \n");  
    scanf("%d",&loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("Can't delete\n");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("Deleted node %d\n ",loc+1);  
}  

void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("empty");  
    }  
    else  
    {  
        printf("values are:\n");   
        while (ptr!=NULL)  
        {  
            printf("%d ",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
}     