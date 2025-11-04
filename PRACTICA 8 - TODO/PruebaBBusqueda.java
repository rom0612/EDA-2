// javac *.java
// java PruebaBBusqueda

public class PruebaBBusqueda {
    public static void main(String[] args) {
        ArbolBinarioBusqueda abb = new ArbolBinarioBusqueda();

        abb.insertar(50);
        abb.insertar(30);
        abb.insertar(70);
        abb.insertar(20);
        abb.insertar(40);
        abb.insertar(60);
        abb.insertar(80);
        System.out.println("arbol Inicial:");
        abb.imprimirArbol();
        // nuevps nodos 
        abb.insertar(10); // hijo izq de 20
        abb.insertar(65); // hijo izq de 70
        abb.insertar(55); // hijo izq de 60
        abb.insertar(45); // hijo der de 40

        System.out.println("arbol después de añadir más nodos:");
        abb.imprimirArbol();
        
        System.out.println("\n--- eliminar 70 ---");
        abb.eliminar(70);
        abb.imprimirArbol();
        
        System.out.println("\n--- eliminar 10 ---");
        abb.eliminar(10);
        abb.imprimirArbol();

        Nodo encontrado = abb.buscar(40);
        System.out.println("\nBúsqueda de 40: " + (encontrado != null ? "encontrado" : "no Encontrado"));
        Nodo noEncontrado = abb.buscar(99);
        System.out.println("Búsqueda de 99: " + (noEncontrado != null ? "encontrado" : "no Encontrado"));

        System.out.println("\n--recorrido inorden:");
        abb.inorden(abb.raiz);
        System.out.println("\n--recorrido preorden:");
        abb.preorden(abb.raiz);
        System.out.println("\n--recorrido posorden:");
        abb.posorden(abb.raiz);
        System.out.println("\n");
    }
}