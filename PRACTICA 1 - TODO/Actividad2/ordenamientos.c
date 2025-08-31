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
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(&lista[j], &lista[j + 1]);
            }
        }
        
        printf("\n -- Iteracion numero %d: ", i + 1);
        PrintArray(lista, n);
    }
}