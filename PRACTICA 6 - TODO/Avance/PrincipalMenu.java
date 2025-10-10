import java.util.Scanner;
public class PrincipalMenu {
    public static void main (String[]args){
        Scanner sc = new Scanner(System.in);
        int opcion=0;

        System.out.println("---Menu de grafos---");
        
        while (opcion!=5){
            System.out.println("Opciones:");
            System.out.println("1. Crear un grafo dirigido");
            System.out.println("2. Crear un grafo NO dirigido");
            System.out.println("3. Crear un grafo ponderado");
            System.out.println("4. Crear un grafo ponderado dirigido");
            System.out.println("5. Salir");
            System.out.println("Ingresa la opción que deseas: ");
            opcion=sc.nextInt();
            int numeroNodos;
            switch (opcion) {
                case 1:
                    Grafo grafo1 = new Grafo (false);
                    System.out.println("De cuantos nodos será tu grafo?");
                    numeroNodos =sc.nextInt();
                    for(int i=0; i<numeroNodos; i++){
                        sc.nextLine();
                        System.out.println("Ingresa el nombre del " + (i+1) + " nodo");
                        String nomNodo = sc.nextLine();
                        grafo1.agregarVertice(nomNodo);
                    }
                    System.out.println("cuantas aristas deseas agregar?");
                    int numeroAristas =sc.nextInt();
                    for(int i=0; i<numeroAristas; i++){
                        sc.nextLine();
                        System.out.println("Arista " + (i+1));
                        System.out.print("origen: " );
                        String origen = sc.nextLine();
                        System.out.print("destino: " );
                        String destino = sc.nextLine();
                        grafo1.agregarArista(origen, destino);;
                    }
                    grafo1.imprimirGrafo();
                    break;
            
                default:
                    break;
            }
        }

    }
}
