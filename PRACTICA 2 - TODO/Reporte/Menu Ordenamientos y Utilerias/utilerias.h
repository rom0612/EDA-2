#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define MAX 1000
//prototipos

void swap(int *a, int *b);
void PrintArray(int lista[], int n);
//Crear el arreglo
void generarArregloAleatorio(int arreglo[], int n);

//Funciones ed Quick
void printSubArray(int arr[],int low, int high);
int partition (int arr[], int low, int high);
//funciones de Heap:
void Heapify(int* A, int i, int size, int heapSize);
void BuildHeap(int* A, int size, int* heapSize);

#endif // MENU_H_INCLUDED