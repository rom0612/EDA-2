#include<stdio.h>
// Solución 1
void HeapSort(int* A, int size);
void Heapify(int* A, int i, int size);
void BuildHeap(int* A, int size);
void swap(int* a, int* b);
void printArray(int arr[], int size);
int heapSize;

int main(){
    int arr[] = {30,20,8,42,65,5,10,77,99,100,51,44};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Arrgelo Original \n");
	printArray(arr,size);
	HeapSort(arr,size);
	printf("Arreglo ordenado \n");
	printArray(arr,size);
    return 0;
}



void HeapSort(int* A, int size){
	BuildHeap(A,size);
  	int i;
  	for(i = size - 1; i > 0; i--){
    	swap(&A[0],&A[heapSize]);      
      	heapSize--;
	Heapify(A, 0,size);
   }
}

void Heapify(int* A, int i, int size)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest;

	if(l <= heapSize && A[l] > A[i])
    	largest = l;
  	else
    	largest = i;
  	if(r <= heapSize && A[r] > A[largest])
    	largest = r;
  	if(largest != i){
    	swap(&A[i],&A[largest]);
    	Heapify(A, largest,size);
     }
      
}

void BuildHeap(int* A, int size){
	heapSize = size - 1;
  	int i;
  	for(i = (size - 1) / 2; i >= 0; i--){
		Heapify(A, i,size);
  	}
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
