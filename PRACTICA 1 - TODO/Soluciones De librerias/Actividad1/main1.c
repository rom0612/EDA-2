#include <stdio.h>
#include "utilerias.h"
#include "ordenamientos.h"

int main() {
    int arrSelection[] = {30, 20, 70, 8, 42, 65, 5, 10, 77, 1};
    int sizeSelection = sizeof(arrSelection) / sizeof(arrSelection[0]);
    int arrInsertion[] = {71, 14, 15, 3, 8, 33, 2, 7, 9};
    int sizeInsertion = sizeof(arrInsertion) / sizeof(arrInsertion[0]);
    int arrBubble1[] = {1, 17, 8, 4, 7, 36, 2, 5, 9};
    int sizeBubble1 = sizeof(arrBubble1) / sizeof(arrBubble1[0]);
    int arrBubble2[] = {1,2,3,4,5,6,7,8,9,10};
    int sizeBubble2 = sizeof(arrBubble2) / sizeof(arrBubble2[0]);

    // Selection
    printf("\nArreglo 1 (Selection) original: ");
    PrintArray(arrSelection, sizeSelection);
    printf("\n---> Tamaño del arreglo 1: %d", sizeSelection);
    selectionSort(arrSelection, sizeSelection);
    printf("\nArreglo 1 (Selection) ordenado: ");
    PrintArray(arrSelection, sizeSelection);

    printf("\n==================");
    
    // Insertion
    printf("\nArreglo 1 (Insertion) original: ");
    PrintArray(arrInsertion, sizeInsertion);
    printf("\n---> Tamaño del arreglo 2: %d ", sizeInsertion);
    InsertionSort(arrInsertion, sizeInsertion);
    printf("\nArreglo 2 (Insertion) ordenado: ");
    PrintArray(arrInsertion, sizeInsertion);
    printf("\n");

    printf("\n==================");
    
    // Bubble
    printf("\nArreglo 3 (Bubble) original: ");
    PrintArray(arrBubble1, sizeBubble1);
    printf("\n---> Tamaño del arreglo 3: %d \n", sizeBubble1);
    BubbleSort(arrBubble1, sizeBubble1);
    printf("\nArreglo 3 (Bubble) ordenado: ");
    PrintArray(arrBubble1, sizeBubble1);
    printf("\n");
    
    // Bubble
    printf("\nArreglo 4 (Bubble ordenado) original: ");
    PrintArray(arrBubble2, sizeBubble2);
    printf("\n---> Tamaño del arreglo 4: %d ", sizeBubble2);
    BubbleSort(arrBubble2, sizeBubble2);
    printf("\nArreglo 4 (Bubble final): ");
    PrintArray(arrBubble2, sizeBubble2);
    printf("\n");
    
    return 0;
}