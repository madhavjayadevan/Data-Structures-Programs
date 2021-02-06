#include<stdio.h>
#include<stdlib.h>
int arr[20],n;
void read(int x)
{
    int i;
    printf("Enter the elements:\n");
    for(i=0;i<x;i++)
        scanf("%d",&arr[i]);
}
void display()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void linear(int x)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(x==arr[i])
        {
            printf("ELement found.");
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\nElement not found.\n");
}
void binary(int x)
{
    int temp,beg=0,mid,end,i,j,flag=0;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    display();
    end=n-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(arr[mid]==x)
        {
            printf("\nelement found");
            flag=1;
            break;
        }
        else if(arr[mid]>x)
            end=mid-1;
        else
            beg=mid+1;
    }
    if(flag==0)
        printf("\nElement not found.\n");
}
int main()
{
    int ch,a;
    while(1)
    {
        printf("\nMENU:\n1.Enter the array.\n2.Linear search.\n3.Binary search.\n4.Exit.\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nEnter the number of elements in array: ");
                scanf("%d",&n);
                read(n);
                break;
        case 2: printf("Enter the element to search: ");
                scanf("%d",&a);
                linear(a);
                break;
        case 3: printf("Enter the element to search: ");
                scanf("%d",&a);
                binary(a);
                break;
        case 4: exit(0);
                break;
        }
    }
    return 0;
}