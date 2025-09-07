#include <stdio.h>
#include "ordenamientos.h"
#include "utilerias.h"


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

        printf("\n -- Iteracion numero %d: ", i + 1);
        PrintArray(arreglo, n);
    }
}

void InsertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int index = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > index) {
            lista[j + 1] = lista[j];
            j = j - 1;
            printf("\n -- Iteracion numero %d: ", i + 1);
            PrintArray(lista, n);
        }
        lista[j + 1] = index;
    }
}

void BubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; //NUEVA VARIABLE
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(&lista[j], &lista[j + 1]);
                swapped = 1; //SI DE HIZO UN CAMBIO, EL VALOR DE SWAPPED CAMBIA
            }
        }
        
        printf("\n -- Iteracion numero %d: ", i + 1);
        PrintArray(lista, n);
        if (swapped == 0) { //SI NO SEHIZO NINGUN CAMBIO D POSICIÓN YA ESTÁ ORDENADO
            printf("\nla lista ya está ordenada, después de la iteración %d: ", i + 1);
            break;
        }
    }
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        printf("\nLlama a QuickSort: ");
        printSubArray(arr, low, high);
        
        int pi = partition(arr, low, high);
        
        printf("Dividiendo: \n");
        printf("-> Sublista izquierda: ");
        printSubArray(arr, low, pi - 1);
        printf("-> Sublista derecha: ");
        printSubArray(arr, pi + 1, high);
        printf("\n");
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void HeapSort(int* A, int size){
    int heapSize = size - 1; // local en lugar de global
    
    BuildHeap(A, size, &heapSize); //pasar heapSize
    
    printf("=== ELIMINAR LA RAÍZ ===\n");
    for(int i = size - 1; i > 0; i--){
        printf("intercambio de raiz (%d) con ultimo elemento (%d)\n", A[0], A[i]);
        swap(&A[0], &A[i]);
        heapSize--;
        printf("Heap después del intercambio: ");
        PrintArray(A, size);
        Heapify(A, 0, size, heapSize); // pasar heapSize
        printf("Heap después de reordenar: ");
        PrintArray(A, size);
        printf("\n");
    }
}
