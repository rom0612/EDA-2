public class ArbolTareas {
    private Nodo raiz;

    public ArbolTareas() {
        this.raiz = null;
    }

    public void insertar(Tarea tarea) {
        raiz = insertarRecursivo(raiz, tarea);
    }

    private Nodo insertarRecursivo(Nodo actual, Tarea tarea) {
        if (actual == null) {
            System.out.println("tarea agregada con éxito");
            return new Nodo(tarea);
        }

        if (tarea.prioridad < actual.tarea.prioridad) {
            actual.izq = insertarRecursivo(actual.izq, tarea);
        } 
        else if (tarea.prioridad > actual.tarea.prioridad) {
            actual.der = insertarRecursivo(actual.der, tarea);
        } else {
            System.out.println("error: Ya existe una tarea con la prioridad " + tarea.prioridad);
            return actual;
        }
        return actual;
    }

    public Tarea buscarPorPrioridad(int prioridad) {
        Nodo resultado = buscarPrioridadRecursivo(raiz, prioridad);
        return (resultado != null) ? resultado.tarea : null;
    }

    private Nodo buscarPrioridadRecursivo(Nodo actual, int prioridad) {
        if (actual == null || actual.tarea.prioridad == prioridad) {
            return actual;
        }

        if (prioridad < actual.tarea.prioridad) {
            return buscarPrioridadRecursivo(actual.izq, prioridad);
        }
        
        return buscarPrioridadRecursivo(actual.der, prioridad);
    }

    public Tarea buscarPorNombre(String nombre) {
        return buscarNombreRecursivo(raiz, nombre);
    }

    private Tarea buscarNombreRecursivo(Nodo actual, String nombre) {
        if (actual == null) {
            return null;
        }

        if (actual.tarea.nombre.equalsIgnoreCase(nombre)) {
            return actual.tarea;
        }

        Tarea tareaEncontrada = buscarNombreRecursivo(actual.izq, nombre);
        
        if (tareaEncontrada == null) {
            tareaEncontrada = buscarNombreRecursivo(actual.der, nombre);
        }

        return tareaEncontrada;
    }

    public void mostrarTareasOrdenadas() {
        recorridoEnOrden(raiz);
    }

    private void recorridoEnOrden(Nodo nodo) {
        if (nodo != null) {
            recorridoEnOrden(nodo.izq);   
            System.out.print(nodo.tarea);   
            recorridoEnOrden(nodo.der);     
        }
    }
    
    public void eliminar(int prioridad) {
        raiz = eliminarRecursivo(raiz, prioridad);
    }

    private Nodo eliminarRecursivo(Nodo actual, int prioridad) {
        if (actual == null) {
            return null; 
        }

        if (prioridad < actual.tarea.prioridad) {
            actual.izq = eliminarRecursivo(actual.izq, prioridad);
        } else if (prioridad > actual.tarea.prioridad) {
            actual.der = eliminarRecursivo(actual.der, prioridad);
        } else {
            
            if (actual.izq == null && actual.der == null) {
                return null;
            }
            if (actual.der == null) {
                return actual.izq;
            }
            if (actual.izq == null) {
                return actual.der;
            }
            Nodo sucesor = encontrarMinimo(actual.der);
            actual.tarea = sucesor.tarea;
            actual.der = eliminarRecursivo(actual.der, sucesor.tarea.prioridad); 
        }
        return actual;
    }

    private Nodo encontrarMinimo(Nodo nodo) {
        return nodo.izq == null ? nodo : encontrarMinimo(nodo.izq);
    }
}