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

// Función para contar las hojas de un árbol
int contarHojas(struct NodoArbol* arbol) {
    // Caso base: si el árbol es nulo, no hay hojas
    if (arbol == NULL) {
        return 0;
    }
    
    // Caso base: si el árbol no tiene hijos, es una hoja
    if (arbol->izquierda == NULL && arbol->derecha == NULL) {
        return 1;
    }
    
    // Recursivamente contar las hojas de los subárboles izquierdo y derecho
    return contarHojas(arbol->izquierda) + contarHojas(arbol->derecha);
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
    
    // Contar las hojas del árbol
    int hojas = contarHojas(arbol);
    printf("El árbol tiene %d hojas.\n", hojas);
    
    return 0;
}
