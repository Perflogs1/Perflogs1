#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue implementation
typedef struct {
  int front, rear;
  int items[MAX_SIZE];
} queue;

void init_queue(queue *q) {
  q->front = -1;
  q->rear = -1;
}

int is_empty(queue *q) {
  return (q->front == -1 && q->rear == -1);
}

int is_full(queue *q) {
  return (q->rear == MAX_SIZE - 1);
}

void enqueue(queue *q, int x) {
  if (is_full(q)) {
    printf("Queue overflow\n");
    exit(1);
  } else if (is_empty(q)) {
    q->front = q->rear = 0;
  } else {
    q->rear++;
  }
  q->items[q->rear] = x;
}

int dequeue(queue *q) {
  int x;
  if (is_empty(q)) {
    printf("Queue underflow\n");
    exit(1);
  } else if (q->front == q->rear) {
    x = q->items[q->front];
    q->front = q->rear = -1;
  } else {
    x = q->items[q->front];
    q->front++;
  }
  return x;
}

int peek(queue *q) {
  if (is_empty(q)) {
    printf("Queue underflow\n");
    exit(1);
  } else {
    return q->items[q->front];
  }
}

int size(queue *q) {
  if (is_empty(q)) {
    return 0;
  } else {
    return q->rear - q->front + 1;
  }
}

int main() {
  queue regular, frequent;
  int n, i, j, k, strategy, total_wait_regular, total_wait_frequent;
  float avg_wait_regular, avg_wait_frequent;
  init_queue(&regular);
  init_queue(&frequent);
  printf("Enter the number of passengers: ");
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    printf("Enter the type of passenger (1 for regular, 2 for frequent): ");
    scanf("%d", &j);
    if (j == 1) {
      enqueue(&regular, i);
    } else if (j == 2) {
      enqueue(&frequent, i);
    } else {
      printf("Invalid type of passenger\n");
      i--;
    }
  }
  printf("Enter the strategy for taking passengers from the waiting lines (1 for alternate, 2 for regular first, 3 for frequent first): ");
  scanf("%d", &strategy);
  total_wait_regular = total_wait_frequent = 0;
  if (strategy == 1) {
    while (!is_empty(&regular) || !is_empty(&frequent)) {
      if (!is_empty(&regular)) {
        k = dequeue(&regular);
        total_wait_regular += size(&frequent);
      }
      if (!is_empty(&frequent)) {
        k = dequeue(&frequent);
        total_wait_frequent += size(&regular);
      }
    }
  } else if (strategy == 2) {
    while (!is_empty(&regular)) {
      k = dequeue(&regular);
      total_wait_regular += size(&frequent);
    }
    while (!is_empty(&frequent)) {
      k = dequeue(&frequent);
      total_wait_frequent += size(&regular);
    }
  } else if (strategy == 3) {
    while (!is_empty(&frequent)) {
      k = dequeue(&frequent);
      total_wait_frequent += size(&regular);
    }
    while (!is_empty(&regular)) {
      k = dequeue(&regular);
      total_wait_regular += size(&frequent);
    }
  } else {
    printf("Invalid strategy\n");
    exit(1);
  }
  avg_wait_regular = (float) total_wait_regular / n;
  avg_wait_frequent = (float) total_wait_frequent / n;
  printf("Average waiting time for regular customers: %.2f\n", avg_wait_regular);
  printf("Average waiting time for frequent flyers: %.2f\n", avg_wait_frequent);
  return 0;
}