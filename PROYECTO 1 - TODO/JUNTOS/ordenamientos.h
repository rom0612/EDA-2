#ifndef ORDENAMIENTOS_H
#define ORDENAMIENTOS_H

void selectionSort(int arreglo[], int n, int* operaciones);
void InsertionSort(int lista[], int n, int* operaciones);
void BubbleSort(int lista[], int n, int* operaciones);
void quickSort(int arr[], int low, int high, int* operaciones);
void HeapSort(int* A, int size, int* operaciones);
void mergeSort(int arreglo[], int left, int right, int* operaciones);

// Funciones de prueba con diferentes tamaños
void probarAlgoritmos();

#endif