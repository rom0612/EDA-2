#include <stdio.h>
void selectionSort(int arreglo[], int n);

int main(){
	
    int arr[] = {30,20,70,8,42,65,5,10,77,1};
    int size = 10;
	selectionSort(arr,size);
    return 0;

}


void insertionSort(int a[], int n){
	int i,j,k;
	int aux;

	for(i=1; i<n; i++){
		j=i;
		aux=a[i];
		while (j>0 && aux < a[j-1]){
			a[j] = a[j-1];
			j--;
		}
		a[j]=aux;

	}
}

void selectionSort(int arreglo[], int n){
	int indiceMenor, i, j;
	for (i=0; i<n-1; i++){
		indiceMenor=i;
		for(j = i+1; j<n; j++){
			if(arreglo[j]<arreglo[indiceMenor])
				indiceMenor=j;
		}
		if (i!=indiceMenor){
			//swap(&arreglo[i],&arreglo[indiceMenor]);
		}

		printf("\nIteracion numero %d \n",i+1);
	}
}




//BUBBLE CON MEJORA
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