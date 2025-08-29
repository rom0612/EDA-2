#include <stdio.h>
#include <stdbool.h>

void BubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                // Intercambiar elementos
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                swapped = true;
            }
        }
        
        printf("Lista después de iteración %d:\n", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", lista[k]);
        }
        printf("\n");
        
        // Si no hubo intercambios, el array ya está ordenado
        if (!swapped) {
            break;
        }
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
    
    BubbleSort(lista, n);
    
    printf("\nLista ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
    return 0;
}