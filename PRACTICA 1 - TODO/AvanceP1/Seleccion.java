

public class Seleccion {  
   
    public void selectionSort(int[] arr){  
        int n = arr.length;
        for (int i = 0; i < n - 1; i++){  
            int min = i;  
            for (int j = i + 1; j < n; j++){  
                if (arr[j] < arr[min]){  
                    min = j;  
                }                      
            }  
            
            Utilerias.intercambiar(arr, i,min);
              
                 
        }  
    }  

}  