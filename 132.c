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

// Función para copiar un árbol recursivamente
struct NodoArbol* copiarArbol(struct NodoArbol* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    
    struct NodoArbol* nuevoArbol = crearNodo(arbol->valor);
    nuevoArbol->izquierda = copiarArbol(arbol->izquierda);
    nuevoArbol->derecha = copiarArbol(arbol->derecha);
    
    return nuevoArbol;
}

int main() {
    // Crear un árbol de ejemplo
    struct NodoArbol* raiz = crearNodo(1);
    raiz->izquierda = crearNodo(2);
    raiz->derecha = crearNodo(3);
    raiz->izquierda->izquierda = crearNodo(4);
    raiz->izquierda->derecha = crearNodo(5);
    
    // Copiar el árbol
    struct NodoArbol* copiaRaiz = copiarArbol(raiz);
    
    // Imprimir la copia del árbol
    printf("Copia del arbol:\n");
    printf("%d\n", copiaRaiz->valor);
    printf("%d    %d\n", copiaRaiz->izquierda->valor, copiaRaiz->derecha->valor);
    printf("%d    %d\n", copiaRaiz->izquierda->izquierda->valor, copiaRaiz->izquierda->derecha->valor);
    
    return 0;
}
