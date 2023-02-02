#include <stdio.h>
int search(int a[100],int start,int end,int key)
{
    int mid,flag=0;
    mid=(start+end)/2;
    while(start<=end)
    {
        if(a[mid]==key)
        {
            flag=1;
            break;
        }
        else if(key<a[mid])
        {
            end=mid-1;
        }    
        else
        {
            start=mid+1;
        }
    }
    if(flag==1)
    {
        printf("element is at %d",mid+1);
    }
    else{
        printf("element not found");
    }
}
int rec_search(int a[100],int key,int start,int end)
{
    int mid;
    mid=(start+end)/2;
    if(start<=end)
    {
        return -1;
    }
    else if(a[mid]==key)
    {
        return (mid+1);
    }
    else if(key<a[mid])
    {
        end=mid-1;
        return (rec_search(a,key,start,end));
    }
    else if(key>a[mid])
    {
        end=mid+1;
        return (rec_search(a,key,start,end));
    }
    else
    {
        return -1;
    }
}
void main()
{
    int a[100],n,key,i,result,end=n-1,start=0;
    printf("enter the size:");
    scanf("%d",&n);
    printf("enter array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the element to be found:");
    scanf("%d",&key);
    search(a,start,end,key);
    printf("\n");
    result=rec_search(a,key,start,end);
    printf("position=%d",result);
    
}

