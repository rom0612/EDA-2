#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilerias.h"

int partition (int arr[], int low, int high, int *operaciones){

   	int pivot = arr[high];    
	int j,i = (low - 1);  
   	for (j = low; j <= high- 1; j++){
   		(*operaciones)++;
       	if (arr[j] <= pivot){
            i++;    
            swap(&arr[i], &arr[j]);
            (*operaciones) +=3;
        	}
    	}
    	swap(&arr[i + 1], &arr[high]);
        (*operaciones) +=3;
	return (i + 1);
}

void quickSort(int arr[], int low, int high, int *operaciones){
    if (low < high)    {
    	(*operaciones)++;
    	int pi = partition(arr, low, high,operaciones);
    	//printSubArray(arr,low,high);
	  	quickSort(arr, low, pi - 1,operaciones);
	  	quickSort(arr, pi + 1, high,operaciones);
    }
}
int main(){
    printf("---QuickSort---\n");
    srand(time(NULL));
    int numPruebas=5;

    for (int i=0;i<numPruebas;i++){

    printf("--- Prueba numero: %d\n", i+1);
	
    int arr1[50], arr2[100], arr3[500], arr4[800], arr5[1000], arr6[2000], arr7[5000], arr8[10000];
    int i,operaciones;
    
    generarArregloAleatorio(arr1, 50);
    int t1 = sizeof(arr1) / sizeof(arr1[0]);

    generarArregloAleatorio(arr2, 100);
    int t2 = sizeof(arr2) / sizeof(arr2[0]);

    generarArregloAleatorio(arr3, 500);
    int t3 = sizeof(arr3) / sizeof(arr3[0]);

    generarArregloAleatorio(arr4, 800);
    int t4 = sizeof(arr4) / sizeof(arr4[0]);

    generarArregloAleatorio(arr5, 1000);
    int t5 = sizeof(arr5) / sizeof(arr5[0]);

    generarArregloAleatorio(arr6, 2000);
    int t6 = sizeof(arr6) / sizeof(arr6[0]);
    
    generarArregloAleatorio(arr7, 5000);
    int t7 = sizeof(arr7) / sizeof(arr7[0]);

    generarArregloAleatorio(arr8, 10000);
    int t8 = sizeof(arr8) / sizeof(arr8[0]);
    
    operaciones=0;
    quickSort(arr1, 0, t1 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    operaciones=0;
    quickSort(arr2, 0, t2 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    operaciones=0;
    quickSort(arr3, 0, t3 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    operaciones=0;
    quickSort(arr4, 0, t4 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    operaciones=0;
    quickSort(arr5, 0, t5 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr6, 0, t6 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr7, 0, t7 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr8, 0, t8 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

}
    return 0;
}