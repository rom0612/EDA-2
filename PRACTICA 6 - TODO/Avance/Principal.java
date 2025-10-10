/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Edgar
 */
public class Principal {
    public static void main(String[] args) {
        
        Grafo g1 = new Grafo(false); 

        g1.agregarVertice("A");
        g1.agregarVertice("B");
        g1.agregarVertice("C");
        g1.agregarVertice("D");
        g1.agregarVertice("E");

        g1.agregarArista("A", "D");
        g1.agregarArista("A", "E");
        g1.agregarArista("B", "A");
        g1.agregarArista("C", "B");
        g1.agregarArista("D", "B");
        g1.agregarArista("D", "C");
        g1.agregarArista("D", "E");
        g1.imprimirGrafo();
        g1.bfs("A");
        g1.dfs("A");
        
        
        GrafoPonderado g2 = new GrafoPonderado(false); // Grafo ponderado no dirigido

        g2.agregarVertice("A");
        g2.agregarVertice("B");
        g2.agregarVertice("C");
        g2.agregarVertice("D");
        g2.agregarVertice("E");
        g2.agregarVertice("F");

        g2.agregarArista("A", "B", 4);
        g2.agregarArista("A", "C", 2);
        g2.agregarArista("B", "C", 5);
        g2.agregarArista("B", "D", 10);
        g2.agregarArista("C", "D", 3);
        g2.agregarArista("C", "E", 8);
        g2.agregarArista("D", "E", 6);
        g2.agregarArista("D", "F", 7);
        g2.agregarArista("E", "F", 1);

        g2.imprimirGrafo();

        g2.bfs("A");
        g2.dfs("A");
        
        System.out.println("---Nuevos Grafos---");

        System.out.println("\n-- grafo no dirigido - no ponderado");
        Grafo ng1 = new Grafo(false); //grafo no dirigido no ponderado
        ng1.agregarVertice("a");
        ng1.agregarVertice("b");
        ng1.agregarVertice("c");
        ng1.agregarVertice("d");
        ng1.agregarVertice("e");
        ng1.agregarVertice("f");
        ng1.agregarArista("d", "a");
        ng1.agregarArista("a", "c");
        ng1.agregarArista("b", "c");
        ng1.agregarArista("c", "d");
        ng1.agregarArista("d", "e");
        ng1.agregarArista("f", "e");

        ng1.imprimirGrafo();
        ng1.bfs("a");
        ng1.dfs("a");

        GrafoPonderado ng2 = new GrafoPonderado (true); //grafo ponderado dirigido
        System.out.println("\n --grafo ponderado dirigido");
        ng2.agregarVertice("a");
        ng2.agregarVertice("b");
        ng2.agregarVertice("c");
        ng2.agregarVertice("d");
        ng2.agregarVertice("e");
        ng2.agregarVertice("f");
        ng2.agregarArista("d", "a", 5);
        ng2.agregarArista("a", "c", 6);
        ng2.agregarArista("b", "c", 1);
        ng2.agregarArista("c", "d", 3);
        ng2.agregarArista("d", "e", 2);
        ng2.agregarArista("f", "e", 4);
        ng2.imprimirGrafo();
        ng2.bfs("a");
        ng2.dfs("a");
    }
    
}
