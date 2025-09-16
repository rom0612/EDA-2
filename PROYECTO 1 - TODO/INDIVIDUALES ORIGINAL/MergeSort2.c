#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int contOperaciones;
void merge(int arreglo[], int left, int mid, int right);
void mergeSort(int arreglo[], int left, int right);

int main(){
	int arr1[50], arr2[100], arr3[500], arr4[800], arr5[1000], arr6[2000], arr7[5000], arr8[10000];
	int i, size1=50, size2=100, size3=500, size4=800, size5=1000, size6=2000, size7=5000, size8=10000;
	
	srand(time(NULL));
	for(i=0; i<size1; i++){
		arr1[i] = rand();
	}
	for(i=0; i<size2; i++){
		arr2[i] = rand();
	}
	for(i=0; i<size3; i++){
		arr3[i] = rand();
	}
	for(i=0; i<size4; i++){
		arr4[i] = rand();
	}
	for(i=0; i<size5; i++){
		arr5[i] = rand();
	}
	for(i=0; i<size6; i++){
		arr6[i] = rand();
	}
	for(i=0; i<size7; i++){
		arr7[i] = rand();
	}
	for(i=0; i<size8; i++){
		arr8[i] = rand();
	}
	
	contOperaciones = 0;
	mergeSort(arr1, 0, size1-1);
	printf("Total de operaciones para arreglo1[50]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr2, 0, size2-1);
	printf("Total de operaciones para arreglo2[100]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr3, 0, size3-1);
	printf("Total de operaciones para arreglo3[500]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr4, 0, size4-1);
	printf("Total de operaciones para arreglo1[800]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr5, 0, size5-1);
	printf("Total de operaciones para arreglo5[1000]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr6, 0, size6-1);
	printf("Total de operaciones para arreglo6[2000]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr7, 0, size7-1);
	printf("Total de operaciones para arreglo7[5000]: %d \n", contOperaciones);
	
	contOperaciones = 0;
	mergeSort(arr8, 0, size8-1);
	printf("Total de operaciones para arreglo8[10000]: %d \n", contOperaciones);
	
	return 0;
}

void merge(int arreglo[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int izquierda[n1];
        int derecha[n2];
        
        for (int i = 0; i < n1; ++i){
        	contOperaciones++;
            izquierda[i] = arreglo[left + i];
        }
        
        for (int j = 0; j < n2; ++j){
        	contOperaciones++;
            derecha[j] = arreglo[mid + 1 + j];
        }
 
        int i = 0, j = 0;

        int k = left;
        while (i < n1 && j < n2) {
        	contOperaciones++;
            if (izquierda[i] <= derecha[j]) {
                arreglo[k] = izquierda[i];
                i++;
            } else {
                arreglo[k] = derecha[j];
                j++;
            }
            contOperaciones++;
            k++;
        }

        while (i < n1) {
        	contOperaciones++;
            arreglo[k] = izquierda[i];
            i++;
            k++;
        }
       
        while (j < n2) {
        	contOperaciones++;
            arreglo[k] = derecha[j];
            j++;
            k++;
        }
    }

void mergeSort(int arreglo[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arreglo, left, mid);
            mergeSort(arreglo, mid + 1, right);
            merge(arreglo, left, mid, right);
        }
    }
