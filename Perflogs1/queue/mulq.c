#include<stdio.h>
#include<stdlib.h>
#define size 100
struct queue{
    int front;
    int rear;
    int arr[size];
} ;

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
    if(isFull(q))
    {
        printf("Queue overflow \n");
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
    
}

int dequeue(struct queue *q)
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue empty \n");
        return data;
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
    return data;
}

void display(struct queue *q)
{
    int i=q->front;
    for(i=q->front;i<q->rear+1;i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main()
{
    //struct queue Q1,Q2;
    
    struct queue *q1=create();
    struct queue *q2=create();
    int choice,data;
    printf("Enter the no of elements: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter data: ");
        scanf("%d",&data);
        enqueue(q1,data);
    }
    
   
    return 0;
}




