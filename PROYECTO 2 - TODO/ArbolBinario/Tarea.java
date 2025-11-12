public class Tarea {
    String nombre;
    String descripcion;
    int prioridad; 
    String fechaLimite;

    public Tarea(String nombre, String descripcion, int prioridad, String fechaLimite) {
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.prioridad = prioridad;
        this.fechaLimite = fechaLimite;
    }

    @Override
    public String toString() {
        return "------------------------------\n" +
               "prioridad: " + prioridad + "\n" +
               "tarea: " + nombre + "\n" +
               "descripcion: " + descripcion + "\n" +
               "fecha limte: " + fechaLimite + "\n" +
               "------------------------------\n";
    }
}