#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int* A, int i, int size, int* heapSize, int* operaciones) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;
    (*operaciones) ++; // 3 asignaciones

    (*operaciones)++; // Comparación
    if(l <= *heapSize) {
        (*operaciones)++; // Comparación
        if(A[l] > A[i]) {
            largest = l;
            (*operaciones)++; // Asignación
        } else {
            largest = i;
            (*operaciones)++; // Asignación
        }
    } else {
        largest = i;
        (*operaciones)++; // Asignación
    }

    (*operaciones)++; // Comparación
    if(r <= *heapSize) {
        (*operaciones)++; // Comparación
        if(A[r] > A[largest]) {
            largest = r;
            (*operaciones)++; // Asignación
        }
    }

    (*operaciones)++; // Comparación
    if(largest != i) {
        swap(&A[i], &A[largest]);
        (*operaciones) ++; // 3 asignaciones en swap
        Heapify(A, largest, size, heapSize, operaciones);
    }
}

void BuildHeap(int* A, int size, int* heapSize, int* operaciones) {
    *heapSize = size - 1;
    (*operaciones)++; // Asignación
    
    for(int i = (size - 1) / 2; i >= 0; i--) {
        (*operaciones)++; // Comparación del for
        Heapify(A, i, size, heapSize, operaciones);
    }
}

void HeapSort(int* A, int size, int* operaciones) {
    int heapSize;
    BuildHeap(A, size, &heapSize, operaciones);
    
    for(int i = size - 1; i > 0; i--) {
        (*operaciones)++; // Comparación del for
        swap(&A[0], &A[i]);
        (*operaciones) ++; // 3 asignaciones en swap
        heapSize--;
        (*operaciones)++; // Asignación
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
    
    for (i = 0; i < 50; i++) {
        arr1[i] = rand();
    }
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    for (i = 0; i < 100; i++) {
        arr2[i] = rand();
    }
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    for (i = 0; i < 500; i++) {
        arr3[i] = rand();
    }
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    for (i = 0; i < 800; i++) {
        arr4[i] = rand();
    }
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    for (i = 0; i < 1000; i++) {
        arr5[i] = rand();
    }
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    for (i = 0; i < 2000; i++) {
        arr6[i] = rand();
    }
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    for (i = 0; i < 5000; i++) {
        arr7[i] = rand();
    }
    int n7 = sizeof(arr7) / sizeof(arr7[0]);

    for (i = 0; i < 10000; i++) {
        arr8[i] = rand();
    }
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    
    operaciones = 0;
    HeapSort(arr1, n1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr2, n2, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr3, n3, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr4, n4, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr5, n5, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr6, n6, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr7, n7, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    
    operaciones = 0;
    HeapSort(arr8, n8, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}
    return 0;
}