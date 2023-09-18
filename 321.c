#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 6

// Estructura para la cola circular
struct ColaCircular {
    char nombres[MAX_SIZE][50];
    int frente;
    int final;
    int cantidad;
};

// Función para inicializar la cola
void inicializarCola(struct ColaCircular *cola) {
    cola->frente = 2;
    cola->final = 2;
    cola->cantidad = 0;
}

// Función para agregar un nombre a la cola
void encolar(struct ColaCircular *cola, const char *nombre) {
    if (cola->cantidad < MAX_SIZE) {
        strcpy(cola->nombres[cola->final], nombre);
        cola->final = (cola->final + 1) % MAX_SIZE;
        cola->cantidad++;
    } else {
        printf("La cola está llena. No se puede agregar %s\n", nombre);
    }
}

// Función para eliminar un elemento de la cola
void desencolar(struct ColaCircular *cola) {
    if (cola->cantidad > 0) {
        printf("Se ha eliminado: %s\n", cola->nombres[cola->frente]);
        cola->frente = (cola->frente + 1) % MAX_SIZE;
        cola->cantidad--;
    } else {
        printf("La cola está vacía. No se puede eliminar.\n");
    }
}

int main() {
    struct ColaCircular cola;
    inicializarCola(&cola);

    encolar(&cola, "Mar");
    encolar(&cola, "Sella");
    encolar(&cola, "Centurión");

    // Mostrar la cola y sus campos
    printf("Elementos de la cola:\n");
    for (int i = 0; i < cola.cantidad; i++) {
        printf("%s\n", cola.nombres[(cola.frente + i) % MAX_SIZE]);
    }
    printf("Frente: %d\n", cola.frente);
    printf("Final: %d\n", (cola.frente + cola.cantidad - 1) % MAX_SIZE);

    encolar(&cola, "Gloria");
    encolar(&cola, "Generosa");
    desencolar(&cola);
    encolar(&cola, "Positivo");
    encolar(&cola, "Horche");

    // Eliminar todos los elementos de la cola
    while (cola.cantidad > 0) {
        desencolar(&cola);
    }

    return 0;
}
