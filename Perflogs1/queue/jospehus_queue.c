#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front, rear, size;
    int capacity;
    int *array;
};

struct queue *createQueue(int capacity)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (int *)malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(struct queue *q, int item)
{
    if (q->size == q->capacity)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size++;
}

int dequeue(struct queue *q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int main()
{
    int A, B;
    printf("Enter the total number of people: ");
    scanf("%d", &A);
    printf("Enter the value to be skipped: ");
    scanf("%d", &B);

    struct queue *q = createQueue(100);

    for (int i = 1; i <= A; i++)
    {
        enqueue(q, i);
    }

    while (q->size > 1)
    {
        for (int i = 0; i < B - 1; i++)
        {
            enqueue(q, dequeue(q));
        }
        printf(" The element is dequeued is %d \n", dequeue(q));
    }
    printf("\nThe survivor is %d\n", dequeue(q));

    return 0;
}

