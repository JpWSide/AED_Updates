#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n) {
    int i, j, min;

    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (*(arr+j) < *(arr+min))
                min = j;

        // troca o elemento mínimo com o primeiro elemento não ordenado
        int temp = *(arr+min);
        *(arr+min) = *(arr+i);
        *(arr+i) = temp;
    }
}

int* maxSubsequence(int* arr, int n, int k, int* returnSize) {
    selectionSort(arr, n);
    *returnSize = n - k;
    int *arrnew = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        arrnew[i] = arr[n-k+i];
    }
    return arrnew;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr+i));
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array original:\n");
    printArray(arr, n);

    int k = 4;
    int returnSize;
    int *arrnew = maxSubsequence(arr, n, k, &returnSize);

    printf("Os %d maiores elementos do array:\n", k);
    printArray(arrnew, k);

    free(arrnew);
    return 0;
}