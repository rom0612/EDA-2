// avanceP2Quick
#include<stdio.h>

// Solucion 1: Declarar func antes
void swap(int* a, int* b);
void printArray(int arr[],int size);
void printSubArray(int arr[],int low, int high);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int heapSize;

int main(){
    int arr[] = {30,20,8,42,65,5,10,77,99,100,51,44};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\n --> Arreglo Original \n");
    printArray(arr,size);
    printf("============================================\n");
    quickSort(arr,0,size-1);
    printf("============================================\n");
    printf("\n --> Arreglo ordenado: ");
	printf("\n\n");
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

    // AÑADIENDO LA IMPRESION
    printf("\n-- partition --\n");
    printf("sublista: ");
    printSubArray(arr, low, high);
    printf("pivote: %d\n", pivot);

    for (j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    // MOSTRAR EL UPDATE DESPUÉS DE TERMINAR
    printf("Despues de dividir: ");
    printSubArray(arr, low, high);
    printf("Pivote en posicion final: %d\n", i + 1); // mUESTRA LO QUE TAMBIÉN DEVUELVE EL RETURN
    printf("----\n\n");
    
    return (i + 1); //
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        printf("\nLlama a QuickSort: ");
        printSubArray(arr, low, high);
        
        int pi = partition(arr, low, high);
        
        printf("Dividiendo: \n");
        printf("-> Sublista izquierda: ");
        printSubArray(arr, low, pi - 1);
        printf("-> Sublista derecha: ");
        printSubArray(arr, pi + 1, high);
        printf("\n");
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}