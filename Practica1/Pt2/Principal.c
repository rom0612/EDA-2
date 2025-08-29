#include <stdio.h>
#include "utilerias.c"
#include "ordenamientos.c"

#define SIZE 10

int main() {
    int opcion;
    
    do {
        int copia [] = {55,23,11,60,75,4,18,90,50,35};
        printf("\n=== MENU DE ORDENAMIENTO ===\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Bubble Sort Mejorado\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
            switch(opcion) {
                case 1:
                    printf("\n=== INSERTION SORT ===\n");
                    insertionSort(copia, SIZE);
                    printf("\nArreglo ordenado: ");
                    printArray(copia, SIZE);
                    break;
                case 2:
                    printf("\n=== SELECTION SORT ===\n");
                    selectionSort(copia, SIZE);
                    printf("\nArreglo ordenado: ");
                    printArray(copia, SIZE);
                    break;
                case 3:
                    printf("\n=== BUBBLE SORT ===\n");
                    bubbleSort(copia, SIZE);
                    printf("\nArreglo ordenado: ");
                    printArray(copia, SIZE);
                    break;
                case 4:
                    printf("\n=== BUBBLE SORT MEJORADO ===\n");
                    bubbleSortMejorado(copia, SIZE);
                    printf("\nArreglo ordenado: ");
                    printArray(copia, SIZE);
                    break;
                case 5:
                    printf("Saliendo del programa...");
                    break;
                default:
                    printf("Opción no válida.");
            }
            
        
    } while(opcion != 5);
    
    return 0;
}
