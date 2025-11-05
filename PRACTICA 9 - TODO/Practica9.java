// javac *.java
// java Practica9

import java.util.Scanner;

public class Practica9 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BTree miArbol = null;
        int opcion = 0;
        int orden = 0;

        do {
            System.out.println("\n--- MENÚ ÁRBOL B ---");
            System.out.println("1. Crear Árbol");
            System.out.println("2. Agregar un valor");
            System.out.println("3. Buscar Valor");
            System.out.println("4. Imprimir árbol");
            System.out.println("5. Salir");
            System.out.print("selecciona una opción: ");

            try {
                opcion = Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("error: ingresa un número válido");
                opcion = 0; 
            }

            switch (opcion) {
                case 1:
                    System.out.print("ingresa el orden (m) del árbol: ");
                    try {
                        orden = Integer.parseInt(sc.nextLine()); 
                        if (orden < 3) {
                            System.out.println("el orden debe ser al menos 3");
                        } else {
                            miArbol = new BTree(orden);
                            System.out.println("árbol B de orden " + orden + " creado");
                        }
                    } catch (NumberFormatException e) {
                        System.out.println("error: ingresa un número válido para el orden \"m\"");
                    }
                    break;

                case 2:
                    if (miArbol == null) {
                        System.out.println("error: primero debes crear el árbol");
                    } else {
                        System.out.print("ingresa el valor a agregar: ");
                        try {
                            int valor = Integer.parseInt(sc.nextLine()); 
                            miArbol.add(valor);
                            System.out.println("valor: " + valor + " agregado");
                        } catch (NumberFormatException e) {
                            System.out.println("error: ingresa un número válido");
                        }
                    }
                    break;

                case 3:
                    if (miArbol == null) {
                        System.out.println("error: primero debes crear el árbol");
                    } else {
                        System.out.print("ingresa el valor a buscar: ");
                        try {
                            int valor = Integer.parseInt(sc.nextLine()); 
                            if (miArbol.find(valor)) {
                                System.out.println("el valor: " + valor + " SÍ se encuentra en el árbol");
                            } else {
                                System.out.println("el valor: " + valor + " NO se encuentra en el árbol");
                            }
                        } catch (NumberFormatException e) {
                            System.out.println("error: ingrese un número válido.");
                        }
                    }
                    break;

                case 4:
                    if (miArbol == null) {
                        System.out.println("error: primero debes crear el árbol");
                    } else {
                        System.out.println("--- Árbol B (orden: " + miArbol.m + ") ---");
                        miArbol.mostrarArbol();
                    }
                    break;

                case 5:
                    System.out.println("saliendo...");
                    break;

                default:
                    if (opcion != 0) { 
                        System.out.println("opción no válida");
                    }
                    break;
            }

        } while (opcion != 5);

        sc.close();
    }
}