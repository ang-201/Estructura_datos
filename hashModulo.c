#include <stdio.h>

int funcionHashModulo(int clave, int tamanoTabla) {
    return clave % tamanoTabla;
}

int main() {
    int clave = 50;
    int tamanoTabla = 100;

    int resultado = funcionHashModulo(clave, tamanoTabla);

    printf("El resultado de la función hash por módulo es: %d\n", resultado);

    return 0;
}
