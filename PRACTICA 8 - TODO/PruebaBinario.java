

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Edgar
 */
public class PruebaBinario {
    public static void main(String[] args) {
        ArbolBinario arbol = new ArbolBinario();

        arbol.insertar(null, 1, true);
        Nodo raiz = arbol.raiz;

        arbol.insertar(raiz, 2, true);   
        arbol.insertar(raiz, 3, false);  

        Nodo nodo2 = arbol.buscar(2);
        arbol.insertar(nodo2, 4, false); 
        
         Nodo nodo3 = arbol.buscar(3);
          arbol.insertar(nodo3, 14, true); 
      
        Nodo nodo4 = arbol.buscar(4);
        arbol.insertar(nodo4, 6, false);   
       
        Nodo nodo6 = arbol.buscar(6);
        
        arbol.insertar(nodo6, 7, true);  
        arbol.insertar(nodo6, 8, false);  

     
        System.out.println("Imprimir arbol:");
        arbol.imprimirArbol();

        arbol.eliminar(8);
        System.out.println("arbol después de eliminar el 8:");
        arbol.imprimirArbol();
        arbol.eliminar(1);
        System.out.println("arbol después de eliminar el 1:");
        arbol.imprimirArbol();
    
        arbol.imprimirArbol();
        
        
        
    }
}
