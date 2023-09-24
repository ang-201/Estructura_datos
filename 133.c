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

// Función para crear el árbol espejo de un árbol dado
struct NodoArbol* crearArbolEspejo(struct NodoArbol* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    
    struct NodoArbol* nuevoArbol = crearNodo(arbol->valor);
    nuevoArbol->izquierda = crearArbolEspejo(arbol->derecha);
    nuevoArbol->derecha = crearArbolEspejo(arbol->izquierda);
    
    return nuevoArbol;
}

// Función para imprimir el árbol en orden simétrico
void imprimirArbolSimetrico(struct NodoArbol* arbol) {
    if (arbol != NULL) {
        imprimirArbolSimetrico(arbol->izquierda);
        printf("%d ", arbol->valor);
        imprimirArbolSimetrico(arbol->derecha);
    }
}

int main() {
    // Crear un árbol de ejemplo
    struct NodoArbol* raiz = crearNodo(1);
    raiz->izquierda = crearNodo(2);
    raiz->derecha = crearNodo(3);
    raiz->izquierda->izquierda = crearNodo(4);
    raiz->izquierda->derecha = crearNodo(5);
    
    // Crear el árbol espejo
    struct NodoArbol* arbolEspejo = crearArbolEspejo(raiz);
    
    // Imprimir el árbol espejo en orden simétrico
    printf("Árbol espejo (orden simétrico): ");
    imprimirArbolSimetrico(arbolEspejo);
    printf("\n");
    
    return 0;
}
