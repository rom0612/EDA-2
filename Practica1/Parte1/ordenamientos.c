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
        printf("Iteración %d: ", i + 1);
        printArray(arreglo, n);
    }
}

void insertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int index = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > index) {
            lista[j + 1] = lista[j];
            j = j - 1;
        }
        lista[j + 1] = index;
        printf("Iteración %d: ", i);
        printArray(lista, n);
    }
}

void bubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(&lista[j], &lista[j + 1]);
            }
        }
        printf("Iteración %d: ", i + 1);
        printArray(lista, n);
    }
}

void bubbleSortMejorado(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(&lista[j], &lista[j + 1]);
                swapped = 1;
            }
        }
        printf("Iteración %d: ", i + 1);
        printArray(lista, n);
        if (swapped == 0) {
            printf("¡Lista ordenada! Deteniendo ejecución.\n");
            break;
        }
    }
}