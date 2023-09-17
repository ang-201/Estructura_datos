#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char palabra[100];
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(char* palabra) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->palabra, palabra);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertarPalabra(Nodo** lista, char* palabra) {
    Nodo* nuevoNodo = crearNodo(palabra);
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        Nodo* temp = *lista;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void borrarPalabra(Nodo** lista, char* palabra) {
    Nodo* temp = *lista;
    Nodo* prev = NULL;

    if (temp != NULL && strcmp(temp->palabra, palabra) == 0) {
        *lista = temp->siguiente;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->palabra, palabra) != 0) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        return;
    }

    prev->siguiente = temp->siguiente;
    free(temp);
}

void escribirArchivo(Nodo* lista, char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");
    Nodo* temp = lista;
    while (temp != NULL) {
        fprintf(archivo, "%s\n", temp->palabra);
        temp = temp->siguiente;
    }
    fclose(archivo);
}

void liberarLista(Nodo* lista) {
    Nodo* temp = lista;
    while (temp != NULL) {
        Nodo* siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    }
}

int main() {
    char nombreArchivo[100];
    printf("Ingrese el nombre del archivo: ");
    scanf("%s", nombreArchivo);

    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    Nodo* lista = NULL;
    char palabra[100];
    while (fscanf(archivo, "%s", palabra) != EOF) {
        insertarPalabra(&lista, palabra);
    }

    fclose(archivo);

    char opcion;
    do {
        printf("\n1. Añadir palabra\n");
        printf("2. Borrar palabra\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1': {
                printf("Ingrese la palabra a añadir: ");
                scanf("%s", palabra);
                insertarPalabra(&lista, palabra);
                break;
            }
            case '2': {
                printf("Ingrese la palabra a borrar: ");
                scanf("%s", palabra);
                borrarPalabra(&lista, palabra);
                break;
            }
            case '3': {
                break;
            }
            default: {
                printf("Opción inválida. Intente nuevamente.\n");
                break;
            }
        }
    } while (opcion != '3');

    escribirArchivo(lista, nombreArchivo);
    liberarLista(lista);

    printf("Programa finalizado. Palabras guardadas en el archivo.\n");

    return 0;
}
