import java.util.HashMap;
import java.util.Scanner;

public class HashCuadrado{

    public static void main(String[] args) {
        // Usamos un HashMap donde la clave es la posición (0-39) y el valor es el número guardado.
        HashMap<Integer, Integer> tablaHash = new HashMap<>();
        Scanner scanner = new Scanner(System.in);

        System.out.println("--- Ejercicio 1 (versión HashMap): Hash Cuadrado ---");
        System.out.println("Por favor, ingrese 15 valores (números de 4 dígitos).");

        // El programa solicitará al usuario 15 valores [cite: 2]
        for (int i = 0; i < 15; i++) {
            System.out.print("Ingrese el valor #" + (i + 1) + ": ");
            int clave = scanner.nextInt();

            // Se implementará la función hash cuadrado en conjunto con la operación de módulo [cite: 1]
            long cuadrado = (long) clave * clave;
            // Se complementará con la función hash módulo 40 [cite: 2]
            int posicion = (int) (cuadrado % 40);

            // El caso de haber colisiones se solucionarán por prueba lineal [cite: 4]
            System.out.println("Clave: " + clave + ", Cuadrado: " + cuadrado + ", Posición inicial: " + posicion);
            // Usamos .containsKey() para detectar colisiones
            while (tablaHash.containsKey(posicion)) {
                System.out.println("  -> Colisión en la posición " + posicion + ". Buscando siguiente espacio.");
                posicion = (posicion + 1) % 40;
            }

            // Almacenar el elemento usando .put()
            tablaHash.put(posicion, clave);
            System.out.println("  -> Elemento " + clave + " almacenado en la posición " + posicion + ".");
        }

        scanner.close();

        // Al finalizar de ingresar los elementos se deberá mostrar el contenedor [cite: 4]
        System.out.println("\n--- Estado Final del Contenedor Hash ---");
        for (int i = 0; i < 40; i++) {
            // Usamos .getOrDefault() para obtener el valor o mostrar "(Vacío)" si no existe la clave.
            System.out.println("Posición [" + i + "]: " + (tablaHash.get(i) == null ? "(Vacío)" : tablaHash.get(i)));
        }
    }
}