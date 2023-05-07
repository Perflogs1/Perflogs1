#include<stdio.h>
#include<stdlib.h>
#define size 100
struct stack{
    int top;
    int arr[size];
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

void roomtraversal(int num)
{
     printf("The room traversal of room in order 1-5 is: \n");
    for(int j=1;j<=5;j++)
    {
        push(j);
        printf("Entering the room no: %d \n",j);
    }
    push(num);
    int binary[100];
    int d,i=0; 
    int num1=num;
    int c=0;
    while(num>0)
    {
     d=num%2;
     binary[i]=d;
     num=num/2;
     c++;
     i++;   
    }
    printf("\n");
    printf("The decimal no %d  converted to binary is: \n",num1);
    for(int j=c;j>=1;j--)
    {
        printf("%d",binary[j]);
    }
    printf("\n");
    int room;
    printf("The room traversal of room in order 5-3 is: \n");
    pop();
    while(s.top!=0)
    {
        room=pop();
        printf(" Leaving room no: %d \n",room);
    }
}

int main()
{
    int number;
    printf("Enter the decimal: ");
    scanf("%d",&number);
    roomtraversal(number);
    return 0;
}


