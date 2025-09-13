import java.util.Random;
public class Practica3 {

    public static void main(String[] args) {


        int[] arr =  new int[20];
        Random rand = new Random();
        
        for (int i = 0; i < 20; i++) {
            arr[i] = rand.nextInt(100) + 1;
        }
        
        System.out.println("Arreglo original:");
        MergeSort.printArray(arr);
        System.out.println("Tamaño del arreglo: " + arr.length);
        System.out.println("----------------------------");
        MergeSort.iterac = 0;
        MergeSort.mergeSort(arr, 0, arr.length - 1);
        
        System.out.println("Arreglo ordenado:");
        MergeSort.printArray(arr);
    }

}
