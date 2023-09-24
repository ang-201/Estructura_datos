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

void dfs(struct Grafo* grafo, int nodo, int* visitado, int* arcosArbol, int* arcosAvance, int* arcosRetroceso, int* arcosCruzados) {
    visitado[nodo] = 1;
    
    struct Nodo* nodoActual = grafo->listaAdyacencia[nodo];
    while (nodoActual != NULL) {
        int idVecino = nodoActual->id;
        
        if (visitado[idVecino] == 0) {
            arcosArbol[idVecino] = 1;
            dfs(grafo, idVecino, visitado, arcosArbol, arcosAvance, arcosRetroceso, arcosCruzados);
        } else if (arcosArbol[idVecino] == 1) {
            arcosRetroceso[idVecino] = 1;
        } else if (arcosArbol[idVecino] == 0) {
            arcosAvance[idVecino] = 1;
        } else {
            arcosCruzados[idVecino] = 1;
        }
        
        nodoActual = nodoActual->siguiente;
    }
}

void calcularBosqueAbarcador(struct Grafo* grafo) {
    int* visitado = (int*)malloc(grafo->numNodos * sizeof(int));
    int* arcosArbol = (int*)malloc(grafo->numNodos * sizeof(int));
    int* arcosAvance = (int*)malloc(grafo->numNodos * sizeof(int));
    int* arcosRetroceso = (int*)malloc(grafo->numNodos * sizeof(int));
    int* arcosCruzados = (int*)malloc(grafo->numNodos * sizeof(int));
    
    for (int i = 0; i < grafo->numNodos; i++) {
        visitado[i] = 0;
        arcosArbol[i] = 0;
        arcosAvance[i] = 0;
        arcosRetroceso[i] = 0;
        arcosCruzados[i] = 0;
    }
    
    for (int i = 0; i < grafo->numNodos; i++) {
        if (visitado[i] == 0) {
            dfs(grafo, i, visitado, arcosArbol, arcosAvance, arcosRetroceso, arcosCruzados);
        }
    }
    
    printf("Arcos de árbol: ");
    for (int i = 0; i < grafo->numNodos; i++) {
        if (arcosArbol[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    printf("Arcos de avance: ");
    for (int i = 0; i < grafo->numNodos; i++) {
        if (arcosAvance[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    printf("Arcos de retroceso: ");
    for (int i = 0; i < grafo->numNodos; i++) {
        if (arcosRetroceso[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    printf("Arcos cruzados: ");
    for (int i = 0; i < grafo->numNodos; i++) {
        if (arcosCruzados[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
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
    
    calcularBosqueAbarcador(grafo);
    
    return 0;
}
