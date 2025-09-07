public class Principal {
    public static void main(String args[]){  
        int[] arr1 = {9,14,3,2,43,11,58,22,40,1,7,96,45,110,23,74,5,47,44,50};  

        System.out.println("Arreglos Originales");  
        Utilerias.imprimirArreglo(arr1);

        int size=arr1.length; //obtener el tamaño del arreglo
        //pasarle a Quicksort el arreglo, su inicio, y su ultimo indice, que es su numero de elementos menos 1
        Quicksort.QuickSort(arr1, 0, size-1); 
        
        //Imprimir desp. de ordenar
        System.out.println("\nArreglo ordenado");  
        Utilerias.imprimirArreglo(arr1);
        
    }   
}


