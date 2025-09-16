// gcc -o main main.c utilerias.c ordenamientos.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilerias.h"
#include "ordenamientos.h"
#include "proyecto1.h"

#define SIZE 20

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
        printf("6. Merge Sort\n");
        printf("7. Probar todos los algoritmos con diferentes tamanos\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        if (opcion >= 1 && opcion <= 6) {
            generarArregloAleatorio(arr, SIZE);
            int copia[SIZE];
            copiarArreglo(arr, copia, SIZE);
            
            int operaciones = 0;
            
            printf("\nArreglo original: ");
            PrintArray(arr, SIZE);
            
            switch(opcion) {
                case 1:
                    printf("\n=== INSERTION SORT ===\n");
                    InsertionSort(copia, SIZE, &operaciones);
                    break;
                case 2:
                    printf("\n=== SELECTION SORT ===\n");
                    selectionSort(copia, SIZE, &operaciones);
                    break;
                case 3:
                    printf("\n=== BUBBLE SORT ===\n");
                    BubbleSort(copia, SIZE, &operaciones);
                    break;
                case 4:
                    printf("\n=== QUICK SORT ===\n");
                    quickSort(copia, 0, SIZE - 1, &operaciones);
                    break;
                case 5:
                    printf("\n=== HEAP SORT ===\n");
                    HeapSort(copia, SIZE, &operaciones);
                    break;
                case 6:
                    printf("\n=== MERGE SORT ===\n");
                    mergeSort(copia, 0, SIZE - 1, &operaciones);
                    break;
            }
            
            printf("\nArreglo ordenado: ");
            PrintArray(copia, SIZE);
            printf("\nTotal de operaciones: %d\n", operaciones);
            
        } else if (opcion == 7) {
            printf("\n=== PROBANDO TODOS LOS ALGORITMOS ===\n");
            probarAlgoritmos();
        } else if (opcion == 8) {
            printf("Saliendo...\n");
        } else {
            printf("Opcion no valida\n");
        }
        
    } while(opcion != 8);
    
    return 0;
}