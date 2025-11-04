
import java.util.LinkedList;
import java.util.Queue;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Edgar
 */
public class ArbolBinarioBusqueda {
    public Nodo raiz;

    public ArbolBinarioBusqueda() {
        this.raiz = null;
    }

    public void insertar(int valor) {
        raiz = insertarRec(raiz, valor);
    }

    private Nodo insertarRec(Nodo nodo, int valor) {
        if (nodo == null) {
            return new Nodo(valor);
        }

        if (valor < nodo.valor) {
            nodo.hIzquierdo = insertarRec(nodo.hIzquierdo, valor);
        } else if (valor > nodo.valor) {
            nodo.hDerecho = insertarRec(nodo.hDerecho, valor);
        } 

        return nodo;
    }

    public Nodo buscar(int valor) {
        return buscarRec(raiz, valor);
    }

    private Nodo buscarRec(Nodo nodo, int valor) {
        if (nodo == null || nodo.valor == valor) {
            return nodo;
        }

        if (valor < nodo.valor) {
            return buscarRec(nodo.hIzquierdo, valor);
        } else {
            return buscarRec(nodo.hDerecho, valor);
        }
    }

    public void eliminar(int valor) {
        raiz = eliminarRec(raiz, valor);
    }

    private Nodo eliminarRec(Nodo nodo, int valor) {
        if (nodo == null) {
            return null;
        }

        if (valor < nodo.valor) {
            nodo.hIzquierdo = eliminarRec(nodo.hIzquierdo, valor);
        } else if (valor > nodo.valor) {
            nodo.hDerecho = eliminarRec(nodo.hDerecho, valor);
        } else {
            if (nodo.hIzquierdo == null) {
                return nodo.hDerecho;
            } else if (nodo.hDerecho == null) {
                return nodo.hIzquierdo;
            }

            nodo.valor = valorMinimo(nodo.hDerecho);
            nodo.hDerecho = eliminarRec(nodo.hDerecho, nodo.valor);
        }
        return nodo;
    }

    private int valorMinimo(Nodo nodo) {
        while (nodo.hIzquierdo != null) {
            nodo = nodo.hIzquierdo;
        }
        return nodo.valor;
    }



    public void inorden(Nodo nodo) {
        if (nodo == null) {
            return;
        }
        inorden(nodo.hIzquierdo);
        System.out.print(nodo.valor + " ");
        inorden(nodo.hDerecho);
    }



    public void preorden(Nodo nodo) {
        if (nodo == null) {
            return;
        }
        System.out.print(nodo.valor + " ");
        preorden(nodo.hIzquierdo);
        preorden(nodo.hDerecho);
    }


    public void posorden(Nodo nodo) {
        if (nodo == null) {
            return;
        }
        posorden(nodo.hIzquierdo);
        posorden(nodo.hDerecho);
        System.out.print(nodo.valor + " ");
    }

    public void imprimirArbol() {
        if (raiz == null) {
            System.out.println("El arbol esta vacio.");
            return;
        }

        Queue<Nodo> queue = new LinkedList<>();
        queue.add(raiz);
        int nivel = 0;

        while (!queue.isEmpty()) {
            int nivelTamanio = queue.size();
            System.out.println("Nivel " + nivel + ":");

            while (nivelTamanio > 0) {
                Nodo actual = queue.poll();
                System.out.print("[" + actual.valor + "] ");

                if (actual.hIzquierdo != null) {
                    queue.add(actual.hIzquierdo);
                    System.out.print("(Izq: " + actual.hIzquierdo.valor + ") ");
                }
                if (actual.hDerecho != null) {
                    queue.add(actual.hDerecho);
                    System.out.print("(Der: " + actual.hDerecho.valor + ") ");
                }

                System.out.print(" | ");
                nivelTamanio--;
            }

            System.out.println("\n");
            nivel++;
        }
    }
}
