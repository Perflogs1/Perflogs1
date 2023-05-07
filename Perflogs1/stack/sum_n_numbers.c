#include<stdio.h>
#include<stdlib.h>
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
        printf("Stack undeflow \n");
        exit(1);
    }
    data=s.arr[s.top--];
    return data;
}

void sum(int num)
{
    int sum=0;
    for(int i=1;i<=num;i++)
    {
        push(i);
        sum+=i;
        pop();
    }
    printf("The sum of first n numbers is %d \n",sum);
}

int main()
{
    s.top=-1;
    int num;
    printf("Enter the number \n");
    scanf("%d",&num);
    sum(num);
}

