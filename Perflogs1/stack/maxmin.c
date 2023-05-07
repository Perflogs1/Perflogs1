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

int main()
{
    s.top=-1;
    int num;
    printf("Enter the size of the array/stack \n");
    scanf("%d",&num);
    int value;
    printf("Enter the values \n");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&value);
        push(value);
    }
    int max,min;
    max=-999999;
    min=999999;
    while(s.top!=-1)
    {
        int current=pop();
        if(current>max)
        {
            max=current;
        }
        if(current<min)
        {
            min=current;
        }
    }
    printf("The maximum element in the stack %d \n",max);
    printf("The minimum element in the stack %d \n",min);
    return 0;
}


