/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Edgar
 */
public class Nodo {
    public int valor;
    public Nodo hIzquierdo;
    public Nodo hDerecho;

    public Nodo(int valor) {
        this.valor = valor;
        this.hIzquierdo = null;
        this.hDerecho = null;
    }
}
