#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define size 100
#define takeoff 0 
#define landing 1 

typedef struct{
    int id;
    int type;
    int timestamp;
}Request;

typedef struct{
    Request arr[size];
    int front;
    int rear;
}Queue;

Queue *create()
{
    Queue *q=(Queue *)malloc(sizeof(Queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

int isEmpty(Queue *q)
{
    if(q->front==-1 && q->rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Queue *q)
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

void enqueue(Queue *q, Request req)
{
    if(isFull(q))
    {
        printf("Queue is full \n");
        return;
    }
    else if(isEmpty(q))
    {
        q->front=q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%size;
    }
    q->arr[q->rear]=req;
    printf("The request %d has been added to the queue \n",req.id);
}

Request dequeue(Queue *q)
{
    Request req;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        return req;
    }
    if(q->front==q->rear)
    {
        req=q->arr[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        req=q->arr[q->front];
        q->front=(q->front+1)%size;
    }
    printf("Request %d has been removed from queue \n",req.id);
    return req;
}

int main()
{
    srand(time(NULL));
    Request runway1={0,0};
    Request runway2={0,0};
    Queue *takeoff_queue=create();
    Queue *landing_queue=create();
    for(int i=1;i<=120;i++)
    {
        float r=(float)rand()/(float)RAND_MAX;
        bool is_landing=(r<0.5);
        if(is_landing)
        {
            Request req={i,is_landing};
            enqueue(landing_queue,req);
            printf("Landing request added to Queue at time %d \n ",i);
        }
        else
        {
            Request req={i,is_landing};
            enqueue(takeoff_queue,req);
            printf("Takeoff request added to Queue at time %d \n ",i);
        }
    }
    return 0;
}
