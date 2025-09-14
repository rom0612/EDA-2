// gcc countingSort.c -o countingSort.exe

#include <stdio.h>
#define SIZE 20
#define VALMIN 5
#define VALMAX 20
#define RANGO (VALMAX - VALMIN + 1)

int main() {
    int arr[SIZE]; //original
    int cont[RANGO] = {0}; // contar las apariciones 
    int sorted[SIZE]; //ordenado
    
    // solicitar los 20 elem
    printf("ingresa 20 numeros enteros entre %d y %d:\n", VALMIN, VALMAX);
    for(int i = 0; i < SIZE; i++) {
        printf("elemento %d: ", i+1);
        scanf("%d", &arr[i]);
        
        // que solo estén en el rango
        if(arr[i] < VALMIN || arr[i] > VALMAX) {
            printf("Error: El numero debe estar entre %d y %d\n", VALMIN, VALMAX);
            i--; // si pone uno que no está en el rango, lo pide otra vez
        }
    }
    
    printf("\nArreglo original: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // contar las apariciones de cada elem
    for(int i = 0; i < SIZE; i++) {
        cont[arr[i] - VALMIN]++;
    }
    // imprimir el arreglo donde los cuenta
    printf("\nArreglo de conteo (despues de primera pasada):\n");
    for(int i = 0; i < RANGO; i++) {
        printf("valor %d: aparce %d veces \n", i + VALMIN, cont[i]);
    }
    
    // suma de actual y anteriores
    for(int i = 1; i < RANGO; i++) {
        cont[i] += cont[i-1];
    }
    //mostrar la suma
    printf("\nSuma:\n");
    for(int i = 0; i < RANGO; i++) {
        printf("Hasta valor %d: %d elementos\n", i + VALMIN, cont[i]);
    }
    
    // llenar el arreglo ordenado
    printf("\nAcmodo al arreglo final:\n");
    for(int i = SIZE - 1; i >= 0; i--) {
        int valor = arr[i];
        int posic = cont[valor - VALMIN] - 1;
        
        sorted[posic] = valor;
        cont[valor - VALMIN]--;
        
        printf("elemnto %d (%d) colocado en posicicion %d", i, valor, posic);
        printf("\n");
    }
    
    printf("\nArreglo ordenado: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    
    return 0;
}