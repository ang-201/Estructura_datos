#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo de la lista enlazada
struct Nodo {
    char palabra[100];
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo con la palabra dada
struct Nodo* crearNodo(const char* palabra) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    strcpy(nuevoNodo->palabra, palabra);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista enlazada
void insertarAlFinal(struct Nodo** cabeza, const char* palabra) {
    struct Nodo* nuevo = crearNodo(palabra);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

// Función para eliminar un nodo con la palabra dada de la lista
void eliminarPalabra(struct Nodo** cabeza, const char* palabra) {
    struct Nodo* actual = *cabeza;
    struct Nodo* previo = NULL;

    while (actual != NULL) {
        if (strcmp(actual->palabra, palabra) == 0) {
            if (previo == NULL) {
                *cabeza = actual->siguiente;
            } else {
                previo->siguiente = actual->siguiente;
            }
            free(actual);
            return; // Palabra encontrada y eliminada
        }
        previo = actual;
        actual = actual->siguiente;
    }
}

// Función para mostrar las palabras en la lista
void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%s\n", actual->palabra);
        actual = actual->siguiente;
    }
}

// Función para liberar la memoria de la lista enlazada
void liberarLista(struct Nodo* cabeza) {
    while (cabeza != NULL) {
        struct Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    FILE* archivo = fopen("palabras.txt", "r"); // Nombre del archivo de texto
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    struct Nodo* lista = NULL;
    char palabra[100];

    // Leer palabras del archivo y construir la lista
    while (fscanf(archivo, "%s", palabra) == 1) {
        insertarAlFinal(&lista, palabra);
    }

    fclose(archivo);

    int opcion;
    do {
        printf("\n1. Agregar palabra\n");
        printf("2. Eliminar palabra\n");
        printf("3. Mostrar palabras\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la palabra a agregar: ");
                scanf("%s", palabra);
                insertarAlFinal(&lista, palabra);
                break;
            case 2:
                printf("Ingrese la palabra a eliminar: ");
                scanf("%s", palabra);
                eliminarPalabra(&lista, palabra);
                break;
            case 3:
                printf("Palabras en la lista:\n");
                mostrarLista(lista);
                break;
            case 4:
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    // Abrir el archivo para escribir las palabras
    archivo = fopen("palabras.txt", "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    // Escribir las palabras en el archivo
    struct Nodo* actual = lista;
    while (actual != NULL) {
        fprintf(archivo, "%s\n", actual->palabra);
        actual = actual->siguiente;
    }

    fclose(archivo);

    // Liberar la memoria de la lista
    liberarLista(lista);

    return 0;
}
