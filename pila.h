#include <stdio.h>
#include <stdlib.h>

// Definir la estructura de un nodo de la pila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definir la estructura de la pila
typedef struct Stack {
    Node* top;
} Stack;

// Función para crear una pila vacía
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Función para verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// Función para añadir un elemento a la pila
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Elemento %d añadido a la pila\n", data);
}

// Función para consultar el elemento en la cima de la pila
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía\n");
        return -1;
    }
    return stack->top->data;
}

// Función para eliminar el elemento en la cima de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("La pila está vacía\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Función para mover un elemento a una posición específica en la pila
void move(Stack* stack, int position) {
    if (position <= 1 || isEmpty(stack)) {
        printf("Posición inválida o la pila está vacía\n");
        return;
    }
    Node* current = stack->top;
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
    previous->next = current->next;
    current->next = stack->top;
    stack->top = current;
    printf("Elemento movido a la posición %d\n", position);
}

// Función para eliminar todos los elementos de la pila
void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    printf("Pila vaciada\n");
}

// Ejemplo de uso
int main() {
    Stack* stack = createStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Elemento en la cima de la pila: %d\n", peek(stack));

    move(stack, 2);

    printf("Elemento en la cima de la pila después de mover: %d\n", peek(stack));

    pop(stack);

    printf("Elemento en la cima de la pila después de eliminar: %d\n", peek(stack));

    clear(stack);

    return 0;
}
