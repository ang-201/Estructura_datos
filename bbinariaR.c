Aquí tienes un ejemplo de código en C para implementar la búsqueda binaria de forma recursiva:

```c
#include <stdio.h>

int busquedaBinariaRecursiva(int arr[], int inicio, int fin, int objetivo) {
    if (inicio > fin) {
        return -1; // El objetivo no se encuentra en el arreglo
    }

    int medio = inicio + (fin - inicio) / 2;

    if (arr[medio] == objetivo) {
        return medio; // Se encontró el objetivo en la posición medio
    }

    if (arr[medio] > objetivo) {
        return busquedaBinariaRecursiva(arr, inicio, medio - 1, objetivo); // Llamada recursiva para buscar en la mitad izquierda
    } else {
        return busquedaBinariaRecursiva(arr, medio + 1, fin, objetivo); // Llamada recursiva para buscar en la mitad derecha
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int objetivo = 23;

    int resultado = busquedaBinariaRecursiva(arr, 0, n - 1, objetivo);

    if (resultado == -1) {
        printf("El objetivo no se encuentra en el arreglo.\n");
    } else {
        printf("El objetivo se encuentra en la posición %d.\n", resultado);
    }

    return 0;
}
```

En este ejemplo, la función `busquedaBinariaRecursiva` realiza la búsqueda binaria de forma recursiva. Toma como parámetros el arreglo `arr`, el índice de inicio, el índice de fin y el objetivo que se desea buscar. Si el objetivo se encuentra en el arreglo, la función devuelve la posición donde se encuentra. Si no se encuentra, devuelve -1.

En la función `main`, se crea un arreglo de ejemplo y se llama a la función `busquedaBinariaRecursiva` para buscar el objetivo 23. Luego, se muestra el resultado por pantalla.

Espero que esto te sea útil.
