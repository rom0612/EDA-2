import java.util.Scanner;

public class Planificador {
    public static void main(String[] args) {
        ArbolTareas arbol = new ArbolTareas();
        Scanner sc = new Scanner(System.in);
        int opcion = 0;

        // inicializar algunas tareas
        arbol.insertar(new Tarea("Hacer reporte", "POO", 10, "15/11/2025"));
        arbol.insertar(new Tarea("Hcer Serie de ejercicios", "Serie 2 de Cálculo vectorial", 5, "12/11/2025"));
        arbol.insertar(new Tarea("Investigación", "Probabilidad", 3, "11/11/2025"));


        while (opcion != 6) {
            System.out.println("\n---- PLANIFICADOR DE TAREAS ----");
            System.out.println("1. agregar nueva tarea");
            System.out.println("2. buscar tarea por nombre");
            System.out.println("3. buscar tarea por prioridad");
            System.out.println("4. mostrar todas las tareas ordenadas por prioridad");
            System.out.println("5. eliminar tarea completada por prioridad");
            System.out.println("6. salir");
            System.out.print("Elige una opción: ");

            try {
                opcion = Integer.parseInt(sc.nextLine());

                switch (opcion) {
                    case 1:
                        System.out.println("nota: no pueden haber tareas con la misma prioridad");
                        System.out.print("Nombre de la tarea: ");
                        String nombre = sc.nextLine();
                        System.out.print("Descripción: ");
                        String descripcion = sc.nextLine();
                        System.out.print("Prioridad (número entero, más pequeño es más importante): ");
                        int prioridad = Integer.parseInt(sc.nextLine());
                        System.out.print("Fecha Límite (DD/MM/AAAA): ");
                        String fecha = sc.nextLine();
                        arbol.insertar(new Tarea(nombre, descripcion, prioridad, fecha));
                        break;

                    case 2:
                        System.out.print("Ingresa el nombre de la tarea a buscar: ");
                        String nombreBusqueda = sc.nextLine();
                        Tarea tareaEncontradaNombre = arbol.buscarPorNombre(nombreBusqueda);
                        if (tareaEncontradaNombre != null) {
                            System.out.println("--- Tarea Encontrada ---");
                            System.out.println(tareaEncontradaNombre);
                        } else {
                            System.out.println("no se encontro ninguna tarea con ese nombre");
                        }
                        break;

                    case 3:
                        System.out.print("Ingresa la prioridad a buscar: ");
                        int prioridadBusqueda = Integer.parseInt(sc.nextLine());
                        Tarea tareaEncontradaPrio = arbol.buscarPorPrioridad(prioridadBusqueda);
                         if (tareaEncontradaPrio != null) {
                            System.out.println("--- Tarea Encontrada ---");
                            System.out.println(tareaEncontradaPrio);
                        } else {
                            System.out.println("No se encontró ninguna tarea con esa prioridad.");
                        }
                        break;

                    case 4:
                        System.out.println("\n--- LISTA DE TAREAS (Ordenadas por prioridad) ---");
                        arbol.mostrarTareasOrdenadas();
                        break;
                        
                    case 5:
                        System.out.print("Ingresa la prioridad de la tarea completada a eliminar: ");
                        int prioridadEliminar = Integer.parseInt(sc.nextLine());
                        if (arbol.buscarPorPrioridad(prioridadEliminar) != null) {
                           arbol.eliminar(prioridadEliminar);
                           System.out.println("tarea con prioridad " + prioridadEliminar + " eliminada");
                        } else {
                           System.out.println("no se encontró una tarea con esa prioridad para eliminar.");
                        }
                        break;

                    case 6:
                        System.out.println("saliendo...");
                        break;

                    default:
                        System.out.println("opción no válida, intenta de nuevo");
                        break;
                }
            } catch (NumberFormatException e) {
                System.out.println("debes ingresar un número válido, intenta de nuevo");
            }
        }
        sc.close();
    }
}