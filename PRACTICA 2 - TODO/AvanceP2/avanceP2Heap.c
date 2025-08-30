// avanceP2Heap

#include<stdio.h>

int heapSize;

// Solución 1
void HeapSort(int* A, int size);
void Heapify(int* A, int i, int size);
void BuildHeap(int* A, int size);
void swap(int* a, int* b);
void printArray(int arr[], int size);

int main(){
    int arr[] = {30,20,8,42,65,5,10,77,99,100,51,44};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("--- Arreglo Original \n");
    printArray(arr,size);
    HeapSort(arr,size);
    printf("--- Arreglo ordenado \n");
    printArray(arr,size);

    return 0;
}

void HeapSort(int* A, int size){
    BuildHeap(A,size); //Construye el heap
    
    //ELIMINA RAIZ Y REORDENA
    printf("=== ELIMINAR LA RAÍZ ===\n");
    int i;
    for(i = size - 1; i > 0; i--){
        printf("intercmbio de raiz (%d) con ultimo elemento (%d)\n", A[0], A[i]);
        swap(&A[0], &A[heapSize]);
        heapSize--;
        printf("Heap dspues del intercambio: ");
        printArray(A, size);
        Heapify(A, 0, size); 
        printf("Heap despues de reordenar: ");
        printArray(A, size);
        printf("\n");
    }
}


void Heapify(int* A, int i,int size){
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
        printf("Intercambiando %d y %d \n", A[i], A[largest]);
        swap(&A[i], &A[largest]);
        printArray(A,size);
        Heapify(A, largest, size);

    }
}

void BuildHeap(int* A, int size){
    heapSize = size - 1;
    int i;
    printf("\n---Construyendo heap---\n");
    for(i = (size - 1) / 2; i >= 0; i--){
        printf("Heapify en la posic. %d (valor: %d)\n", i, A[i]);
        Heapify(A, i, size);
        printf("-->Heap actual: ");
        printArray(A, size);
        printf("\n");
    }
    printf("=== HEAP FINAL ===\n");
    printArray(A, size);
    printf("\n");
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}