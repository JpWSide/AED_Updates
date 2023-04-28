#include <stdio.h>

// função auxiliar para mesclar dois subarrays em um único array ordenado
void merge(int arr[], int left[], int right[], int nLeft, int nRight) {
    int i = 0, j = 0, k = 0;

    while (i < nLeft && j < nRight) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < nLeft) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < nRight) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// função principal do Merge Sort
void mergeSort(int arr[], int n) {
    if (n <= 1) {
        return;  // caso base: o array tem 1 elemento ou menos
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    // divide o array em dois subarrays
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }

    // chama a função mergeSort recursivamente nos dois subarrays
    mergeSort(left, mid);
    mergeSort(right, n - mid);

    // mescla os dois subarrays em um único array ordenado
    merge(arr, left, right, mid, n - mid);
}

// função auxiliar para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    mergeSort(arr, n);

    printf("Array ordenado: ");
    printArray(arr, n);

    return 0;
}