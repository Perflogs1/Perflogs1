#include<stdio.h>
#include<stdlib.h>
#define size 100
int stack[size];
int top=-1;
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    if(isFull())
    {
        printf("Stack overflow \n");
        exit(1);
    }
    stack[++top]=data;
}
int pop()
{
    int data;
    if(isEmpty())
    {
        printf("Stack underflow \n");
        exit(1);
    }
    data=stack[top--];
    return data;
}

void fact(int num)
{
    int fact=1;
    if(num==0)
    {
        printf("The factorial of number is %d \n",0);
        exit(1);
    }
    for(int i=1;i<=num;i++)
    {
        fact=fact*i;
        push(fact);
    }
    printf("The factorial of the number %d is %d \n",num,stack[top]);
    
    
}

int main()
{
    int n;
    printf("Enter a number \n");
    scanf("%d",&n);
    fact(n);
    return 0;
}
