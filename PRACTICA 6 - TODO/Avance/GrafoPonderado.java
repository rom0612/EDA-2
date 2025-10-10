/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Edgar
 */
import java.util.*;

public class GrafoPonderado {
    private List<String> vertices;
    private List<List<Arista>> listaAdyacencia;
    private boolean dirigido;

    public GrafoPonderado(boolean dirigido) {
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

    public void agregarArista(String v1, String v2, int peso) {
        int i1 = vertices.indexOf(v1);
        int i2 = vertices.indexOf(v2);
        if (i1 != -1 && i2 != -1) {
            listaAdyacencia.get(i1).add(new Arista(i2, peso));
            if (!dirigido) {
                listaAdyacencia.get(i2).add(new Arista(i1, peso));
            }
        }
    }


    public void imprimirGrafo() {
        for (int i = 0; i < vertices.size(); i++) {
            System.out.print(vertices.get(i) + " -> ");
            for (Arista arista : listaAdyacencia.get(i)) {
                System.out.print(vertices.get(arista.destino) + "(" + arista.peso + ") ");
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

            for (Arista arista : listaAdyacencia.get(actual)) {
                if (!visitado[arista.destino]) {
                    visitado[arista.destino] = true;
                    cola.add(arista.destino);
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
        for (Arista arista : listaAdyacencia.get(actual)) {
            if (!visitado[arista.destino]) {
                recorrer(arista.destino, visitado);
            }
        }
    }
}

