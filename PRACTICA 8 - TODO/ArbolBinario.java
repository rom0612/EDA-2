
    
import java.util.LinkedList;
import java.util.Queue;

public class ArbolBinario {
    public Nodo raiz;

    public ArbolBinario() {
        this.raiz = null;
    }
    
    public void insertar(Nodo padre, int valor, boolean esIzquierdo) {
        Nodo nuevoNodo = new Nodo(valor);
        if (padre == null) {
            if (raiz == null) {
                raiz = nuevoNodo;
                System.out.println("Se establecio " + valor + " como raiz.");
            } else {
                System.out.println("Error: La raiz ya esta establecida.");
            }
        } else {
            if (esIzquierdo) {
                if (padre.hIzquierdo == null) {
                    padre.hIzquierdo = nuevoNodo;
                    System.out.println("Se inserto " + valor + " como hijo izquierdo de " + padre.valor);
                } else {
                    System.out.println("Error: El nodo " + padre.valor + " ya tiene hijo izquierdo.");
                }
            } else {
                if (padre.hDerecho == null) {
                    padre.hDerecho = nuevoNodo;
                    System.out.println("Se inserto " + valor + " como hijo derecho de " + padre.valor);
                } else {
                    System.out.println("Error: El nodo " + padre.valor + " ya tiene hijo derecho.");
                }
            }
        }
    }

    public Nodo buscar(int valor) {
        if (raiz == null) {
            return null;
        }

        Queue<Nodo> queue = new LinkedList<>();
        queue.add(raiz);

        while (!queue.isEmpty()) {
            Nodo temp = queue.poll();
            if (temp.valor == valor) {
                return temp;
            }
            if (temp.hIzquierdo != null) {
                queue.add(temp.hIzquierdo);
            }
            if (temp.hDerecho != null) {
                queue.add(temp.hDerecho);
            }
        }
        return null;
    }

    public void eliminar(int valor) {
        if (raiz == null) {
            return;
        }

        if (raiz.hIzquierdo == null && raiz.hDerecho == null) {
            if (raiz.valor == valor) {
                raiz = null;
            }
            return;
        }

        Queue<Nodo> queue = new LinkedList<>();
        queue.add(raiz);

        Nodo keyNode = null;
        Nodo temp = null;

        while (!queue.isEmpty()) {
            temp = queue.poll();
            if (temp.valor == valor) {
                keyNode = temp;
            }
            if (temp.hIzquierdo != null) {
                queue.add(temp.hIzquierdo);
            }
            if (temp.hDerecho != null) {
                queue.add(temp.hDerecho);
            }
        }

        if (keyNode != null) {
            int valorTemp = temp.valor;
            eliminarNodoMasProfundo(temp);
            keyNode.valor = valorTemp;
        }
    }

    private void eliminarNodoMasProfundo(Nodo delNode) {
        Queue<Nodo> queue = new LinkedList<>();
        queue.add(raiz);
        Nodo temp;

        while (!queue.isEmpty()) {
            temp = queue.poll();
            if (temp == delNode) {
                temp = null;
                return;
            }
            if (temp.hIzquierdo != null) {
                if (temp.hIzquierdo == delNode) {
                    temp.hIzquierdo = null;
                    return;
                } else {
                    queue.add(temp.hIzquierdo);
                }
            }
            if (temp.hDerecho != null) {
                if (temp.hDerecho == delNode) {
                    temp.hDerecho = null;
                    return;
                } else {
                    queue.add(temp.hDerecho);
                }
            }
        }
    }


    public void preorden(Nodo nodo) {
        if (nodo == null) {
            return;
        }
        System.out.print(nodo.valor + " ");
        preorden(nodo.hIzquierdo);
        preorden(nodo.hDerecho);
    }
    public void inorden(Nodo nodo) {
        if (nodo == null) {
            return;
        }
        inorden(nodo.hIzquierdo);
        System.out.print(nodo.valor + " ");
        inorden(nodo.hDerecho);
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
        System.out.println("El �rbol est� vac�o.");
        return;
    }

    Queue<Nodo> queue = new LinkedList<>();
    queue.add(raiz);
    int nivel = 0;

    while (!queue.isEmpty()) {
        int nivelTamanio = queue.size();
      

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

    
