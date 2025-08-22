#include <stdio.h>

void InsertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int index = lista[i];
        int j = i - 1;
        while (j >= 0 && lista[j] > index) {
            lista[j + 1] = lista[j];
            j = j - 1;
            printf("List hasta el momento:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
        }
        lista[j + 1] = index;
    }
}

int main() {
    int lista[] = {25, 10, 18, 40, 3, 35, 2, 8, 21, 23, 300, 150, 30, 14, 27, 29, 48, 23, 19, 2};
    int n = 20;  

    printf("LISTA ORIGINAL:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
    InsertionSort(lista, n);
    
    
    printf("List ordenada:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
    
    return 0;
}