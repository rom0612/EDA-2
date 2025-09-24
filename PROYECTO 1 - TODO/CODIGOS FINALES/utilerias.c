#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilerias.h"
#define MAX 1000


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void generarArregloAleatorio(int arreglo[], int tamaño) {
    for(int i = 0; i < tamaño; i++) {
        arreglo[i] = rand() % MAX;
    }
}
