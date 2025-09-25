import java.util.ArrayList;
public class BusquedaLineal {
    
    public boolean seEncuentraInt(ArrayList<Integer>listaEnteros, int valorBuscado){
        for (int elem : listaEnteros){
            if (elem==valorBuscado){
            return true;
            }
        }
        return false;
    }

    public int buscarInd(ArrayList<Integer>listaEnteros, int valorBuscado){
        for (int i=0; i<listaEnteros.size();i++){
            if (listaEnteros.get(i)==valorBuscado){
            return i;
            }
        }
        return -1;
    }

    public int contarAp(ArrayList<Integer>listaEnteros, int valorBuscado){
        int apariciones=0;
        for (int i=0; i<listaEnteros.size();i++){
            if (listaEnteros.get(i)==valorBuscado){
            apariciones++;
            }
        }
        return apariciones;
    }

    public static int contarApCompu(ArrayList<Computadora>listaCompu, String marca){
        //equalsIgnoreCase: no importan mayúsculas y minúsculas 
        int apariciones=0;
        for (int i=0; i<listaCompu.size();i++){
            Computadora temp = listaCompu.get(i);
            if(temp.getMarca().equalsIgnoreCase(marca)){
                apariciones++;
            }
            }
        return apariciones;
    }
}
