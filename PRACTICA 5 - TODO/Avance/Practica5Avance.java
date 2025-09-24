import java.util.HashMap; 
import java.util.Map; 
import java.util.Scanner;
public class Practica5Avance { 
    public static void main(String[] args) { 
        HashMap<Integer, String> personas = new HashMap<Integer, String>(); 

        personas.put(3011, "Juan Pérez"); 
        personas.put(2134, "María García"); 
        personas.put(4444, "Carlos López"); 
        personas.put(3040, "Ana Torres"); 

        //impirmir original
        System.out.println("Contenido del HashMap original: " + personas); 
        System.out.println("------");

        //agregar 3 elem con funciones diferentees a put
        personas.putIfAbsent(3011, "Carlos Quinto"); //solo la inserta si no existe la clave, si existe, no hace nada
        personas.putIfAbsent(3014, "Karla Santamaria"); //agregar primero: no existe la clave, entonces crea una nueva con su valor
        System.out.println("HashMap después de putIfAbsent: \n" + personas);
        personas.merge(2134, " Castillo", (valorExistente, nuevoValor) -> valorExistente + nuevoValor); //le añade algo porque encontró la clave
        personas.merge(5555, "Valencia", (valorExistente, nuevoValor) -> valorExistente + nuevoValor); //agregar segundo: no existe la clave, entonces crea una nueva con su valor
        System.out.println("HashMap después de merge: \n" + personas+ "\n");

        int idBuscar = 2134; 
        
        if (personas.containsKey(idBuscar)) { 
            System.out.println("El ID " + idBuscar + " existe y pertenece a: " + personas.get(idBuscar)+ "\n"); 
        } else { 
            System.out.println("El ID " + idBuscar + " no existe."+ "\n"); 
        } 

        String nombreBuscar = "Carlos López"; 

        if (personas.containsValue(nombreBuscar)) { 
            System.out.println("El nombre " + nombreBuscar + " se encuentra en el HashMap." + "\n"); 
        } else { 
            System.out.println("El nombre " + nombreBuscar + " no se encuentra en el HashMap."+ "\n"); 
        } 

        String nombre = personas.get(4444);
        System.out.println("El nombre asociado al ID 3 es: " + nombre+ "\n");    

        //Otros métodos para buscar elementos:
        System.out.println("¿que hay en la clave 3011? "+personas.getOrDefault(3011, "no se encontró")+ "\n"); //clave que SI está
        System.out.println("¿que hay en la clave 3015? "+personas.getOrDefault(3015, "no se encontró")+ "\n"); //clave que no está
        System.out.println("¿Se encuentra Juan Pérez? "+personas.containsValue("Juan Pérez")+ "\n"); // SI ESTÁ devuelve true
        System.out.println("¿Se encuentra Juan Correa? "+personas.containsValue("Juan Correa")+ "\n"); // NO ESTÁ devuelve false
        

        //USO DE SIZE
        System.out.println("El HashMap tiene: " + personas.size() + " elementos\n");

        //iteraciones
        System.out.println("Iteraciones sobre el HashMap:");
        for (Map.Entry<Integer, String> entry : personas.entrySet()) {
            System.out.println("Clave: " + entry.getKey() + ", Valor: " + entry.getValue());
        }

        //remove
        Scanner scanner = new Scanner(System.in);
        System.out.println("Contenido del HashMap: " + personas); 
        System.out.print("Ingrese la clave de la persona que quiere eliminar: ");
        int elim = scanner.nextInt();
        
        if (personas.containsKey(elim)) { //primero verificar si está la clave
            String persElim = personas.remove(elim); //puede almacenar el que se estpa quitando (su valor)
            System.out.println("se eliminó a: " + persElim);
            System.out.println("después de eliminar: " + personas + "\n");
        } else {
            System.out.println("la clave" + elim + " no se encontró.\n");
        }
        scanner.close();

        //más metodos
        System.out.println("== Otros ===");
        
        // clear() - Limpia el HashMap
        HashMap<Integer, String> copiaPersonas = new HashMap<>(personas); // copia el hashmap que se le pasa como argumento en su constructor
        System.out.println("copia: " + copiaPersonas);
        copiaPersonas.clear();
        System.out.println("copia después de clear: " + copiaPersonas);

        // isEmpty() 
        System.out.println("El HashMap está vacío? " + personas.isEmpty());

    } 
}