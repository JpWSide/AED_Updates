#include <stdio.h>


void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low - 1;       

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);  
    return i + 1;            
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);  
        quickSort(arr, low, pivot - 1);         
        quickSort(arr, pivot + 1, high);        
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    printArray(arr, n);

    return 0;
}