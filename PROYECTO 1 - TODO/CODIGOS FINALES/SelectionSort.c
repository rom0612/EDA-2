#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilerias.h"

void selectionSort(int arreglo[], int n, int *operaciones) {
    int indiceMenor, i, j;
    for(i = 0; i < n - 1; i++) {
        (*operaciones)++;
        indiceMenor = i;
        for(j = i + 1; j < n; j++) {
            (*operaciones)++; 
            if(arreglo[j] < arreglo[indiceMenor]) {
                indiceMenor = j;
                (*operaciones)++; 
            }
        }
        if(i != indiceMenor) {
            swap(&arreglo[i], &arreglo[indiceMenor]);
            (*operaciones) +=3;// 3 asignaciones x swap
        }
    }
}

int main() {
    printf("---SelectionSort---\n");
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
    selectionSort(arr1, t1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr2, t2, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr3, t3, &operaciones);
    printf("Total de operaciones con arreglo of 500: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr4, t4, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr5, t5, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr6, t6, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr7, t7, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    
    operaciones = 0;
    selectionSort(arr8, t8, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}
    return 0;
}