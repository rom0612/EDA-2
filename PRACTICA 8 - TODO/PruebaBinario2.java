// javac *.java
// java PruebaBinario2
public class PruebaBinario2 {
    public static void main(String[] args) {
        ArbolBinario arbol = new ArbolBinario();

        // nivel 0: Raíz 10
        arbol.insertar(null, 10, true);
        Nodo n10 = arbol.raiz; 
        //nivel 1
        arbol.insertar(n10, 12, true);   
        arbol.insertar(n10, 20, false);  
        Nodo n12 = arbol.buscar(12);
        Nodo n20 = arbol.buscar(20);
        //nivel 2
        arbol.insertar(n12, 40, true); 
        arbol.insertar(n20, 65, true); 
        arbol.insertar(n20, 13, false); 
        Nodo n40 = arbol.buscar(40);
        Nodo n65 = arbol.buscar(65);
        Nodo n13 = arbol.buscar(13);
        //nivel 3
        arbol.insertar(n40, 33, true); 
        arbol.insertar(n40, 18, false); 
        arbol.insertar(n65, 73, true); 
        arbol.insertar(n65, 19, false); 
        arbol.insertar(n13, 34, true); 
        arbol.insertar(n13, 25, false); 
        Nodo n34 = arbol.buscar(34);
        //nivel 4
        arbol.insertar(n34, 6, false);   
        System.out.println("arbol creado:");
        arbol.imprimirArbol();
        //rwcorridos
        System.out.println("\n---recorrido preorden:");
        arbol.preorden(arbol.raiz);
        System.out.println("\n---recorrido inorden:");
        arbol.inorden(arbol.raiz);
        System.out.println("\n---recorrido posorden:");
        arbol.posorden(arbol.raiz);
        System.out.println();
    }
}