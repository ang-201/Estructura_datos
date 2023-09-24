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

// Función para mostrar los nodos de un árbol en un nivel dado
void mostrarNodosEnNivel(struct NodoArbol* arbol, int nivel) {
    // Caso base: si el árbol es nulo, no hay nodos para mostrar
    if (arbol == NULL) {
        return;
    }
    
    // Si el nivel es 1, mostrar el valor del nodo
    if (nivel == 1) {
        printf("%d ", arbol->valor);
    }
    
    // Llamadas recursivas para los subárboles izquierdo y derecho
    mostrarNodosEnNivel(arbol->izquierda, nivel - 1);
    mostrarNodosEnNivel(arbol->derecha, nivel - 1);
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
    
    // Mostrar los nodos en un nivel dado (en este caso, nivel 2)
    int nivel = 2;
    printf("Nodos en el nivel %d: ", nivel);
    mostrarNodosEnNivel(arbol, nivel);
    
    return 0;
}
