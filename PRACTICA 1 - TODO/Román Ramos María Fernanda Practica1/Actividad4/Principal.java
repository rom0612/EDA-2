public class Principal {
    public static void main(String args[]){  
        int[] arr1 = {9,14,3,2,43,11,58,22}; 
        int[] arr2 = {10,15,4,3,44,12,59,23}; 
        int[] arr3 = {8,13,2,1,42,10,57,21}; 

        System.out.println("Arreglos Originales");  
        Utilerias.imprimirArreglo(arr1);
        Utilerias.imprimirArreglo(arr2);
        Utilerias.imprimirArreglo(arr3);
        
        //INSERTION
        Insercion.insertionSort(arr1);
        
        //SELECTION
        Seleccion seleccion = new Seleccion();   
        seleccion.selectionSort(arr2);  
        
        //BUBBLE
        Burbuja.bubbleSort(arr3);
        
        //Imprimir desp. de ordenar
        System.out.println("\nArreglos ordenados");  
        System.out.print("Inserción: ");
        Utilerias.imprimirArreglo(arr1);
        System.out.print("Selección: ");
        Utilerias.imprimirArreglo(arr2);
        System.out.print("Bubble:   ");
        Utilerias.imprimirArreglo(arr3);
        
    }   
}


