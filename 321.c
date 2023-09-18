#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

typedef struct Queue {
    char names[MAX_SIZE][20];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return (queue->front == -1);
}

int isFull(Queue* queue) {
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->rear == (queue->front - 1) % (MAX_SIZE - 1)));
}

void enqueue(Queue* queue, char* name) {
    if (isFull(queue)) {
        printf("La cola está llena. No se pueden agregar más elementos.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else if (queue->rear == MAX_SIZE - 1 && queue->front != 0) {
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    strcpy(queue->names[queue->rear], name);
    printf("%s añadido a la cola\n", name);
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía. No se pueden eliminar elementos.\n");
        return;
    }
    printf("%s eliminado de la cola\n", queue->names[queue->front]);
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else if (queue->front == MAX_SIZE - 1) {
        queue->front = 0;
    } else {
        queue->front = queue->front + 1;
    }
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía\n");
        return;
    }
    int i = queue->front;
    printf("Elementos de la cola:\n");
    while (i != queue->rear) {
        printf("%s\n", queue->names[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%s\n", queue->names[i]);
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, "Mar");
    enqueue(&queue, "Sella");
    enqueue(&queue, "Centurión");

    printQueue(&queue);

    enqueue(&queue, "Gloria");
    enqueue(&queue, "Generosa");

    dequeue(&queue);

    enqueue(&queue, "Positivo");
    enqueue(&queue, "Horche");

    printQueue(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    printQueue(&queue);

    return 0;
}
