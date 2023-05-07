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
  int n, m, i, j, count, soldier;

  printf("Enter the number of soldiers: ");
  scanf("%d", &n);

  Queue q;
  initQueue(&q);

  for (i = 1; i <= n; i++) {
    enqueue(&q, i);
  }

  printf("Enter the value of m: ");
  scanf("%d", &m);

  count = 0;

  while (q.size > 1) {
    for (i = 0; i < m - 1; i++) {
      soldier = dequeue(&q);
      enqueue(&q, soldier);
    }
    soldier = dequeue(&q);
    count++;
    if (count == m) {
      count = 0;
    } else {
      enqueue(&q, soldier);
    }
  }

  printf("The soldier who will go out to seek help is: %d\n", dequeue(&q));

  return 0;
}
