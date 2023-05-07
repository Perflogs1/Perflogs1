#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRIVAL_INTERVAL 5
#define MAX_TICKET_AGENT_TIME 10
#define MAX_SIMULATION_TIME 100

typedef enum {
    REGULAR,
    FREQUENT
} customer_type;

typedef struct {
    customer_type type;
    int arrival_time;
} customer;

typedef struct {
    customer *customers;
    int front;
    int rear;
} queue;

void init_queue(queue *q) {
    q->customers = malloc(sizeof(customer) * MAX_SIMULATION_TIME);
    q->front = -1;
    q->rear = -1;
}

int is_queue_empty(queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(queue *q, customer c) {
    if (is_queue_empty(q)) {
        q->front++;
    }
    q->rear++;
    q->customers[q->rear] = c;
}

customer dequeue(queue *q) {
    customer c = q->customers[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return c;
}

int main() {
    srand(time(NULL));  // seed random number generator

    queue regular_queue, frequent_queue;
    init_queue(&regular_queue);
    init_queue(&frequent_queue);

    int ticket_agent_busy_until = 0;
    int total_regular_waiting_time = 0, total_frequent_waiting_time = 0;
    int regular_customers_served = 0, frequent_customers_served = 0;

    for (int current_time = 0; current_time < MAX_SIMULATION_TIME; current_time++) {
        // generate customer arrival
        if (rand() % MAX_ARRIVAL_INTERVAL == 0) {
            customer c;
            c.arrival_time = current_time;
            c.type = rand() % 2 == 0 ? REGULAR : FREQUENT;
            if (c.type == REGULAR) {
                enqueue(&regular_queue, c);
            } else {
                enqueue(&frequent_queue, c);
            }
        }

                // server customer
        if (ticket_agent_busy_until <= current_time) {
            if (!is_queue_empty(&frequent_queue)) {
                customer c = dequeue(&frequent_queue);
                total_frequent_waiting_time += current_time - c.arrival_time;
                frequent_customers_served++;
                ticket_agent_busy_until = current_time + (rand() % MAX_TICKET_AGENT_TIME) + 1;
            } else if (!is_queue_empty(&regular_queue)) {
                customer c = dequeue(&regular_queue);
                total_regular_waiting_time += current_time - c.arrival_time;
                regular_customers_served++;
                ticket_agent_busy_until = current_time + (rand() % MAX_TICKET_AGENT_TIME) + 1;
            }
        }
    }

    printf("Regular customers served: %d\n", regular_customers_served);
    printf("Average waiting time for regular customers: %.2f\n", 
           (float) total_regular_waiting_time / regular_customers_served);
    printf("Frequent customers served: %d\n", frequent_customers_served);
    printf("Average waiting time for frequent customers: %.2f\n", 
           (float) total_frequent_waiting_time / frequent_customers_served);

    free(regular_queue.customers);
    free(frequent_queue.customers);

    return 0;
}

