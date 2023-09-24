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

// Función para insertar un valor en el árbol
struct NodoArbol* insertar(struct NodoArbol* nodo, int valor) {
    // Si el árbol está vacío, crear un nuevo nodo con el valor dado
    if (nodo == NULL) {
        return crearNodo(valor);
    }
    
    // Si el valor es menor que el valor del nodo actual, insertarlo en el subárbol izquierdo
    if (valor < nodo->valor) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    }
    // Si el valor es mayor que el valor del nodo actual, insertarlo en el subárbol derecho
    else if (valor > nodo->valor) {
        nodo->derecha = insertar(nodo->derecha, valor);
    }
    
    return nodo;
}

// Función para buscar un valor en el árbol
struct NodoArbol* buscar(struct NodoArbol* nodo, int valor) {
    // Si el árbol está vacío o el valor del nodo actual es igual al valor buscado, retornar el nodo actual
    if (nodo == NULL || nodo->valor == valor) {
        return nodo;
    }
    
    // Si el valor es menor que el valor del nodo actual, buscar en el subárbol izquierdo
    if (valor < nodo->valor) {
        return buscar(nodo->izquierda, valor);
    }
    // Si el valor es mayor que el valor del nodo actual, buscar en el subárbol derecho
    else {
        return buscar(nodo->derecha, valor);
    }
}

// Función para eliminar un valor del árbol
struct NodoArbol* eliminar(struct NodoArbol* nodo, int valor) {
    // Si el árbol está vacío, retornar el árbol sin cambios
    if (nodo == NULL) {
        return nodo;
    }
    
    // Si el valor es menor que el valor del nodo actual, eliminar en el subárbol izquierdo
    if (valor < nodo->valor) {
        nodo->izquierda = eliminar(nodo->izquierda, valor);
    }
    // Si el valor es mayor que el valor del nodo actual, eliminar en el subárbol derecho
    else if (valor > nodo->valor) {
        nodo->derecha = eliminar(nodo->derecha, valor);
    }
    // Si el valor es igual al valor del nodo actual, eliminar el nodo actual
    else {
        // Caso 1: el nodo no tiene hijos o solo tiene un hijo
        if (nodo->izquierda == NULL) {
            struct NodoArbol* temp = nodo->derecha;
            free(nodo);
            return temp;
        }
        else if (nodo->derecha == NULL) {
            struct NodoArbol* temp = nodo->izquierda;
            free(nodo);
            return temp;
        }
        
        // Caso 2: el nodo tiene dos hijos
        struct NodoArbol* temp = nodo->derecha;
        while (temp->izquierda != NULL) {
            temp = temp->izquierda;
        }
        nodo->valor = temp->valor;
        nodo->derecha = eliminar(nodo->derecha, temp->valor);
    }
    
    return nodo;
}

// Función para mostrar los nodos del árbol en orden ascendente
void mostrarEnOrden(struct NodoArbol* nodo) {
    if (nodo != NULL) {
        mostrarEnOrden(nodo->izquierda);
        printf("%d ", nodo->valor);
        mostrarEnOrden(nodo->derecha);
    }
}

int main() {
    struct NodoArbol* arbol = NULL;
    
    // Insertar valores en el árbol
    arbol = insertar(arbol, 50);
    arbol = insertar(arbol, 30);
    arbol = insertar(arbol, 20);
    arbol = insertar(arbol, 40);
    arbol = insertar(arbol, 70);
    arbol = insertar(arbol, 60);
    arbol = insertar(arbol, 80);
    
    // Mostrar los nodos del árbol en orden ascendente
    printf("Nodos del arbol en orden ascendente: ");
    mostrarEnOrden(arbol);
    printf("\n");
    
    // Buscar un valor en el árbol
    int valorBuscado = 40;
    struct NodoArbol* nodoEncontrado = buscar(arbol, valorBuscado);
    if (nodoEncontrado != NULL) {
        printf("El valor %d esta en el arbol.\n", valorBuscado);
    } else {
        printf("El valor %d no esta en el arbol.\n", valorBuscado);
    }
    
    // Eliminar un valor del árbol
    int valorAEliminar = 30;
    arbol = eliminar(arbol, valorAEliminar);
    
    // Mostrar los nodos del árbol en orden ascendente después de la eliminación
    printf("Nodos del arbol en orden ascendente despues de eliminar %d: ", valorAEliminar);
    mostrarEnOrden(arbol);
    printf("\n");
    
    return 0;
}
