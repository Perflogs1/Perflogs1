#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 100
struct stack{
    int arr[size];
    int top;
};
struct stack s;
int isEmpty()
{
    if(s.top==-1)
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
    if(s.top==size-1)
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
    s.arr[++s.top]=data;
}
int pop()
{
    int data;
    if(isEmpty())
    {
        printf("Stack underflow \n");
        exit(1);
    }
    data=s.arr[s.top--];
    return data;
}

void power(int num,int exponent)
{
    
    for(int i=0;i<=exponent;i++)
    {
        push(pow(num,i));
    }
    printf("The power of the number %d raised to the exponent %d  is %d \n",num,exponent,s.arr[s.top]);
}

int main()
{
    s.top=-1;
    int num,exponent;
    printf("Enter the base \n");
    scanf("%d",&num);
    printf("Enter the exponent \n");
    scanf("%d",&exponent);
    power(num,exponent);
    return 0;
}

