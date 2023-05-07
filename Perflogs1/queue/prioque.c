#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void Enqueue(int data) {
  if (rear == MAX_SIZE - 1) {
    printf("Queue overflow\n");
    return;
  }
  if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = data;
    return;
  }
  int i;
  for (i = rear; i >= front; i--) {
    if (data > queue[i]) {
      queue[i + 1] = queue[i];
    } else {
      break;
    }
  }
  queue[i + 1] = data;
  rear++;
}

void Dequeue() {
  if (front == -1 || front > rear) {
    printf("Queue underflow\n");
    return;
  }
  printf("Dequeued element: %d\n", queue[front]);
  front++;
}

void PrintQueue() {
  if (front == -1 || front > rear) {
    printf("Queue is empty\n");
    return;
  }
  int i;
  printf("Queue: ");
  for (i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice;
  while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1: {
        int data;
        printf("Enter data to enqueue: ");
        scanf("%d", &data);
        Enqueue(data);
        break;
      }
      case 2: {
        Dequeue();
        break;
      }
      case 3: {
        PrintQueue();
        break;
      }
      case 4: {
        exit(0);
      }
      default: {
        printf("Invalid choice\n");
      }
    }
  }
  return 0;
}