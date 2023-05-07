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
        printf("Stack underflow \n");
        exit(1);
    }
    data=s.arr[s.top--];
    return data;
}

void fibonacci(int n)
{
    int a,b,c;
    int i=1;
    a=0,b=1;
    push(a);
    push(b);
   
   while(i<=n-2)
   {
       c=a+b;
       push(c);
       a=b;
       b=c;
       i++;
   }
   
   printf("The fibonacci series for n terms is %d \n",n);
   while(s.top!=-1)
   {
       printf("%d ",pop());
   }
}

int main()
{
    s.top=-1;
    int n;
    printf("Enter a number \n");
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}

