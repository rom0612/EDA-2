// javac *.java
// java MenuArboles

import java.util.Scanner;

public class MenuArboles {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int opcion;
        do {
            mostrarMenuPrincipal();
            opcion = leerOpcion();

            switch (opcion) {
                case 1:
                    pArbolBinario();
                    break;
                case 2:
                    pArbolBinarioBusqueda();
                    break;
                case 3:
                    System.out.println("saliendo..");
                    break;
                default:
                    System.out.println("opción no válida");
            }
        } while (opcion != 3);
    }

    private static void mostrarMenuPrincipal() {
        System.out.println("\n--- MENU ---");
        System.out.println("1. Árboles Binarios");
        System.out.println("2. Árboles Binarios de Búsqueda");
        System.out.println("3. Salir");
        System.out.print("selecciona una opción: ");
    }

    private static int leerOpcion() {
            return scanner.nextInt();
    }

    public static void pArbolBinario() {
        ArbolBinario arbol = new ArbolBinario();
        int opcionAB;
        int valor, valorPadre;
        Nodo padre;

        do {
            mostrarMenuAB();
            opcionAB = leerOpcion();

            switch (opcionAB) {
                case 1:
                    if (arbol.raiz == null) {
                        System.out.print("ingresa el valor para la RAÍZ: ");
                        valor = scanner.nextInt();
                        arbol.insertar(null, valor, true); 
                    } else {
                        System.out.print("ingresa el valor a insertar: ");
                        valor = scanner.nextInt();
                        System.out.print("ingresa el valor del nodo padre: ");
                        valorPadre = scanner.nextInt();
                        padre = arbol.buscar(valorPadre);
                        if (padre != null) {
                            System.out.print("insertar como hijo IZQUIERDO (I) o DERECHO (D) de " + valorPadre + "?: ");
                            String lado = scanner.next().toUpperCase();//lo pone a mayusculas (apunte2 POO)
                            boolean esIzquierdo = lado.equals("I");//apunte2 POO
                            arbol.insertar(padre, valor, esIzquierdo); 
                        } else {
                            System.out.println( valorPadre + " NO encontrado.");
                        }
                    }
                break;
                case 2:
                    System.out.print("ingresa el valor a eliminar: ");
                    valor = scanner.nextInt();
                    arbol.eliminar(valor);
                    break;
                case 3:
                    System.out.print("ingresa el valor a buscar: ");
                    valor = scanner.nextInt();
                    padre = arbol.buscar(valor);
                    System.out.println((padre != null ? "valor " + valor + " encontrado." : "valor " + valor + " NO encontrado."));
                    break;
                case 4: 
                    arbol.imprimirArbol();
                    break;
                case 5: 
                    System.out.print("recorrido preorden (Raíz, Izq, Der): ");
                    arbol.preorden(arbol.raiz);
                    System.out.println();
                    break;
                case 6: 
                    System.out.print("recorrido inorden (Izq, Raíz, Der): ");
                    arbol.inorden(arbol.raiz);
                    System.out.println();
                    break;
                case 7: 
                    System.out.print("recorrido iostorden (Izq, Der, Raíz): ");
                    arbol.posorden(arbol.raiz);
                    System.out.println();
                    break;
                case 8: 
                    System.out.println("regresando al menú principal");
                    break;
                default:
                    System.out.println("opción no válida");
            }
        } while (opcionAB != 8);
    }

    private static void mostrarMenuAB() {
        System.out.println("\n--- ÁRBOLES BINARIOS ---");
        System.out.println("1. Insertar dato");
        System.out.println("2. Eliminar dato");
        System.out.println("3. Buscar dato");
        System.out.println("4. Imprimir árbol ");
        System.out.println("5. Notación Prefija (preorden)");
        System.out.println("6. Notación Infija (inorden)");
        System.out.println("7. Notación Postfija (postorden)");
        System.out.println("8. Regresar al menú principal");
        System.out.print("Selecciona una opción: ");
    }

    public static void pArbolBinarioBusqueda() {
        ArbolBinarioBusqueda abb = new ArbolBinarioBusqueda();
        int opcionABB;
        int valor;
        Nodo encontrado;

        do {
            mostrarMenuABB();
            opcionABB = leerOpcion();

            switch (opcionABB) {
                case 1:
                    System.out.print("ingresa el valor a insertar: ");
                    valor = scanner.nextInt();
                    abb.insertar(valor);
                    break;
                case 2: // 2. Buscar
                    System.out.print("ingresa el valor a buscar: ");
                    valor = scanner.nextInt();
                    encontrado = abb.buscar(valor);
                    System.out.println((encontrado != null ? "valor " + valor + " encontrado." : "valor " + valor + " NO encontrado."));
                    break;
                case 3: 
                    System.out.print("ingresa el valor a eliminar: ");
                    valor = scanner.nextInt();
                    abb.eliminar(valor);
                    break;
                case 4: 
                    abb.imprimirArbol();
                    break;
                case 5: 
                    System.out.print("recorrido preorden (Raíz, Izq, Der): ");
                    abb.preorden(abb.raiz);
                    System.out.println();
                    break;
                case 6: // 6. Inorden
                    System.out.print("recorrido inordn (Izq, Raíz, Der): ");
                    abb.inorden(abb.raiz);
                    System.out.println();
                    break;
                case 7:
                    System.out.print("recorrido postorden (Izq, Der, Raíz): ");
                    abb.posorden(abb.raiz);
                    System.out.println();
                    break;
                case 8:
                    System.out.println("regresando al menú principal");
                    break;
                default:
                    System.out.println("opción no válida");
            }
        } while (opcionABB != 8);
    }

    private static void mostrarMenuABB() {
        System.out.println("\n--- ÁRBOLES BINARIOS DE BÚSQUEDA ---");
        System.out.println("1. Insertar dato");
        System.out.println("2. Buscar dato");
        System.out.println("3. Eliminar dato");
        System.out.println("4. Imprimir árbol");
        System.out.println("5. Preorden");
        System.out.println("6. Inorden");
        System.out.println("7. Postorden");
        System.out.println("8. Regresar al menú principal");
        System.out.print("Selecciona una opción: ");
    }
}