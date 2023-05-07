#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int front;
  int rear;
  int size;
} Queue;

void initQueue(Queue *q) {
  q->front = 0;
  q->rear = -1;
  q->size = 0;
}

int isQueueEmpty(Queue *q) {
  return q->size == 0;
}

int isQueueFull(Queue *q) {
  return q->size == MAX_SIZE;
}

void enqueue(Queue *q, int value) {
  if (isQueueFull(q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX_SIZE;
  q->data[q->rear] = value;
  q->size++;
}

int dequeue(Queue *q) {
  if (isQueueEmpty(q)) {
    printf("Queue is empty\n");
    return -1;
  }
  int value = q->data[q->front];
  q->front = (q->front + 1) % MAX_SIZE;
  q->size--;
  return value;
}

int main() {
  int n, i, j, count, customer, teller_count, wait_time, total_wait_time;

  printf("Enter the number of customers: ");
  scanf("%d", &n);

  Queue q;
  initQueue(&q);

  for (i = 1; i <= n; i++) {
    enqueue(&q, i);
  }

  printf("Enter the number of tellers: ");
  scanf("%d", &teller_count);

  count = 0;
  wait_time = 0;
  total_wait_time = 0;

  while (!isQueueEmpty(&q)) {
    customer = dequeue(&q);
    count++;
    if (count <= teller_count) {
      wait_time = 0;
    } else {
      wait_time++;
      total_wait_time += wait_time;
    }
    printf("Customer %d is being served by teller %d (wait time: %d)\n", customer, count % teller_count, wait_time);
  }

  printf("Average wait time: %.2f\n", (float)total_wait_time / n);

  return 0;
}


