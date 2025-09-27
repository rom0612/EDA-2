import java.util.ArrayList;
import java.util.Collections;
public class BusquedaBinaria {
    
    public static String seEncuentra(ArrayList<Integer>listaEnteros, int valorBuscado){
        ArrayList<Integer> copia = new ArrayList<>(listaEnteros);
        Collections.sort(copia);
        int binPosicion = Collections.binarySearch(copia, valorBuscado);
        if(binPosicion>=0){
            return "El número " + valorBuscado + " sí se encuentra en la lista";
        }
        return "El número " + valorBuscado + " no se encuentra en la lista";
    }

    public static String contarAp(ArrayList<Integer> lista, int valorBuscado) {
        ArrayList<Integer> copia = new ArrayList<>(lista);
        Collections.sort(copia);
        int apariciones = contarApRec(copia, 0, copia.size()-1, valorBuscado);
        return "el numero " + valorBuscado + " se encuentra " + apariciones + " veces";
    }

    private static int contarApRec(ArrayList<Integer> lista, int inicio, int fin, int valorBuscado) {
        if (inicio > fin) {
            return 0;
        }
        
        int medio = inicio + (fin - inicio) / 2;
        
        if (lista.get(medio) == valorBuscado) {
            int contador = 1; 
            contador += contarApRec(lista, inicio, medio - 1, valorBuscado);
            contador += contarApRec(lista, medio + 1, fin, valorBuscado);
            return contador;
        }
        else if (lista.get(medio) > valorBuscado) {
            return contarApRec(lista, inicio, medio - 1, valorBuscado);
        }
        else {
            return contarApRec(lista, medio + 1, fin, valorBuscado);
        }
    }
}