#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int id;
    struct Nodo* siguiente;
};

struct Grafo {
    int numNodos;
    struct Nodo** listaAdyacencia;
};

struct Nodo* crearNodo(int id) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->id = id;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

struct Grafo* crearGrafo(int numNodos) {
    struct Grafo* nuevoGrafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    nuevoGrafo->numNodos = numNodos;
    nuevoGrafo->listaAdyacencia = (struct Nodo**)malloc(numNodos * sizeof(struct Nodo*));
    for (int i = 0; i < numNodos; i++) {
        nuevoGrafo->listaAdyacencia[i] = NULL;
    }
    return nuevoGrafo;
}

void agregarArista(struct Grafo* grafo, int origen, int destino) {
    struct Nodo* nuevoNodo = crearNodo(destino);
    nuevoNodo->siguiente = grafo->listaAdyacencia[origen];
    grafo->listaAdyacencia[origen] = nuevoNodo;
}

void imprimirGrafo(struct Grafo* grafo) {
    for (int i = 0; i < grafo->numNodos; i++) {
        struct Nodo* nodoActual = grafo->listaAdyacencia[i];
        printf("Nodo %d: ", i);
        while (nodoActual != NULL) {
            printf("%d ", nodoActual->id);
            nodoActual = nodoActual->siguiente;
        }
        printf("\n");
    }
}

int main() {
    int numNodos = 5;
    struct Grafo* grafo = crearGrafo(numNodos);
    
    agregarArista(grafo, 0, 1);
    agregarArista(grafo, 0, 4);
    agregarArista(grafo, 1, 2);
    agregarArista(grafo, 1, 3);
    agregarArista(grafo, 1, 4);
    agregarArista(grafo, 2, 3);
    agregarArista(grafo, 3, 4);
    
    imprimirGrafo(grafo);
    
    return 0;
}
