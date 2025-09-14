public class MergeSort {

    static int iterac = 0;

    static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    static void printSubArray(int arr[], int inicio, int fin) {
        for (int i = inicio; i < fin; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    static void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int L[] = new int[n1];
        int R[] = new int[n2];
        for (int i = 0; i < n1; ++i)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[mid + 1 + j];

        //IMPRIMIR L Y R
        System.out.print("L: ");
        printArray(L);
        System.out.print("R: ");
        printArray(R);

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    static void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            System.out.println("ITERACIÓN " + (++iterac) );

            System.out.print("   sublista actual: ");
            printSubArray(arr, left, right);
            System.out.println("---");

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
            System.out.println("iteración " + iterac + " terminada");
            System.out.print("   después del merge: ");
            printSubArray(arr, left, right);
            System.out.println("---");
        }
    }
}