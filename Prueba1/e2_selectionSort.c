#include <stdio.h>

void SelectionSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min]) {
                min = j;
            }
        }
        // Intercambiar elementos
        int temp = lista[i];
        lista[i] = lista[min];
        lista[min] = temp;
        
        printf("Lista hasta el momento:\n");
        for (int k = 0; k < n; k++) {
            printf("%d ", lista[k]);
        }
        printf("\n");
    }
}

int main() {
    int lista[] = {25, 10, 18, 40, 3, 35, 2, 8};
    int n = 8;  

    printf("LISTA ORIGINAL:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n\n");
    
    SelectionSort(lista, n);
    
    printf("\nLista ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
    return 0;
}