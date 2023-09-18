#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura de un nodo de la lista enlazada
typedef struct Node {
    char word[100];
    struct Node* next;
} Node;

// Función para insertar una palabra al final de la lista
void insert(Node** head, char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Función para eliminar una palabra de la lista
void removeWord(Node** head, char* word) {
    if (*head == NULL) {
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    // Buscar la palabra en la lista
    while (current != NULL && strcmp(current->word, word) != 0) {
        prev = current;
        current = current->next;
    }

    // Si se encuentra la palabra, eliminarla
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

// Función para escribir las palabras de la lista en un archivo
void writeToFile(Node* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        fprintf(file, "%s\n", current->word);
        current = current->next;
    }

    fclose(file);
}

int main() {
    char filename[100];
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    Node* head = NULL;
    char word[100];

    // Leer palabras del archivo y formar la lista
    while (fscanf(file, "%s", word) == 1) {
        insert(&head, word);
    }

    fclose(file);

    // Agregar nuevas palabras
    printf("Ingrese una palabra para agregar (o 'salir' para terminar): ");
    scanf("%s", word);
    while (strcmp(word, "salir") != 0) {
        insert(&head, word);
        printf("Ingrese una palabra para agregar (o 'salir' para terminar): ");
        scanf("%s", word);
    }

    // Eliminar una palabra
    printf("Ingrese una palabra para eliminar (o 'ninguna' para omitir): ");
    scanf("%s", word);
    if (strcmp(word, "ninguna") != 0) {
        removeWord(&head, word);
    }

    // Escribir las palabras en el archivo
    writeToFile(head, filename);

    // Liberar memoria
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
