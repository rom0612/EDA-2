#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a,int *b){
    int index=*a;
    *a=*b;
    *b=index;
}
int partition (int arr[], int low, int high, int *operaciones){

   	int pivot = arr[high];    
	int j,i = (low - 1);  
   	for (j = low; j <= high- 1; j++){
   		(*operaciones)++;
       	if (arr[j] <= pivot){
       		(*operaciones)++;
            i++;    
            swap(&arr[i], &arr[j]);
        	}
    	}
    	swap(&arr[i + 1], &arr[high]);
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
	srand(time(NULL));
    int arr1[50], arr2[100], arr3[500], arr4[800], arr5[1000], arr6[2000], arr7[5000], arr8[10000];
    int i,operaciones;
    for (i=0;i<50;i++){
    	arr1[i]=rand();
    }
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    for (i=0;i<100;i++){
    	arr2[i]=rand();
    }
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    for (i=0;i<500;i++){
    	arr3[i]=rand();
    }
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    for (i=0;i<800;i++){
    	arr4[i]=rand();
    }
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    for (i=0;i<1000;i++){
    	arr5[i]=rand();
    }
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    for (i=0;i<2000;i++){
    	arr6[i]=rand();
    }
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    
    for (i=0;i<5000;i++){
    	arr7[i]=rand();
    }
    int n7 = sizeof(arr7) / sizeof(arr7[0]);

    for (i=0;i<10000;i++){
    	arr8[i]=rand();
    }
    int n8 = sizeof(arr8) / sizeof(arr8[0]);
    
    operaciones=0;
    quickSort(arr1, 0, n1 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 50: %d\n", operaciones);
    operaciones=0;
    quickSort(arr2, 0, n2 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 100: %d\n", operaciones);
    operaciones=0;
    quickSort(arr3, 0, n3 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 500: %d\n", operaciones);
    operaciones=0;
    quickSort(arr4, 0, n4 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 800: %d\n", operaciones);
    operaciones=0;
    quickSort(arr5, 0, n5 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 1000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr6, 0, n6 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 2000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr7, 0, n7 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 5000: %d\n", operaciones);
    operaciones=0;
    quickSort(arr8, 0, n8 - 1, &operaciones);
    printf("Total de operaciones con arreglo de 10000: %d\n", operaciones);

    return 0;
}
