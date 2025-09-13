import java.util.LinkedList;

public class AvanceP4Linked {
    public static void main(String[] args) {
        // Crear una LinkedList
        LinkedList<String> paises = new LinkedList<>();
        
        // Agregar elementos (método común con ArrayList)
        paises.add("Mex");
        paises.add("Uru");
        paises.add("Arg");
        paises.add("Col");
        
        System.out.println("Lista inicial: " + paises);
        System.out.println();

        // addFirst() - Agrega al inicio 
        paises.addFirst("Cor");
        System.out.println("Lista después de addFirst: " + paises);
        System.out.println();
        //agrega al final
        
        paises.addLast("Ch");
        System.out.println("Lista después de addLast: " + paises);
        System.out.println();
        
        String primeraCiudad = paises.getFirst();
        System.out.println("Primer pais: " + primeraCiudad);
        System.out.println();
        
        String ultimaCiudad = paises.getLast();
        System.out.println("ultimo pais: " + ultimaCiudad);
        
    }
}
