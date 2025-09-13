import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class RomanAvanceP4{
    public static void main(String[] args) {
        List <Integer> lista1 = new ArrayList<>();

        lista1.add(15); //metdo add añade un elemento en la ultima posicion
        lista1.add(80);
        //añadiendo mas add
        lista1.add(41);
        lista1.add(74);
        lista1.add(3);
        lista1.add(8);
        lista1.add(122);

        System.out.println("Estado 1:");
        impLista(lista1);
        

        //Añadri mas valores con los indices donde quiero que se inserten, los demás se mueven a la derecha
        lista1.add(2,300);
        lista1.add(4,500);
        lista1.add(5,700);
        System.out.println("Estado 2:");
        impLista(lista1);

        //Reemplazar elementos
        lista1.set(1,14);
        lista1.set(2,16);
        lista1.set(7,18);
        System.out.println("Estado 3:");
        impLista(lista1);

        //
        List <Integer> lista2, lista3;
        lista2=lista1.subList(2, 4);
        lista3=lista1.subList(2, 4);
        impLista(lista2);
        impLista(lista3);

        //Ver si ambos son iguales, devuelve un booleano
        System.out.println(lista1.equals(lista2));
        System.out.println("====");

        
        //Ordenar la lista
        List <Integer> lista4 = new ArrayList<>(lista1);//lista nueva que copia la original, se le pone como argumento y el constructor dentro de arraylist lo reibe para copiarlos
        Collections.sort(lista4); //ordenar la copia
        impLista(lista4);

        // Métodos para buscar

        boolean estaEnList = lista1.contains(4);//busca el elemento que está en los argumentos
        boolean estaEnList2 = lista1.contains(122);
        int indiceEnc = lista1.indexOf(8);//busca el elemento y si lo encuentra devuelve el indice de donde esta
        int indiceNOEnc = lista1.indexOf(1);//prueba a ver que devuelve si no lo encuentra
        int binPosicion1 = Collections.binarySearch(lista1, 8); // busq binaria, para ver que devuelve si no esta ordenada
        int binPosicion2 = Collections.binarySearch(lista4, 8); // busq binaria, para ver que devuelve si ya esta ordenada
        int binPosicion3 = Collections.binarySearch(lista4, 1); // busq binaria, para ver que devuelve si esta ord pero no esta el elememto

        System.out.println("(lista1) ¿ESTÁ EL 4? (NO) = "+ estaEnList);
        System.out.println("(lista1) ¿ESTÁ EL 122? (si) = "+ estaEnList2);
        System.out.println("(lista1) El numero 8 está en la posición: " + indiceEnc);
        System.out.println("(lista1) El numero 1 está en la posición: (no está) " + indiceNOEnc);
        System.out.println("(lista1) Busqueda binaria del 8: (no está ordenada) " + binPosicion1);
        System.out.println("(lista4) Busqueda binaria del 8: (ya está ordenada) " + binPosicion2);
        System.out.println("(lista4) Busqueda binaria del 1: (no esta el elemnto) " + binPosicion3);

        //Métodos para eliminar
        System.out.println("=============");
        lista1.remove(4); // quita el elemento en el índice que tiene como argumento
        System.out.println("dspues de quitar el indice 4: "+lista1); // imprime la lista linealmente
        lista1.removeFirst(); // elimina el primero
        System.out.println("dspues de quitar el primero: " + lista1);
        lista1.removeLast();  // elimina el último 
        System.out.println("dspues de quitar el ultimo: " + lista1);
        lista1.clear(); // vacía lista1
        System.out.println("dspues de hacer clear(): " +lista1);

        //otros metodos
        System.out.println("la lista 4 esta vacia? " + lista4.isEmpty());
        System.out.println("la lista 1 esta vacia? (si) " + lista1.isEmpty());
        lista4.replaceAll(n -> n * 2);
        System.out.println("lista 4 multiplicada por 2: " + lista4);

    }

    public static void impLista(List <Integer> lista){
        String separacion = "======";
        for (Integer v : lista ){
            System.out.println(v);
        }
        
        System.out.println(separacion); //añadí acá la separacion para no escribirla cada vez
    }

}