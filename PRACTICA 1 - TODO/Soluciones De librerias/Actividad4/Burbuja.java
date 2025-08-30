public class Burbuja {
    
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;
        
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Intercambiar elementos
                    Utilerias.intercambiar(arr, j, j + 1);
                    swapped = true;
                }
            }
            
            // Si no hubo intercambios, el arreglo ya está ordenado
            if (!swapped) {
                System.out.println("El arreglo ya está ordenado!");
                break;
            }
        }
    }
}