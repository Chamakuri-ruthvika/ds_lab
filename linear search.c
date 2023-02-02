#include <stdio.h>
int search(int a[100],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("%d is at %d location",a[i],i+1);
        }
    }
    
    return 0;

}
int rec_search(int l[],int key,int n,int i)
{
    if(i==n)
    {
        return -1;
    }
    else if(l[i]==key)
    {
        return (i+1);
    }
    else
    {
        return(rec_search(l,key,n,i+1));
    }
}
int main()
{
    int lst[100],n,i,key,result,k=0;
    printf("enter size of list:");
    scanf("%d",&n);
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&lst[i]);
    }
    printf("enter key:");
    scanf("%d",&key);
    search(lst,n,key);
    printf("\n");
    result=rec_search(lst,key,n,k);
    printf("position = %d",result);
}

