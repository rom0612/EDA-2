#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge(int arreglo[], int left, int mid, int right, int* operaciones) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    (*operaciones) += 2; // 2 asignaciones

    int* izquierda = (int*)malloc(n1 * sizeof(int));
    int* derecha = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; ++i) {
        (*operaciones)++; // Comparación del for
        izquierda[i] = arreglo[left + i];
        (*operaciones)++; // Asignación
    }
    
    for (int j = 0; j < n2; ++j) {
        (*operaciones)++; // Comparación del for
        derecha[j] = arreglo[mid + 1 + j];
        (*operaciones)++; // Asignación
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        (*operaciones) += 2; // 2 comparaciones del while
        (*operaciones)++; // Comparación interna
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            (*operaciones)++; // Asignación
            i++;
            (*operaciones)++; // Asignación
        } else {
            arreglo[k] = derecha[j];
            (*operaciones)++; // Asignación
            j++;
            (*operaciones)++; // Asignación
        }
        k++;
        (*operaciones)++; // Asignación
    }

    while (i < n1) {
        (*operaciones)++; // Comparación del while
        arreglo[k] = izquierda[i];
        (*operaciones)++; // Asignación
        i++;
        k++;
        (*operaciones) += 2; // 2 asignaciones
    }
    
    while (j < n2) {
        (*operaciones)++; // Comparación del while
        arreglo[k] = derecha[j];
        (*operaciones)++; // Asignación
        j++;
        k++;
        (*operaciones) += 2; // 2 asignaciones
    }
    
    free(izquierda);
    free(derecha);
}

void mergeSort(int arreglo[], int left, int right, int* operaciones) {
    (*operaciones)++; // Comparación
    if (left < right) {
        int mid = (left + right) / 2;
        (*operaciones)++; // Asignación
        mergeSort(arreglo, left, mid, operaciones);
        mergeSort(arreglo, mid + 1, right, operaciones);
        merge(arreglo, left, mid, right, operaciones);
    }
}

int main() {
    printf("---MergeSort---\n");
    printf("\n");
    int numPruebas=5;

    for (int i=0;i<numPruebas;i++){

    printf("--- Prueba numero: %d\n", i+1);
    srand(time(NULL));
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
    mergeSort(arr1, 0, n1 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr2, 0, n2 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr3, 0, n3 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr4, 0, n4 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr5, 0, n5 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr6, 0, n6 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr7, 0, n7 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    
    operaciones = 0;
    mergeSort(arr8, 0, n8 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}

    return 0;
}