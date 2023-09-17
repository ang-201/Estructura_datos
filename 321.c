#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

void initializeList(struct LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insert(struct LinkedList* list, const char* name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void removeNodesGreaterThan(struct LinkedList* list, const char* name) {
    struct Node* current = list->head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) > 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            struct Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (previous == NULL) {
        list->tail = NULL;
    } else {
        list->tail = previous;
    }
}

void printList(struct LinkedList list) {
    struct Node* current = list.head;
    while (current != NULL) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
}

int main() {
    struct LinkedList list;
    initializeList(&list);

    insert(&list, "Mar");
    insert(&list, "Sella");
    insert(&list, "Centurión");

    printf("Elementos de la lista enlazada: ");
    printList(list);

    insert(&list, "Gloria");
    insert(&list, "Generosa");

    removeNodesGreaterThan(&list, "Centurión");

    printf("Elementos de la lista después de eliminar mayores a Centurión: ");
    printList(list);

    freeList(&list);

    return 0;
}
