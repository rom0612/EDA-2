#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int arreglo[], int n);
void InsertionSort(int lista[], int n);
void PrintArray(int lista[], int n);

int main() {
    int arr[] = {30, 20, 70, 8, 42, 65, 5, 10, 77, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, size);
    
    // Imprimir el arreglo ordenado
    printf("\nArreglo ordenado: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

//nueva func swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arreglo[], int n) {
    int indiceMenor, i, j;
    for(i = 0; i < n - 1; i++) {
        indiceMenor = i;
        for(j = i + 1; j < n; j++) {
            if(arreglo[j] < arreglo[indiceMenor])
                indiceMenor = j;
        }
        if(i != indiceMenor) {
            swap(&arreglo[i], &arreglo[indiceMenor]);
        }

        printf("\nIteracion numero %d: ", i + 1);
        for(int k = 0; k < n; k++) {
            printf("%d ", arreglo[k]);
        }
    }
}

void InsertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int index = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > index) {
            lista[j + 1] = lista[j];
            j = j - 1;
            printf("List hasta el momento:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
        }
        lista[j + 1] = index;
    }
}

void PrintArray(int lista[], int n){
    printf("Arreglo hasta el momento:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
}