#include<stdio.h>
#include<stdlib.h>
#define size 100
typedef struct {
    char name[100];
    char gender[100];
    int age;
}Passenger;
typedef struct{
    Passenger passenger[size];
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

void enqueue(Queue *q,Passenger p)
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
    q->passenger[q->rear]=p;
    printf("Passenger %s has been added to Queue \n",p.name);
}

Passenger dequeue(Queue *q)
{
    Passenger p;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        return p;
    }
    if(q->front==q->rear)
    {
        p=q->passenger[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        
        q->front=(q->front+1)%size;
    }
    p=q->passenger[q->front];
    printf("The Passenger has been removed from Queue \n");
    return p;
    
}

void display(Queue *q)
{
    Passenger p;
    printf("The info is \n");
            p=q->passenger[q->front];
            printf("Name of the Passenger: %s \n",p.name);
            printf("Gender of the Passenger: %s \n",p.gender);
            printf("Age of the Passenger: %d \n",p.age);
}

void displaypassengers(Queue *q)
{
    int c=0;
    int i=0;
    while(i<=q->rear-1)
    {
        c++;
        i++;
    }
    
    printf("No of Passenger in the Queue are %d \n",c);
    
}
int main()
{
    Passenger p;
    Queue *q=create();
    int choice;
    do{
        printf("1-Enter the Passenger details and enqueue it \n");
        printf("2-Dequeue the Passenger from the Queue \n");
        printf("3-Display the info of Passenger in the front \n");
        printf("4-Exitting the program \n");
        printf("Enter choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the info details of the Passenger \n");
            printf("Enter the name of the Passenger: ");
            fflush(stdin);
            gets(p.name);
            gets(p.name);
            printf("Enter the gender of the Passenger: ");
            scanf("%s",p.gender);
            printf("Enter the age of the Passenger: ");
            scanf("%d",&p.age);
            enqueue(q,p);
            break;
            
            case 2:
            if(!isEmpty(q))
            {
                p=dequeue(q);
            }
            
            break;
            
            case 3:
            display(q);
            break;
            
            case 4:
            displaypassengers(q);
            printf("Exitting the program \n");
            exit(1);
            break;
            
            default:
            printf("Invalid choice,try again \n");
            break;
            
        }
    }while(choice!=4);
    
    return 0;
}


