#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (isEmpty(queue)) {
        newNode->next = newNode;
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Elemento %d añadido a la cola\n", data);
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía\n");
        return -1;
    }
    return queue->front->data;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }
    free(temp);
    return data;
}

void move(Queue* queue, int position) {
    if (position <= 1 || isEmpty(queue)) {
        printf("Posición inválida o la cola está vacía\n");
        return;
    }
    Node* current = queue->front;
    Node* previous = NULL;
    int count = 1;
    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Posición inválida\n");
        return;
    }
    if (previous == NULL) {
        queue->front = current->next;
    } else {
        previous->next = current->next;
    }
    queue->rear->next = current;
    current->next = NULL;
    queue->rear = current;
    printf("Elemento movido a la posición %d\n", position);
}

void clear(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    printf("Cola vaciada\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Elemento en el frente de la cola: %d\n", front(queue));

    move(queue, 2);

    printf("Elemento en el frente de la cola después de mover: %d\n", front(queue));

    dequeue(queue);

    printf("Elemento en el frente de la cola después de eliminar: %d\n", front(queue));

    clear(queue);

    return 0;
}
