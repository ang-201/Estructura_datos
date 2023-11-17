#include <stdio.h>

int moduloHash(int clave, int tamañoTabla) {
    return clave % tamañoTabla;
}

int main() {
    int clave = 10; // La clave que deseas hashear
    int tamañoTabla = 100; // El tamaño de la tabla hash

    int indice = moduloHash(clave, tamañoTabla);
    printf("El índice hash para la clave %d es: %d\n", clave, indice);

    return 0;
}

