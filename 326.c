#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITOS 1000

typedef struct {
    int digitos[MAX_DIGITOS];
    int frente;
    int final;
} Cola;

typedef struct {
    int digitos[MAX_DIGITOS];
    int tope;
} Pila;

void inicializarCola(Cola *cola) {
    cola->frente = 0;
    cola->final = -1;
}

void inicializarPila(Pila *pila) {
    pila->tope = -1;
}

void insertarPila(Pila *pila, int digito) {
    pila->tope++;
    pila->digitos[pila->tope] = digito;
}

int quitarPila(Pila *pila) {
    int digito = pila->digitos[pila->tope];
    pila->tope--;
    return digito;
}

void insertarCola(Cola *cola, int digito) {
    cola->final++;
    cola->digitos[cola->final] = digito;
}

int quitarCola(Cola *cola) {
    int digito = cola->digitos[cola->frente];
    cola->frente++;
    return digito;
}

int esCapicua() {
    Cola cola;
    Pila pila;
    inicializarCola(&cola);
    inicializarPila(&pila);

    char caracter;
    while ((caracter = getchar()) != '\n') {
        int digito = caracter - '0';
        insertarCola(&cola, digito);
        insertarPila(&pila, digito);
    }

    while (cola.frente <= cola.final && pila.tope >= 0) {
        int digitoCola = quitarCola(&cola);
        int digitoPila = quitarPila(&pila);
        if (digitoCola != digitoPila) {
            return 0; // No es capicúa
        }
    }

    return 1; // Es capicúa
}

int main() {
    printf("Ingrese un número: ");

    if (esCapicua()) {
        printf("El número ingresado es capicúa.\n");
    } else {
        printf("El número ingresado no es capicúa.\n");
    }

    return 0;
}
