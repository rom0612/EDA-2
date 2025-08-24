#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilerias.h"
#include "ordenamientos.h"

#define SIZE 20
#define MAX 1000

void generarArregloAleatorio(int arreglo[], int n) {
    for(int i = 0; i < n; i++) {
        arreglo[i] = rand() % MAX;
    }
}

int main() {
    int arr[SIZE];
    int opcion;
    srand(time(NULL));
    
    do {
        printf("\n=== MENU DE ORDENAMIENTO ===\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Bubble Sort Mejorado\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        if(opcion >= 1 && opcion <= 4) {
            generarArregloAleatorio(arr, SIZE);
            printf("\nArreglo original: ");
            printArray(arr, SIZE);
            
            int copia[SIZE];
            for(int i = 0; i < SIZE; i++) copia[i] = arr[i];
            
            switch(opcion) {
                case 1:
                    printf("\n=== INSERTION SORT ===\n");
                    insertionSort(copia, SIZE);
                    break;
                case 2:
                    printf("\n=== SELECTION SORT ===\n");
                    selectionSort(copia, SIZE);
                    break;
                case 3:
                    printf("\n=== BUBBLE SORT ===\n");
                    bubbleSort(copia, SIZE);
                    break;
                case 4:
                    printf("\n=== BUBBLE SORT MEJORADO ===\n");
                    bubbleSortMejorado(copia, SIZE);
                    break;
            }
            
            printf("\nArreglo ordenado: ");
            printArray(copia, SIZE);
        }
        else if(opcion == 5) {
            printf("\n¡Gracias por usar el programa! Saliendo...\n");
        }
        else {
            printf("\nOpción inválida. Intente de nuevo.\n");
        }
        
    } while(opcion != 5);
    
    return 0;
}
