#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

      
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void print(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    print(arr, tamanho);

    insertionSort(arr, tamanho);

    printf("Array ordenado: ");
    print(arr, tamanho);

    return 0;
}