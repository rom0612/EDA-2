// avanceP2Quick

#include<stdio.h>

int heapSize;

int main(){
    int arr[] = {30,20,8,42,65,5,10,77,99,100,51,44};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Arrgelo Original \n");
	printArray(arr,size);
	quickSort(arr,0,size-1);
	printf("Arreglo ordenado \n");
	printArray(arr,size);
    return 0;
}


void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[],int size){
	int i;
  	for (i=0; i < size; i++)
       	printf("%d ", arr[i]);
    	printf("\n");
}
void printSubArray(int arr[],int low, int high){
    int i;
    printf("Sub array :  ");
	for (i=low; i <= high; i++)
       printf("%d ", arr[i]);
    printf("\n");
}


int partition (int arr[], int low, int high){
   	int pivot = arr[high];    
	int j,i = (low - 1);  
   	for (j = low; j <= high- 1; j++){
       	if (arr[j] <= pivot){
            	i++;    
            	swap(&arr[i], &arr[j]);
        	}
    	}
    	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high)    {
    	int pi = partition(arr, low, high);
	  	quickSort(arr, low, pi - 1);
	  	quickSort(arr, pi + 1, high);
    }
}
