// javac *.java
// java PrincipalMenu

import java.util.Scanner;
public class PrincipalMenu {
    public static void main (String[]args){
        Scanner sc = new Scanner(System.in);
        int opcion=0;
        
        while (opcion!=5){
            System.out.println("\n---Menu de grafos---");
            System.out.println("Opciones:");
            System.out.println("1. Crear un grafo dirigido");
            System.out.println("2. Crear un grafo NO dirigido");
            System.out.println("3. Crear un grafo ponderado");
            System.out.println("4. Crear un grafo ponderado dirigido");
            System.out.println("5. Salir");
            System.out.println("Ingresa la opción que deseas: ");
            opcion=sc.nextInt();
            String nomNodo;
            String origen;
            String destino;
            int numeroNodos;
            switch (opcion) {
                case 1:
                    System.out.println("--- Grafo Dirigido (No Ponderado) ---");
                    Grafo grafoDir = new Grafo (true);
                    System.out.println("De cuantos nodos será tu grafo?");
                    numeroNodos =sc.nextInt();
                    sc.nextLine();
                    for(int i=0; i<numeroNodos; i++){
                        System.out.println("Ingresa el nombre del " + (i+1) + " nodo");
                        nomNodo = sc.nextLine();
                        grafoDir.agregarVertice(nomNodo);
                    }
                    System.out.println("cuantas aristas deseas agregar?");
                    int numeroAristas =sc.nextInt();
                    for(int i=0; i<numeroAristas; i++){
                        sc.nextLine();
                        System.out.println("Arista " + (i+1));
                        System.out.print("origen: " );
                        origen = sc.nextLine();
                        System.out.print("destino: " );
                        destino = sc.nextLine();
                        grafoDir.agregarArista(origen, destino);;
                    }
                    System.out.println("\nGrafo Dirigido creado:");
                    grafoDir.imprimirGrafo();
                    break;
                case 2:
                    System.out.println("--- Grafo NO Dirigido (No Ponderado) ---");
                    Grafo grafoNoDir = new Grafo(false); 
                    
                    System.out.println("De cuántos nodos será tu grafo?");
                    numeroNodos = sc.nextInt();
                    sc.nextLine(); 
                    
                    for (int i = 0; i < numeroNodos; i++) {
                        System.out.println("Ingresa el nombre del " + (i + 1) + " nodo:");
                        nomNodo = sc.nextLine();
                        grafoNoDir.agregarVertice(nomNodo);
                    }
                    
                    System.out.println("¿Cuántas aristas deseas agregar?");
                    numeroAristas = sc.nextInt();
                    sc.nextLine(); 
                    
                    for (int i = 0; i < numeroAristas; i++) {
                        System.out.println("Arista " + (i + 1));
                        System.out.print("Vértice 1: ");
                        origen = sc.nextLine();
                        System.out.print("Vértice 2: ");
                        destino = sc.nextLine();
                        grafoNoDir.agregarArista(origen, destino);
                    }
                    
                    System.out.println("\nGrafo NO Dirigido creado:");
                    grafoNoDir.imprimirGrafo();
                    break;
                case 3: 
                    System.out.println("--- Creando Grafo Ponderado NO Dirigido ---");
                    GrafoPonderado grafoPondNoDir = new GrafoPonderado(false); // false
                    
                    System.out.println("De cuántos nodos será tu grafo?");
                    numeroNodos = sc.nextInt();
                    sc.nextLine();
                    
                    for (int i = 0; i < numeroNodos; i++) {
                        System.out.println("Ingresa el nombre del " + (i + 1) + " nodo:");
                        nomNodo = sc.nextLine();
                        grafoPondNoDir.agregarVertice(nomNodo);
                    }
                    
                    System.out.println("¿Cuántas aristas deseas agregar?");
                    numeroAristas = sc.nextInt();
                    sc.nextLine(); 
                    
                    for (int i = 0; i < numeroAristas; i++) {
                        System.out.println("Arista " + (i + 1));
                        System.out.print("Vértice 1: ");
                        origen = sc.nextLine();
                        System.out.print("Vértice 2: ");
                        destino = sc.nextLine();
                        System.out.print("Peso: ");
                        int peso = sc.nextInt();
                        sc.nextLine(); 
                        grafoPondNoDir.agregarArista(origen, destino, peso);
                    }
                    
                    System.out.println("\nGrafo Ponderado NO Dirigido creado:");
                    grafoPondNoDir.imprimirGrafo();
                    break;

                case 4: 
                    System.out.println("--- Grafo Ponderado Dirigido ---");
                    GrafoPonderado grafoPondDir = new GrafoPonderado(true); // true
                    
                    System.out.println("De cuántos nodos será tu grafo?");
                    numeroNodos = sc.nextInt();
                    sc.nextLine();
                    
                    for (int i = 0; i < numeroNodos; i++) {
                        System.out.println("Ingresa el nombre del " + (i + 1) + " nodo:");
                        nomNodo = sc.nextLine();
                        grafoPondDir.agregarVertice(nomNodo);
                    }
                    
                    System.out.println("¿Cuántas aristas deseas agregar?");
                    numeroAristas = sc.nextInt();
                    sc.nextLine(); // Consumir newline
                    
                    for (int i = 0; i < numeroAristas; i++) {
                        System.out.println("Arista " + (i + 1));
                        System.out.print("Origen: ");
                        origen = sc.nextLine();
                        System.out.print("Destino: ");
                        destino = sc.nextLine();
                        System.out.print("Peso: ");
                        int peso = sc.nextInt();
                        sc.nextLine(); 
                        grafoPondDir.agregarArista(origen, destino, peso);
                    }
                    
                    System.out.println("\nGrafo Ponderado Dirigido creado:");
                    grafoPondDir.imprimirGrafo();
                    break;

                case 5:
                    System.out.println("Saliendo..");
                    break;

                default:
                    System.out.println("Opción no válida");
                    break;
            }
        }
        sc.close();
    }
}
