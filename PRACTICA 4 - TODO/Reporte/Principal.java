import java.util.ArrayList;
import java.util.Scanner;
public class Principal {
    public static void main (String [] args){
        ListaComputadoras compus = new ListaComputadoras();
        ListaEnteros nums = new ListaEnteros();
        //inicializar listas
        compus.inicializarlista();
        nums.inicializarlista();
        //obtener listas
        ArrayList <Computadora> listCompus = new ArrayList<>(compus.obtenerLista());
        ArrayList <Integer> listNums = new ArrayList<>(nums.obtenerLista());

        System.out.println("Bienvenido al menú de búsqueda");
        int opcion=0;
        Scanner sc =new Scanner(System.in);

        
        do {

            System.out.println("-----Menú, selecciona una opcion-----");
            System.out.println("1. Búsqueda Lineal de Enteros");
            System.out.println("2. Búsqueda Binaria de Enteros");
            System.out.println("3. Búsqueda de computadoras");
            System.out.println("4. Salir");
            opcion=sc.nextInt();

            switch (opcion) {
                case 1:
                    System.out.println("Qué numero quieres buscar?");
                    int numBuscado=sc.nextInt();
                        System.out.println("-De qué forma quieres buscar el número?-");
                        System.out.println("1. Búsqueda Lbásica (está o no)");
                        System.out.println("2. Buscar índice");
                        System.out.println("3. Buscar apariciones");
                        opcion=sc.nextInt();
                        switch (opcion) {
                            case 1:
                                System.out.println(BusquedaLineal.seEncuentraInt(listNums,numBuscado));
                                break;
                            case 2:
                                int indNum= BusquedaLineal.buscarInd(listNums,numBuscado);
                                System.out.println("El número " + numBuscado + " se encuentra en la posciión " + indNum);
                                break;
                            case 3:
                                System.out.println(BusquedaLineal.contarAp(listNums,numBuscado));
                                break;
                            default:
                                System.out.println("opcion no válida");
                                break;
                        }
                    break;
                case 2:
                    System.out.println("Qué numero quieres buscar?");
                    int numBuscadoB=sc.nextInt();
                        System.out.println("-De qué forma quieres buscar el número?-");
                        System.out.println("1. Búsqueda básica (está o no)");
                        System.out.println("2. Buscar apariciones");
                        opcion=sc.nextInt();
                        switch (opcion) {
                            case 1:
                                System.out.println(BusquedaBinaria.seEncuentra(listNums,numBuscadoB));
                                break;
                            case 2:
                                System.out.println(BusquedaBinaria.contarAp(listNums, numBuscadoB));
                                break;
                            default:
                                System.out.println("opcion no válida");
                                break;
                        }
                    break;
                case 3:
                    System.out.println("-De qué forma quieres buscar el la computadora?-");
                        System.out.println("1. Por marca");
                        System.out.println("2. Por memoria");
                        opcion=sc.nextInt();
                        sc.nextLine();
                        switch (opcion) {
                            case 1:
                                System.out.println("Ingrese la marca que desea buscar");
                                String marca = sc.nextLine();
                                System.out.println(BusquedaLineal.contarAp(listCompus, marca));
                                break;
                            case 2:
                                System.out.println("Ingrese la memoria que desea buscar en GB");
                                int memoriaB = sc.nextInt();
                                System.out.println(BusquedaLineal.contarApMemoria(listCompus, memoriaB));
                                break;
                            default:
                                System.out.println("opcion no válida");
                                break;
                        }
                    break;
                case 4:
                    System.out.println("Saliendo...");
                    break;
                default:
                        System.out.println("Opcion no valida");
                    break;
            }


        } while (opcion!=4);


        sc.close();
    }//cierre d main
}//cierre d clase