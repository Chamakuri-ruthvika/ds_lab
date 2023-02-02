#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;  
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

void main()
{  
int choice =0;  
    while(1)  
    {  
        printf("\nENTER\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Show\n8.Exit\n");  
        printf("Enter your choice:\n");  
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
            printf("Please enter valid choice!");  
        }  
    }  
}  
void insert_beg()    
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("OVERFLOW\n");  
   }  
   else  
   {  
    printf("Enter Item value:");  
    scanf("%d",&item);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("Node inserted\n");  
}  
     
}  
void insert_end() 
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("OVERFLOW\n");  
   }  
   else  
   {  
       printf("Enter value:");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
       }  
     printf("node inserted\n");  
    }  
}

void insert_pos()  
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("node inserted\n");  
   }  
}  
void delete_beg()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("UNDERFLOW\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("node deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("node deleted\n");  
    }  
  
}  
void delete_end() 
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("UNDERFLOW\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("node deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("node deleted\n");  
    }  
}  
void delete_pos() 
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("Can't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("node deleted\n");  
    }     
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
