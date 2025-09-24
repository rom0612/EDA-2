import java.util.HashMap; 
import java.util.Map; 
public class Practica5AvanceProfe { 
    public static void main(String[] args) { 
        HashMap<Integer, String> personas = new HashMap<>(); 

        personas.put(3011, "Juan Pérez"); 
        personas.put(2134, "María García"); 
        personas.put(4444, "Carlos López"); 
        personas.put(3040, "Ana Torres"); 

        System.out.println("Contenido del HashMap: " + personas); 
        int idBuscar = 2134; 
        
        if (personas.containsKey(idBuscar)) { 
            System.out.println("El ID " + idBuscar + " existe y pertenece a: " + personas.get(idBuscar)); 
        } else { 
            System.out.println("El ID " + idBuscar + " no existe."); 
        } 

        String nombreBuscar = "Carlos López"; 

        if (personas.containsValue(nombreBuscar)) { 
            System.out.println("El nombre " + nombreBuscar + " se encuentra en el HashMap."); 
        } else { 
            System.out.println("El nombre " + nombreBuscar + " no se encuentra en el HashMap."); 
        } 

        String nombre = personas.get(4444); 
        System.out.println("El nombre asociado al ID 3 es: " + nombre);   
    } 
}