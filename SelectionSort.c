#include <stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, min;

    // percorre todo o array
    for (i = 0; i < n-1; i++)
    {
        // encontra o elemento mínimo no array não ordenado
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        // troca o elemento mínimo com o primeiro elemento não ordenado
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array original:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}