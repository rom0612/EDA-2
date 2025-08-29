

public class Principal {
    
    public static void main(String args[]){  
        int[] arr1 = {9,14,3,2,43,11,58,22}; 
        int[] arr2 = {10,15,4,3,44,12,59,23}; 

        System.out.println("Arreglos Originales");  
        Utilerias.imprimirArreglo(arr1);
        Utilerias.imprimirArreglo(arr2);
        
        Insercion.insertionSort(arr1);
        
        Seleccion seleccion = new Seleccion();   
        seleccion.selectionSort(arr2);  
       
             
        System.out.println("Arreglos ordenados");  
        Utilerias.imprimirArreglo(arr1);
        Utilerias.imprimirArreglo(arr2);
        
    }  
    
   
}
