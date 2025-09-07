#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[], int n);
void printArray(int arr[], int size);

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int getDigito(int number, int posicionDig) {
    int divisor = 1;
    for (int i = 0; i < posicionDig; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

// Implementación de Radix Sort
void radixSort(int arr[], int n) {
    int max = findMax(arr, n);
    
    int queues[10][n];
    int numElemQueue[10] = {0}; // lleva el numero de elementos de cada cola (0-9)
    
    for (int digito = 0; max > 0; digito++, max /= 10) {
        // llenar las colas con el elemento correspondiente
        for (int i = 0; i < n; i++) {
            int valorDig = getDigito(arr[i], digito);
            // Coloca el número en la cola correspondiente a ese dígito
            queues[valorDig][numElemQueue[valorDig]] = arr[i];
            numElemQueue[valorDig]++; // Incrementa el contador después de agregar
        }
        
        // recorre y guarda los elementos de cada cola
        int index = 0;
        for (int queueNum = 0; queueNum < 10; queueNum++) {
            for (int i = 0; i < numElemQueue[queueNum]; i++) {
                arr[index++] = queues[queueNum][i];
                
            printf("arreglo despues de desencolar la queue %d: ", queueNum);
            printArray(arr,n);
            }
            
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ejemplo de uso de Radix Sort
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArreglo original (Radix Sort): ");
    printArray(arr, size);
    
    radixSort(arr, size);
    
    printf("Arreglo ordenado (Radix Sort): ");
    printArray(arr, size);
    
    return 0;
}