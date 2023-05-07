#include<stdio.h>
#include<stdlib.h>
#define size 5
typedef struct{
    int id;
    int processing_time;
    int remaining_time;
}Job;
typedef struct{
    Job arr[size];
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

int isFull(Queue * q)
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

void enqueue(Queue *q,Job job)
{
    if(isFull(q))
    {
        printf("Queue is full \n");
        return;
    }
    if(isEmpty(q))
    {
        q->front=q->rear=0;
    }
    else
    {
        q->rear=(q->rear+1)%size;
    }
    q->arr[q->rear]=job;
    printf("Job J%d has been added to queue \n",job.id);
}

Job dequeue(Queue *q)
{
    Job job;
    if(isEmpty(q))
    {
        printf("Queue is empty \n");
        Job empty_job={0,0,0};
        return empty_job;
    }
    if(q->front==q->rear)
    {
       job= q->arr[q->front];
        q->front=q->rear=-1;
    }
    else
    {
        job= q->arr[q->front];
        q->front=(q->front+1)%size;
    }
    printf("Job J%d has been removed from queue \n",job.id);
    return job;
}

void process_jobs(Queue *q,int n)
{
    int current_time=0;
    while(!isEmpty(q))
    {
        Job current_job=dequeue(q);
        if(current_job.remaining_time>n)
        {
            current_job.remaining_time-=n;
            current_time+=n;
            printf("Processing J%d for %d seconds(remaining time %d) \n",current_job.id,n,current_job.remaining_time);
            enqueue(q,current_job);
        }
        else
        {
            current_time+=current_job.remaining_time;
            printf("Processing J%d for %d seconds(completed) \n",current_job.id,current_job.remaining_time);
        }
    }
    printf("All jobs are completed at time %d \n",current_time);
}
int main()
{
    int n,t1,t2,t3;
    Queue *q=create();
    printf("Enter the processing times for J1,J2 and J3 \n");
    scanf("%d %d %d",&t1,&t2,&t3);
    printf("Enter time quantum(in seconds) \n");
    scanf("%d",&n);
    Job job1={1,t1,t1};
    Job job2={2,t2,t2};
    Job job3={3,t3,t3};
    enqueue(q,job1);
    enqueue(q,job2);
    enqueue(q,job3);
    printf("Jobs J1,J2 and J3 are added to the queue \n");
    process_jobs(q,n);
    return 0;
}



