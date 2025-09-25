import java.util.ArrayList;
import java.util.Collections;
public class BusquedaBinaria {
    
    public boolean seEncuentra(ArrayList<Integer>listaEnteros, int valorBuscado){
        Collections.sort(listaEnteros); //ordenarla por si no la dan ordenada
        int binPosicion = Collections.binarySearch(listaEnteros, valorBuscado);
        boolean seEncuentraInt = (binPosicion>=0);
        return seEncuentraInt;
    }

    public static int contarAp(ArrayList<Integer> lista, int inicio, int fin, int x) {
        // caso base!!!!!!!!
        if (inicio > fin) {
            return 0; // regresa q aparece 0 veces
        }
        
        int medio = inicio + (fin - inicio) / 2;
        
        if (lista.get(medio) == x) {
            int contador = 1; 
            contador += contarAp(lista, inicio, medio - 1, x);
            contador += contarAp(lista, medio + 1, fin, x);
            return contador;
        }
        else if (lista.get(medio) > x) {
            return contarAp(lista, inicio, medio - 1, x);
        }
        else {
            return contarAp(lista, medio + 1, fin, x);
        }
    }


}//cierre de clase
