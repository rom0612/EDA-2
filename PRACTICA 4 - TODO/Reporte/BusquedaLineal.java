import java.util.ArrayList;
public class BusquedaLineal {
    
    public static String seEncuentraInt(ArrayList<Integer>listaEnteros, int valorBuscado){
        for (int elem : listaEnteros){
            if (elem==valorBuscado){
            return "El número " + valorBuscado + " Sí Se encuentra en la lista";
            }
        }
        return "El número " + valorBuscado + " No Se encuentra en la lista";
    }

    public static int buscarInd(ArrayList<Integer>listaEnteros, int valorBuscado){
        for (int i=0; i<listaEnteros.size();i++){
            if (listaEnteros.get(i)==valorBuscado){
            return i;
            }
        }
        return -1;
    }

    public static String contarAp(ArrayList<Integer>listaEnteros, int valorBuscado){
        int apariciones=0;
        for (int i=0; i<listaEnteros.size();i++){
            if (listaEnteros.get(i)==valorBuscado){
            apariciones++;
            }
        }
        return "El número " + valorBuscado + " se encuentra " + apariciones + " veces";
    }
//sobreescribe el metodo recibiendo un arrayList y un String
    public static String contarAp(ArrayList<Computadora>listaCompu, String marca){
        int apariciones=0;
        for (int i=0; i<listaCompu.size();i++){
            Computadora temp = listaCompu.get(i);
            if(temp.getMarca().equalsIgnoreCase(marca)){
                apariciones++;
            }
            }
        return "Hay " + apariciones + " computadoras de la marca " + marca;
    }
    //no puede sobreescribir el metodo xq recibe los mismos argumentos
    public static String contarApMemoria(ArrayList<Computadora>listaCompu, int memoria){
        int apariciones=0;
        for (int i=0; i<listaCompu.size();i++){
            Computadora temp = listaCompu.get(i);
            if(temp.getMemoria()==(memoria)){
                apariciones++;
            }
        }
        return "Hay " + apariciones + " computadoras de memoria " + memoria + "GB";
    }

}//cierre de la clase
