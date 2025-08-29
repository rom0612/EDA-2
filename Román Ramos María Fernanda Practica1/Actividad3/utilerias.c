#include <stdio.h>
#include "utilerias.h"
#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
}

void generarArregloAleatorio(int arreglo[], int n) {
    for(int i = 0; i < n; i++) {
        arreglo[i] = rand() % MAX;
    }
}