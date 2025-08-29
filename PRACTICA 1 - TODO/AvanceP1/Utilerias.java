


public class Utilerias {
    
    public static void imprimirArreglo(int[] arreglo){
        for(int i:arreglo){  
            System.out.print(i+" ");  
        }
        System.out.println(" ");
    }

    public static void intercambiar(int[] arr, int x, int y) {
        int temp = arr[x];   
        arr[x] = arr[y];  
        arr[y] = temp;
    }
}
