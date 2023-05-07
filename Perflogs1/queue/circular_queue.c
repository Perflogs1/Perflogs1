#include<stdio.h>
#include<stdlib.h>
#define size 100
struct queue{
    int arr[size];
    int front;
    int rear;
};
struct queue *createqueue()
{
    struct queue *q=(struct queue*)malloc(sizeof(struct queue));
    q->front=0;
    q->rear=0;
    return q;
}
int isEmpty(struct queue *q)
{
    if(q->front==q->rear)
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
        printf("Queue is full \n");
        return;
    }
    q->arr[q->rear]=data;
    q->rear=(q->rear+1)%size;
}

int dequeue(struct queue *q)
{
    int data;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        exit(1);
    }
    
    data=q->arr[q->front];
    q->front=(q->front+1)%size;
    return data;
}

void display(struct queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        return;
    }
    printf("Queue contents \n");
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *q=createqueue();
    int choice,data;
    do{
        printf("1-Enqueue \n");
        printf("2-Dequeue \n");
        printf("3-Display \n");
        printf("4-Exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
        printf("Enter element to be entered: ");
        scanf("%d",&data);
        enqueue(q,data);
        break;
        case 2:
        data=dequeue(q);
        printf("Enter element deleted: %d \n",data);
        break;
        case 3:
        printf("Display queue: \n");
        display(q);
        break;
        case 4:
        printf("Exitting the program \n ");
        exit(1);
        break;
        default:
        printf("Invalid choice,try again \n");
        break;
        }
        
    }while(choice!=4);
    return 0;
}
