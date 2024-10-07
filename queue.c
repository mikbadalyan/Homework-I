#include <stdio.h>
#include <stdbool.h>
#define size 100


typedef struct {
    int elements[size];
    int head;
    int tail;
} Queue;


void init(Queue* q)
{
    q->head = -1;
    q->tail = 0;
}


bool empty(Queue* q) {
     return (q->head == q->tail - 1); 
}


bool full(Queue* q) { 
    return (q->tail == size);
}

void enqueue(Queue* q, int value)
{
    if (full(q)) {
        printf("Queue is full\n");
        return;
    }
    q->elements[q->tail] = value;
    q->tail++;
}

void dequeue(Queue* q)
{
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    q->head++;
}

int head_element(Queue* q)
{
    if (empty(q)) {
        printf("Queue is empty\n");
        return -1; 
                
    }
    return q->elements[q->head + 1];
}

void print(Queue* q)
{
    if (empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->head + 1; i < q->tail; i++) {
        printf("%d ", q->elements[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);
    enqueue(&q, 150);
    print(&q);
    enqueue(&q, 65);
    print(&q);
    enqueue(&q, 12);
    print(&q);
    enqueue(&q, 4);
    print(&q);
    enqueue(&q, 26);
    print(&q);
    enqueue(&q, 17);
    print(&q);
    enqueue(&q, 87);
    print(&q);
    enqueue(&q, 120);
    print(&q);
    printf("head element: %d\n", head_element(&q));
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    printf("head element after dequeue: %d\n", head_element(&q));

    return 0;
}
