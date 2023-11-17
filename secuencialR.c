#include <stdio.h>

int busquedaSecuencialRecursiva(int arr[], int inicio, int fin, int objetivo) {
    if (inicio > fin) {
        return -1; // El objetivo no se encuentra en el arreglo
    }

    if (arr[inicio] == objetivo) {
        return inicio; // Se encontró el objetivo en la posición inicio
    }

    return busquedaSecuencialRecursiva(arr, inicio + 1, fin, objetivo); // Llamada recursiva para buscar en la siguiente posición
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 23;

    int resultado = busquedaSecuencialRecursiva(arr, 0, n - 1, objetivo);

    if (resultado == -1) {
        printf("El objetivo no se encuentra en el arreglo.\n");
    } else {
        printf("El objetivo se encuentra en la posición %d.\n", resultado);
    }

    return 0;
}
