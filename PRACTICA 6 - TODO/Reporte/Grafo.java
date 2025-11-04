/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
    import java.util.*;
/**
 *
 * @author Edgar
 */
public class Grafo {

    private List<String> vertices;
    private List<List<Integer>> listaAdyacencia;
    private boolean dirigido; 

   
    public Grafo(boolean dirigido) {
        this.vertices = new ArrayList<>();
        this.listaAdyacencia = new ArrayList<>();
        this.dirigido = dirigido;
    }


    public void agregarVertice(String nombre) {
        if (!vertices.contains(nombre)) {
            vertices.add(nombre);
            listaAdyacencia.add(new ArrayList<>());
        }
    }


    public void agregarArista(String v1, String v2) {
        int i1 = vertices.indexOf(v1);
        int i2 = vertices.indexOf(v2);
        if (i1 != -1 && i2 != -1) {
            listaAdyacencia.get(i1).add(i2);
            if (!dirigido) {
                listaAdyacencia.get(i2).add(i1);  // Si el grafo no es dirigido, agregamos tambien la arista inversa
            }
        }
    }


    public void imprimirGrafo() {
        for (int i = 0; i < vertices.size(); i++) {
            System.out.print(vertices.get(i) + " -> ");
            for (int vecino : listaAdyacencia.get(i)) {
                System.out.print(vertices.get(vecino) + " ");
            }
            System.out.println();
        }
    }
    public void bfs(String inicio) {
        int idx = vertices.indexOf(inicio);
        if (idx == -1) return;

        boolean[] visitado = new boolean[vertices.size()];
        Queue<Integer> cola = new LinkedList<>();
        
        visitado[idx] = true;
        cola.add(idx);
        
        System.out.print("BFS: ");
        while (!cola.isEmpty()) {
            int actual = cola.poll();
            System.out.print(vertices.get(actual) + " ");
            
            for (int vecino : listaAdyacencia.get(actual)) {
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    cola.add(vecino);
                }
            }
        }
        System.out.println();
    }
    
    public void dfs(String inicio) {
        int idx = vertices.indexOf(inicio);
        if (idx == -1) return;

        boolean[] visitado = new boolean[vertices.size()];
        System.out.print("DFS: ");
        recorrer(idx, visitado); 
        System.out.println();
    }

    private void recorrer(int actual, boolean[] visitado) {
        visitado[actual] = true;      
       
        System.out.print(vertices.get(actual) + " ");

        for (int vecino : listaAdyacencia.get(actual)) {
            if (!visitado[vecino]) 
                recorrer(vecino, visitado);  
            }
       }
}
