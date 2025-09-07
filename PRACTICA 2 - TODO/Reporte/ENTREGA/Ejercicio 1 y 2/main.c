// gcc -o main main.c utilerias.c ordenamientos.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilerias.h"
#include "ordenamientos.h"

#define SIZE 20
#define MAX 1000


int main() {
    int arr[SIZE];
    int opcion;
    srand(time(NULL));
    
    do {
        printf("\n=== MENU DE ORDENAMIENTO ===\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Heap Sort\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
            generarArregloAleatorio(arr, SIZE);
            
            int copia[SIZE];
            for(int i = 0; i < SIZE; i++) copia[i] = arr[i];
            
            switch(opcion) {
                case 1:
                    printf("\n=== INSERTION SORT ===\n");
                    printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
                    InsertionSort(copia, SIZE);
                    break;
                case 2:
                    printf("\n=== SELECTION SORT ===\n");
                    printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
                    selectionSort(copia, SIZE);
                    break;
                case 3:
                    printf("\n=== BUBBLE SORT ===\n");
                    printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
                    BubbleSort(copia, SIZE);
                    break;
                case 4:
                    printf("\n=== QUICK SORT ===\n");
                    printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
                    quickSort(copia, 0, SIZE - 1);
                    break;
                case 5:
                    printf("\n=== HEAP SORT ===\n");
                    printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
                    HeapSort(copia, SIZE);
                    break;
                case 6:
                    printf("Saliendo..");
                    break;
                default:
                    printf("Opcion no valida");
            }

              if(opcion >= 1 && opcion < 6) {
            printf("\nArreglo ordenado: ");
            PrintArray(copia, SIZE);
             }
        
    } while(opcion != 6);
    
    return 0;
}