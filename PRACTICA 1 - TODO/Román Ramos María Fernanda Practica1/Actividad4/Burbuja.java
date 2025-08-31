public class Burbuja {
    
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        int swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = 0;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    Utilerias.intercambiar(arr, j, j + 1);
                    swapped = 1;
                }
            }
            if (swapped==0) {
                break;
            }
        }
    }
}