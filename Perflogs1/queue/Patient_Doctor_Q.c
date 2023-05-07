#include<stdio.h>
#include<stdlib.h>
#define size 10
typedef struct{
    char name[50];
    int age;
}Patient;

typedef struct{
    Patient items[size];
    int front;
    int rear;
    
}Queue;

Queue *create()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
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
    if(q->rear+1%size==q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q,Patient p)
{
    if(isFull(q))
    {
        printf("Queue is full \n");
        exit(1);
    }
    if(isEmpty(q))
    {
        q->front=q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%size;
    }
    q->items[q->rear]=p;
    printf("Patient %s has been added to the queue \n",p.name);
}

Patient dequeue(Queue *q)
{
    Patient p;
    if(isEmpty(q))
    {
        printf("Queue is Empty \n");
        return p;
    }
    if(q->front==q->rear)
    {
        p=q->items[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        
        p=q->items[q->front];
        q->front=(q->front+1)%size;
    }
    printf("Patient %s has been removed from the queue \n",p.name);
    return p;
}

int main()
{
    Queue *q=create();
    Patient p;
    int numpatients;
    printf("Enter the no of patients \n");
    scanf("%d",&numpatients);
    for(int i=0;i<numpatients;i++)
    {
        printf("Enter the age of patient %d: ",i+1);
        scanf("%d",&p.age);
        printf("Enter the name of patient %d: ",i+1);
        scanf("%s",&p.name);
        enqueue(q,p);
    }
    printf("\n Patients are waiting to see a doctor \n");
    while(!isEmpty(q))
    {
        p=dequeue(q);
         printf("Patient %s has been assigned to doctor \n",p.name);
    }
    printf("All patients have been seen \n");
    return 0;
    
}

