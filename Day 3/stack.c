#include<stdio.h>
int stack[5];
int top=-1;

void push(int x)
{
    if(top==4)
    printf("\nStack Full!!!\nFurther elements cannot be pushed!!!\n");
    else
    {
        top++;
        stack[top]=x;
        printf("\nPush successful\n");
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow !! Stack Empty\n");
    }
    else
    {
        printf("Poped Element: %d ",stack[top]);
        top--;
    }
}

void peek()
{
    if(top==-1)
    {
    printf("\nStack Empty!!\n");
    }
    else
    printf("Element at the top: %d",stack[top]);
}

void isempty()
{
    if(top==-1)
    printf("\nThe Stack is empty\n");
    else
    {
        printf("\nStack is not empty\n");
    }
}

void isfull()
{
    if(top==4)
    printf("\nThe stack is Full !!\n");
    else
    {
        printf("\nThe Stack is not full !!!\n");
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nUnderflow !! Stack Empty\n");
    }
    else
    {
        printf("Elements of the stack are:\n");
        for(i=top;i>-1;i--)
        printf("%d \n",stack[i]);
        printf("\n");
    }   
}

void main()
{
    int resp,x;
    printf("***************************************************************|||| STACK MENU ||||***************************************************************");
    do
    {
    printf("\n1. Push\n2. Pop\n3.Peek\n4. Isempty\n5. Is Full\n6. Display the Stack\n0. Exit\n\nYour Choice:");
    scanf("%d",&resp);
    switch (resp)
    {
    case 1:
        printf("Enter the Element to be pushed:");
        scanf("%d",&x);
        push(x);
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;        
    case 4:
        isempty();
        break;
    case 5:
        isfull();
        break;
    case 6:
        display();    
    default:
        break;
    }
    }while(resp!=0);
}