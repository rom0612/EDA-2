//ESTE ES EL BUENOOOOOOO
#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int arreglo[], int n);
void InsertionSort(int lista[], int n);
void PrintArray(int lista[], int n);
void BubbleSort(int lista[], int n);

int main() {
    int arrSelection[] = {30, 20, 70, 8, 42, 65, 5, 10, 77, 1};
    int sizeSelection = sizeof(arrSelection) / sizeof(arrSelection[0]);
    int arrInsertion[] = {71, 14, 15, 3, 8, 33, 2, 7, 9};
    int sizeInsertion = sizeof(arrInsertion) / sizeof(arrInsertion[0]);
	int arrBubble1[] = {1, 17, 8, 4, 7, 36, 2, 5, 9};
    int sizeBubble1 = sizeof(arrBubble1) / sizeof(arrBubble1[0]);
	int arrBubble2[] = {1,2,3,4,5,6,7,8,9,10};
    int sizeBubble2 = sizeof(arrBubble2) / sizeof(arrBubble2[0]);

 //Selection
    printf("\nArreglo 1 (Selection) original: ");
	PrintArray(arrSelection, sizeSelection);
	printf("\n---> Tamaño del arreglo 1: %d", sizeSelection);
	selectionSort(arrSelection, sizeSelection);
    printf("\nArreglo 1 (Selection) ordenado: ");
    PrintArray(arrSelection, sizeSelection);

	printf("\n==================");
 //Insertion
	printf("\nArreglo 1 (Insertion) original: ");
	PrintArray(arrInsertion, sizeInsertion);
	printf("\n---> Tamaño del arreglo 2: %d ", sizeInsertion);
	InsertionSort(arrInsertion,sizeInsertion);
	printf("\nArreglo 2 (Insertion) ordenado: ");
    PrintArray(arrInsertion, sizeInsertion);
	printf("\n");

		printf("\n==================");
 //Bubble
	printf("\nArreglo 3 (Bubble) original: ");
	PrintArray(arrBubble1, sizeBubble1);
	printf("\n---> Tamaño del arreglo 3: %d ", sizeBubble1);
	InsertionSort(arrBubble1,sizeBubble1);
	printf("\nArreglo 3 (Bubble) ordenado: ");
    PrintArray(arrBubble1, sizeBubble1);
	printf("\n");
  //Bubble
	printf("\nArreglo 4 (Bubble ordenado) original: ");
	PrintArray(arrBubble2, sizeBubble2);
	printf("\n---> Tamaño del arreglo 4: %d ", sizeBubble2);
	InsertionSort(arrBubble2,sizeBubble2);
	printf("\nArreglo 4 (Bubble final): ");
    PrintArray(arrBubble2, sizeBubble2);
	printf("\n");
    
    return 0;
}

//nueva func swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arreglo[], int n) {
    int indiceMenor, i, j;
    for(i = 0; i < n - 1; i++) {
        indiceMenor = i;
        for(j = i + 1; j < n; j++) {
            if(arreglo[j] < arreglo[indiceMenor])
                indiceMenor = j;
        }
        if(i != indiceMenor) {
            swap(&arreglo[i], &arreglo[indiceMenor]);
        }

        printf("\n -- Iteracion numero %d: ", i + 1);
        PrintArray(arreglo, n);
    }
}

void InsertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int index = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > index) {
            lista[j + 1] = lista[j];
            j = j - 1;
            printf("\n -- Iteracion numero %d: ", i + 1);
			PrintArray(lista,n);
        }
        lista[j + 1] = index;
    }
}

void PrintArray(int lista[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
}

void BubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                // Intercambiar elementos
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                swapped = 1;
            }
        }
        
        printf("Lista después de iteración %d:\n", i + 1);
        PrintArray(lista, n);
        if (swapped==0) {
            break;
        }
    }
}