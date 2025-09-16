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

//FUNCIONES NECESRIAS PARA QUICKSORT
void printSubArray(int arr[],int low, int high){
    int i;
    printf("Sub array :  ");
    for (i=low; i <= high; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int partition (int arr[], int low, int high){
    int pivot = arr[high];    
    int j,i = (low - 1);  

    // AÑADIENDO LA IMPRESION
    printf("\n-- partition --\n");
    printf("sublista: ");
    printSubArray(arr, low, high);
    printf("pivote: %d\n", pivot);

    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    // MOSTRAR EL UPDATE DESPUÉS DE TERMINAR
    printf("Despues de dividir: ");
    printSubArray(arr, low, high);
    printf("Pivote en posicion final: %d\n", i + 1); // mUESTRA LO QUE TAMBIÉN DEVUELVE EL RETURN
    printf("----\n\n");
    
    return (i + 1); //
}

// FUNCIONES PARA HEAP
void BuildHeap(int* A, int size, int* heapSize){
    *heapSize = size - 1;
    printf("\n---Construyendo heap---\n");
    for(int i = (size - 1) / 2; i >= 0; i--){
        printf("Heapify en la posic. %d (valor: %d)\n", i, A[i]);
        Heapify(A, i, size, *heapSize); // Pasar heapSize como parámetro
        printf("-->Heap actual: ");
        PrintArray(A, size);
        printf("\n");
    }
    printf("=== HEAP FINAL ===\n");
    PrintArray(A, size);
    printf("\n");
}
void Heapify(int* A, int i, int size, int heapSize){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if(l <= heapSize && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if(r <= heapSize && A[r] > A[largest])
        largest = r;
    if(largest != i){
        printf("Intercambiando %d y %d \n", A[i], A[largest]);
        swap(&A[i], &A[largest]);
        PrintArray(A, size);
        Heapify(A, largest, size, heapSize); // Pasar heapSize como parámetro
    }
}


void copiarArreglo(int origen[], int destino[], int n) {
    for(int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}