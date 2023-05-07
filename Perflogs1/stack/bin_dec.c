#include<stdio.h>
#include<stdlib.h>
#define size 100
struct stack{
    int arr[size];
    int top;
};
struct stack s;
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
void binary(int num)
{
    int rem=0;
    if(num==0)
    {
        printf("Binary equivalent is: %d \n",0);
        exit(1);
    }
    else if(num==1)
    {
        printf("Binary equivalent is %d \n",1);
    }
    
    while(num!=0)
    {
        rem=num%2;
        push(rem);
        num=num/2;
    }
    
    printf("the binary equivalent of the number is : \n");
    while(s.top!=-1)
    {
        printf("%d",pop());
    }
}

int main()
{
    s.top=-1;
    int n;
    printf("Enter a number : \n");
    scanf("%d",&n);
    binary(n);
    return 0;
}


