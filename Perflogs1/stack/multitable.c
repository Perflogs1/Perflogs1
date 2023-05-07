#include<stdlib.h>
#include<stdio.h>
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

void table(int num,int limit)
{
    int prod=1;
    int limit1=1;
    int limit2=limit;
    while(limit!=0)
    {
        prod=num*limit;
        push(prod);
        limit--;
    }
    printf("The multiplication table is as follows \n");
    while(s.top!=-1&&limit1<=limit2)
    {
        printf("%d x %d = %d \n",num,limit1,pop());
        limit1++;
    }
}

int main()
{
    s.top=-1;
    int n;
    printf("Enter the number \n");
    scanf("%d",&n);
    int limit;
    printf("Enter the limit \n");
    scanf("%d",&limit);
    table(n,limit);
    return 0;
}

