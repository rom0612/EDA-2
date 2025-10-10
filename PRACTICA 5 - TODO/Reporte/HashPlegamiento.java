import java.util.Scanner;

public class HashPlegamiento{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] arregloB = new int[10][10]; //arreglo de 10x10
        int[] cont = new int[10]; 

        System.out.println("Tamaño del contenedor: 10x10");
        System.out.println("Ingresa 10 claves de 9 dígitos:");

        for (int i = 0; i < 10; i++) {
            System.out.print("Ingresa la clave " + (i + 1) + ": ");
            String claveStr = scanner.next();
            
            // la clave debe ser de 9 dig
            if (claveStr.length() != 9) {
                System.out.println("la clave debe ser de 9 dígitos");
                i--; 
                continue;
            }

            // calculo del hash
            int clave = Integer.parseInt(claveStr);
            String p1 = claveStr.substring(0, 4);
            String p2 = claveStr.substring(4, 8);
            String p3 = claveStr.substring(8, 9);
            long suma = Long.parseLong(p1) + Long.parseLong(p2) + Long.parseLong(p3);
            int posicion = (int) (suma % 10);

            // se usa el arreglo cont para saber en qué posicion de la fila va el nuevo elemento.
            if (cont[posicion] < 10) { 
                int ind2 = cont[posicion];
                arregloB[posicion][ind2] = clave;
                cont[posicion]++; 
                System.out.println("Clave: " + clave + ", suma del plegamiento: " + suma + ", posicion: [" + posicion + "][" + ind2 + "]");
            } else {
                System.out.println("ya no hay espacio para colisiones en " + posicion);
            }
        }

        scanner.close();

        System.out.println("\n---Contenedor---");
        for (int i = 0; i < arregloB.length; i++) {
            System.out.print("índice: " + i + " -> valor: [");
            for (int j = 0; j < arregloB[i].length; j++) {
                System.out.print(arregloB[i][j]);
                if (j < arregloB[i].length - 1) {
                    System.out.print(", ");
                }
            }
            System.out.println("]");
        }
    }
}