#include<stdio.h>
#include<stdlib.h>
#define size 100
struct queue{
    int arr[size];
    int front;
    int rear;
};
struct queue *create()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isEmpty(struct queue *q)
{
    if(q->front==-1 &&q->rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
{
    if(q->front==(q->rear+1)%size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q,int data)
{
    //int data;
    if(isFull(q))
    {
       printf("Queue is full \n");
       exit(1);
    }
    else if(isEmpty(q))
    {
        q->front=q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%size;
    }
    q->arr[q->rear]=data;
    printf("%d has been added to the queue \n",data);
}

int dequeue(struct queue *q)
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        exit(1);
    }
    else if(q->front==q->rear)
    {
        data=q->arr[q->front];
        q->front=q->rear=-1;
    }
    else
    {
       
        data=q->arr[q->front];
         q->front=(q->front+1)%size;
    }
    printf("%d has been removed from queue \n",data);
    return data;
}

int  replace(struct queue *q,int n1,int n2)
{
    int temp;
    int flg=0;
    int i=q->front;
    while(i!=q->rear+1)
    {
        if(n1==q->arr[i])
        {
            q->arr[i]=n2;
            flg=1;
            break;
        }
        i=(i+1)%size;
    }
    return flg;
}

void display(struct queue *q)
{
    int i=q->front;
    while(i!=q->rear+1)
    {
        printf("%d ",q->arr[i]);
        i=(i+1)%size;
    }
    printf("\n");
}

int main()
{
    
    struct queue *q=create();
    int choice,data;
    int num;
    printf("Enter the no of elements you want to enter in the queue: \n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        printf("Enter the data: ");
        scanf("%d",&data);
        enqueue(q,data);
    }
    int num1,num2;
    printf("Enter 1st element: ");
    scanf("%d",&num1);
    printf("Enter 2nd element: ");
    scanf("%d",&num2);
    if(replace(q,num1,num2))
    {
        printf("Element is replaced \n");
        printf("Changed queue \n");
        display(q);
    }
    else
    {
        printf("Element is not replaced \n");
    }
    return 0;
}
