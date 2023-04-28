#include <stdio.h>

// função para trocar dois elementos de posição
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// função para encontrar o pivô e rearranjar o array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // escolhe o último elemento como pivô
    int i = low - 1;        // inicializa o índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // se o elemento atual for menor ou igual ao pivô, incrementa o índice do menor elemento e troca
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);  // coloca o pivô na posição correta
    return i + 1;            // retorna a posição do pivô
}

// função principal do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);  // encontra o pivô
        quickSort(arr, low, pivot - 1);         // ordena o subarray à esquerda do pivô
        quickSort(arr, pivot + 1, high);        // ordena o subarray à direita do pivô
    }
}

// função auxiliar para imprimir o array
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