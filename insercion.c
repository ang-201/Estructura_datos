#include <stdio.h>

void ordenamientoInsercion(int arr[], int n) {
    int i, j, actual;
    for (i = 1; i < n; i++) {
        actual = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > actual) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = actual;
    }
}

int main() {
    int arr[] = {190, 200, 86, 170, 4, 50, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    ordenamientoInsercion(arr, n);
    printf("Arreglo ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
