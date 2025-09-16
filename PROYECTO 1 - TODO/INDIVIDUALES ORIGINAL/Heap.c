#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int contOperaciones=0;

void HeapSort(int *A, int size);
void Heapify(int* A, int i, int size);
void BuildHeap(int* A, int size);
void swap(int* a, int* b);
void printArray(int arr[],int size);


int main(){
    int arr1[50], arr2[100], arr3[500], arr4[800], arr5[1000], arr6[2000], arr7[5000], arr8[10000];
    int n1 = 50, n2 = 100, n3 =500, n4 = 800, n5 = 1000, n6 = 2000, n7 = 5000, n8 = 10000;
	int i, *cont1, *cont2;
    
    srand(time(NULL));
    for(i=0; i<n1; i++){
    	arr1[i] = rand();
	}
	for(i=0; i<n2; i++){
    	arr2[i] = rand();
	}
	for(i=0; i<n3; i++){
    	arr3[i] = rand();
	}
	for(i=0; i<n4; i++){
    	arr4[i] = rand();
	}
	for(i=0; i<n5; i++){
    	arr5[i] = rand();
	}
	for(i=0; i<n6; i++){
    	arr6[i] = rand();
	}
	for(i=0; i<n7; i++){
    	arr7[i] = rand();
	}
	for(i=0; i<n8; i++){
    	arr8[i] = rand();
	}
	
	contOperaciones=0;
	HeapSort(arr1, n1);
	printf("Operaciones totales para arreglo1[50]: %d\n", contOperaciones);
    
    contOperaciones=0;
	HeapSort(arr2, n2);
	printf("Operaciones totales para arreglo2[100]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr3, n3);
	printf("Operaciones totales para arreglo3[500]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr4, n4);
	printf("Operaciones totales para arreglo4[8000]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr5, n5);
	printf("Operaciones totales para arreglo5[1000]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr6, n6);
	printf("Operaciones totales para arreglo6[2000]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr7, n7);
	printf("Operaciones totales para arreglo7[5000]: %d\n", contOperaciones);
	
	contOperaciones=0;
	HeapSort(arr8, n8);
	printf("Operaciones totales para arreglo8[10000]: %d\n", contOperaciones);
    return 0;
}

void HeapSort(int* A, int size){
	BuildHeap(A,size);
  	int i;
  	for(i = size - 1; i > 0; i--){
  		contOperaciones++;
    	swap(&A[0],&A[i]);
		contOperaciones++;      
	    Heapify(A, 0, i);
   }
}

void Heapify(int* A, int i, int size){
	
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	if(l <= size && A[l] > A[i]){
    	largest = l;
    }
  	else{
    	largest = i;
    }
    contOperaciones++;
    
  	if(r <= size && A[r] > A[largest]){
  		contOperaciones++;
    	largest = r;
    }
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	contOperaciones++;
    	Heapify(A, largest, size);
     }   
}

void BuildHeap(int* A, int size){
  	int i;
  	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i, size);
  	}
}

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void printArray(int arr[],int size){
	int i;
  	for (i=0; i < size; i++)
       	printf("%d ", arr[i]);
    	printf("\n");
}
