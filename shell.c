#include <stdio.h>

void ordenamientoShell(int arr[], int n) {
    int intervalo, i, j, temp;
    for (intervalo = n/2; intervalo > 0; intervalo /= 2) {
        for (i = intervalo; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= intervalo && arr[j - intervalo] > temp; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    ordenamientoShell(arr, n);
    printf("Arreglo ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
