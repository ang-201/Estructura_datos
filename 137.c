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

// Función para determinar la altura de un árbol
int determinarAltura(struct NodoArbol* arbol) {
    // Caso base: si el árbol es nulo, la altura es 0
    if (arbol == NULL) {
        return 0;
    }
    
    // Recursivamente determinar la altura de los subárboles izquierdo y derecho
    int alturaIzquierda = determinarAltura(arbol->izquierda);
    int alturaDerecha = determinarAltura(arbol->derecha);
    
    // La altura del árbol es la máxima altura de los subárboles más 1
    return (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha) + 1;
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
    
    // Determinar la altura del árbol
    int altura = determinarAltura(arbol);
    printf("La altura del árbol es: %d\n", altura);
    
    return 0;
}
