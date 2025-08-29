#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila *crearPila(int n){
    Pila *nuevaPila;
    //1. crear la pila y el arreglo de la pila
    nuevaPila = (Pila *)malloc(1 *sizeof(Pila)); //CREA LA ESTRUCTURA PILA CON TODOS SUS ELEMENTOS
    nuevaPila->arrPila = (Cancion *)calloc(n , sizeof(Cancion));//CREANDO EL ARREGLO DE LA PILA
    //2. INICIALIZA VALORES
    nuevaPila->tope =-1;
    nuevaPila->max = n;
    return nuevaPila;
}

int pilaLLena(Pila *pila){
    return (pila->tope == pila->max-1);
}
void push(Cancion dato,Pila *pila){
    pila->tope++;
    pila->arrPila[pila->tope] = dato;
}
void listarPila(Pila pila){
    Cancion* i;
    for (i = pila.arrPila + pila.tope; i >= pila.arrPila; i--)
        listarCancion(*i);
}
int pilaVacia(Pila *pila){
    return (pila->tope == -1);
}
Cancion pop(Pila *pila){
    Cancion aux = pila->arrPila[pila->tope];
    pila->tope--;
    return aux;
}
void inicializarPila(Pila *pila){
    pila->tope = -1;
}


void liberarPila(Pila *pila){
    if (pila != NULL)
    {
        free(pila->arrPila);
        free(pila);
        pila = NULL;
    }
}
