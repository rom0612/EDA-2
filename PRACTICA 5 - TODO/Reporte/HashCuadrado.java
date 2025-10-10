import java.util.HashMap;
import java.util.Scanner;

public class HashCuadrado{

    public static void main(String[] args) {
        // la clave es la posición y el valor el número guardado.
        HashMap<Integer, Integer> tablaHash = new HashMap<>(40);
        Scanner scanner = new Scanner(System.in);

        System.out.println("Tamaño del contenedor: 40");
        System.out.println("Ingresa 15 valores: ");

        for (int i = 0; i < 15; i++) {
            System.out.print("Ingresa la clave " + (i + 1) + ": ");
            int clave = scanner.nextInt();
            long cuad = (long) clave * clave;

            // convertir a String para encontrar los de enmedio
            String cuadStr = String.valueOf(cuad);
            int tam = cuadStr.length();
            int medio = tam / 2;

            String cent = cuadStr.substring(medio - 1, medio + 1); //tomo dos digitos con substring
            // parsear a entero
            int numCentral = Integer.parseInt(cent);
            //mod40
            int posicion = numCentral % 40;
            //datos calculados como en la tablita del ejemplo
            System.out.println("Clave: " + clave + ", cuadrado: " + cuad + ", centrales: " + numCentral + ", Posicion: " + posicion);
            
            //prueba lineal
            while (tablaHash.containsKey(posicion)) { //mientas la posicion ya exista, va a recorrer para buscar otra
                System.out.println("** Colisión en la posición " + posicion );
                posicion = (posicion + 1) % 40;
            }

            // guardar la clave
            tablaHash.put(posicion, clave);
            System.out.println("  -> clave " + clave + " guardada en la posicion " + posicion + ".");
        }

        scanner.close();

        // mostrar el contenedor 
        System.out.println("\n---Contenedor---");
        for (int i = 0; i < 40; i++) {
            System.out.println("indice: " + i +  " -> valor:" + tablaHash.get(i));
        }
    }
}