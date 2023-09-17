#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITOS 1000

typedef struct {
    int digitos[MAX_DIGITOS];
    int tope;
} Pila;

typedef struct {
    int digitos[MAX_DIGITOS];
    int frente;
    int final;
} Cola;

void inicializarPila(Pila *pila) {
    pila->tope = -1;
}

void inicializarCola(Cola *cola) {
    cola->frente = 0;
    cola->final = -1;
}

void push(Pila *pila, int digito) {
    pila->tope++;
    pila->digitos[pila->tope] = digito;
}

int pop(Pila *pila) {
    int digito = pila->digitos[pila->tope];
    pila->tope--;
    return digito;
}

void enqueue(Cola *cola, int digito) {
    cola->final++;
    cola->digitos[cola->final] = digito;
}

int dequeue(Cola *cola) {
    int digito = cola->digitos[cola->frente];
    cola->frente++;
    return digito;
}

void sumarNumeros(FILE *archivo) {
    Pila pila;
    Cola cola;
    inicializarPila(&pila);
    inicializarCola(&cola);

    char linea[MAX_DIGITOS];
    while (fgets(linea, MAX_DIGITOS, archivo) != NULL) {
        Pila nuevaPila;
        inicializarPila(&nuevaPila);

        for (int i = 0; linea[i] != '\0' && linea[i] != '\n'; i++) {
            int digito = linea[i] - '0';
            push(&nuevaPila, digito);
        }

        int acarreo = 0;
        while (pila.tope >= 0 || nuevaPila.tope >= 0 || acarreo > 0) {
            int suma = (pila.tope >= 0 ? pop(&pila) : 0) + (nuevaPila.tope >= 0 ? pop(&nuevaPila) : 0) + acarreo;
            int digito = suma % 10;
            acarreo = suma / 10;
            enqueue(&cola, digito);
        }

        while (cola.frente <= cola.final) {
            push(&pila, dequeue(&cola));
        }
    }

    printf("La suma de todos los números enteros del archivo es: ");
    while (pila.tope >= 0) {
        printf("%d", pop(&pila));
    }
    printf("\n");
}

int main() {
    FILE *archivo = fopen("archivo.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    sumarNumeros(archivo);

    fclose(archivo);

    return 0;
}
