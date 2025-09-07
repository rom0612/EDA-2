import java.util.Random;
import java.util.Scanner;

public class Principal {
    public static void main(String args[]){ 
        Scanner sc = new Scanner(System.in);
        System.out.println("¿De qué tamaño desea el arreglo? ");
        int size = sc.nextInt();
        int[] arr1 = new int[size];
        Random random = new Random();
        
        for (int i = 0; i < size ; i++) {
            arr1[i] = random.nextInt(100);
        }  

        System.out.println("Arreglo Original");  
        Utilerias.imprimirArreglo(arr1);

        
        Quicksort.QuickSort(arr1, 0, size-1); 
        
        //Imprimir desp. de ordenar
        System.out.println("\nArreglo ordenado");  
        Utilerias.imprimirArreglo(arr1);
        
        sc.close();
    }   
}


