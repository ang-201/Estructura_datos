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

// Función para comprobar si dos árboles son iguales
int sonIguales(struct NodoArbol* arbol1, struct NodoArbol* arbol2) {
    // Caso base: si ambos árboles son nulos, son iguales
    if (arbol1 == NULL && arbol2 == NULL) {
        return 1;
    }
    
    // Si solo uno de los árboles es nulo, no son iguales
    if (arbol1 == NULL || arbol2 == NULL) {
        return 0;
    }
    
    // Comprobar si los valores de los nodos son iguales
    if (arbol1->valor != arbol2->valor) {
        return 0;
    }
    
    // Comprobar recursivamente si los subárboles izquierdo y derecho son iguales
    return sonIguales(arbol1->izquierda, arbol2->izquierda) && sonIguales(arbol1->derecha, arbol2->derecha);
}

int main() {
    // Crear el primer árbol de ejemplo
    struct NodoArbol* arbol1 = crearNodo(1);
    arbol1->izquierda = crearNodo(2);
    arbol1->derecha = crearNodo(3);
    arbol1->izquierda->izquierda = crearNodo(4);
    arbol1->izquierda->derecha = crearNodo(5);
    
    // Crear el segundo árbol de ejemplo
    struct NodoArbol* arbol2 = crearNodo(1);
    arbol2->izquierda = crearNodo(2);
    arbol2->derecha = crearNodo(3);
    arbol2->izquierda->izquierda = crearNodo(4);
    arbol2->izquierda->derecha = crearNodo(5);
    
    // Comprobar si los árboles son iguales
    if (sonIguales(arbol1, arbol2)) {
        printf("Los árboles son iguales.\n");
    } else {
        printf("Los árboles no son iguales.\n");
    }
    
    return 0;
}
