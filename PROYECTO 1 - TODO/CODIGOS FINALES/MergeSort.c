#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilerias.h"

void merge(int arreglo[], int left, int mid, int right, int* operaciones) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //int* izquierda = (int*)malloc(n1 * sizeof(int));
    //int* derecha = (int*)malloc(n2 * sizeof(int));
    int izquierda[n1];
    int derecha[n2];

    for (int i = 0; i < n1; ++i) {
        (*operaciones)++; 
        izquierda[i] = arreglo[left + i];
    }
    
    for (int j = 0; j < n2; ++j) {
        (*operaciones)++; 
        derecha[j] = arreglo[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*operaciones)++;
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            (*operaciones)++;
            i++;
        } else {
            arreglo[k] = derecha[j];
            (*operaciones)++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        (*operaciones)++; 
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        (*operaciones)++; 
        arreglo[k] = derecha[j];
        j++;
        k++;
    }
    
}

void mergeSort(int arreglo[], int left, int right, int* operaciones) {
    
    if (left < right) {
        (*operaciones)++;
        int mid = (left + right) / 2;
        mergeSort(arreglo, left, mid, operaciones);
        mergeSort(arreglo, mid + 1, right, operaciones);
        merge(arreglo, left, mid, right, operaciones);
    }
}

int main() {
    printf("---MergeSort---\n");
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
    mergeSort(arr1, 0, t1 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr2, 0, t2 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr3, 0, t3 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr4, 0, t4 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr5, 0, t5 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr6, 0, t6 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr7, 0, t7 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr8, 0, t8 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}

    return 0;
}