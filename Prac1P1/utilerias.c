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