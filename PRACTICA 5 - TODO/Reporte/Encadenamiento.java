import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class Encadenamiento {

    public static void main(String[] args) {
        //lista de linkedlists
        ArrayList<LinkedList<Integer>> listaDeListas = new ArrayList<>();
        
        // se llena con LinkedLists vacías
        for (int i = 0; i < 15; i++) {
            listaDeListas.add(new LinkedList<>()); 
        }

        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        boolean salir = false;

        while (!salir) {
            System.out.println("\n----Selecciona una opción:----");
            System.out.println("1. Agregar un número");
            System.out.println("2. Imprimir el estado ");
            System.out.println("3. salir");
            System.out.print("opción: ");

            int opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    System.out.print("Ingresa el número: ");
                    int numero = scanner.nextInt();
                    int posic = random.nextInt(15);
                    listaDeListas.get(posic).add(numero);
                    System.out.println("numero " + numero + " -> posición " + posic );
                    printContenedor(listaDeListas);
                    break;
                case 2:
                    printContenedor(listaDeListas);
                    break;
                case 3:
                    salir = true;
                    System.out.println("saliendo...");
                    break;
                default:
                    System.out.println("opción no válida");
                    break;
            }
        }
        scanner.close();
    }

    public static void printContenedor(ArrayList<LinkedList<Integer>> list) {
        System.out.println("\n---Contenedor---");
        for (int i = 0; i < list.size(); i++) {
            System.out.println("indice: " + i +  " -> valor:" + list.get(i));
        }
    }
}