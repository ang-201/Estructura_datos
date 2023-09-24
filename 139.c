#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo del árbol
struct NodoArbol {
    int valor;
    struct NodoArbol* izquierda;
    struct NodoArbol* derecha;
};

// Función para crear un nuevo nodo del árbol
struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol* nodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    nodo->valor = valor;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

// Función para mostrar los nodos de un árbol entre dos niveles dados
void mostrarNodosEntreNiveles(struct NodoArbol* arbol, int nivel_p, int nivel_q) {
    // Caso base: si el árbol es nulo, no hay nodos para mostrar
    if (arbol == NULL) {
        return;
    }
    
    // Si el nivel actual está entre p y q, mostrar el valor del nodo
    if (nivel_p <= 0 && nivel_q >= 0) {
        printf("%d ", arbol->valor);
    }
    
    // Llamadas recursivas para los subárboles izquierdo y derecho
    mostrarNodosEntreNiveles(arbol->izquierda, nivel_p - 1, nivel_q - 1);
    mostrarNodosEntreNiveles(arbol->derecha, nivel_p - 1, nivel_q - 1);
}

int main() {
    // Crear un árbol de ejemplo
    struct NodoArbol* arbol = crearNodo(1);
    arbol->izquierda = crearNodo(2);
    arbol->derecha = crearNodo(3);
    arbol->izquierda->izquierda = crearNodo(4);
    arbol->izquierda->derecha = crearNodo(5);
    arbol->derecha->izquierda = crearNodo(6);
    arbol->derecha->derecha = crearNodo(7);
    
    // Mostrar los nodos entre dos niveles dados (en este caso, niveles 1 y 2)
    int nivel_p = 1;
    int nivel_q = 2;
    printf("Nodos entre los niveles %d y %d: ", nivel_p, nivel_q);
    mostrarNodosEntreNiveles(arbol, nivel_p, nivel_q);
    
    return 0;
}
