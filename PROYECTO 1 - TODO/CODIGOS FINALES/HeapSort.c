#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilerias.h"

void Heapify(int* A, int i, int size, int* heapSize, int* operaciones) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if(l <= *heapSize) {
        (*operaciones)++; 
        if(A[l] > A[i]) {
            largest = l;
            (*operaciones)++; 
        } else {
            largest = i;
            (*operaciones)++;
        }
    } else {
        largest = i;
        (*operaciones)++;
    }

    if(r <= *heapSize) {
        (*operaciones)++; 
        if(A[r] > A[largest]) {
            largest = r;
            (*operaciones)++;
        }
    }

    if(largest != i) {
        swap(&A[i], &A[largest]);
        (*operaciones) +=3; //Sumar 3 operac
        Heapify(A, largest, size, heapSize, operaciones);
    }
}

void BuildHeap(int* A, int size, int* heapSize, int* operaciones) {
    *heapSize = size - 1;
    (*operaciones)++; 
    
    for(int i = (size - 1) / 2; i >= 0; i--) {
        (*operaciones)++; 
        Heapify(A, i, size, heapSize, operaciones);
    }
}

void HeapSort(int* A, int size, int* operaciones) {
    int heapSize;
    BuildHeap(A, size, &heapSize, operaciones);
    
    for(int i = size - 1; i > 0; i--) {
        (*operaciones)++; 
        swap(&A[0], &A[i]);
        (*operaciones) +=3; //Sumar 3 operac por el swp
        heapSize--;
        (*operaciones)++;
        Heapify(A, 0, size, &heapSize, operaciones);
    }
}

int main() {
    printf("---HeapSort---\n");
    printf("\n");
    srand(time(NULL));
    int numPruebas=5;

    for (int i=0;i<numPruebas;i++){

    printf("--- Prueba numero: %d\n", i+1);
    int arr1[50], arr2[100], arr3[500], arr4[800], arr5[1000], arr6[2000], arr7[5000], arr8[10000];
    int i, operaciones;
    
    generarArregloAleatorio(arr1, 50);
    int t1 = sizeof(arr1) / sizeof(arr1[0]);

    generarArregloAleatorio(arr2, 100);
    int t2 = sizeof(arr2) / sizeof(arr2[0]);

    generarArregloAleatorio(arr3, 500);
    int t3 = sizeof(arr3) / sizeof(arr3[0]);

    generarArregloAleatorio(arr4, 800);
    int t4 = sizeof(arr4) / sizeof(arr4[0]);

    generarArregloAleatorio(arr5, 1000);
    int t5 = sizeof(arr5) / sizeof(arr5[0]);

    generarArregloAleatorio(arr6, 2000);
    int t6 = sizeof(arr6) / sizeof(arr6[0]);
    
    generarArregloAleatorio(arr7, 5000);
    int t7 = sizeof(arr7) / sizeof(arr7[0]);

    generarArregloAleatorio(arr8, 10000);
    int t8 = sizeof(arr8) / sizeof(arr8[0]);
    
    operaciones = 0;
    HeapSort(arr1, t1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr2, t2, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr3, t3, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr4, t4, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr5, t5, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr6, t6, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr7, t7, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr8, t8, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}
    return 0;
}