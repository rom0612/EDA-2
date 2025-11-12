public class Nodo {
    Tarea tarea;
    Nodo izq; 
    Nodo der;

    public Nodo(Tarea tarea) {
        this.tarea = tarea;
        this.izq = null;
        this.der = null;
    }
}