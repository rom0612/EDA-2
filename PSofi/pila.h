#include "music.h"
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef struct {
    Cancion *arrPila;
    int max;
    int tope;
} Pila;

Pila *crearPila(int max);
int pilaLLena(Pila *pila);
void push(Cancion dato, Pila *pila);
void listarPila(Pila pila);
int pilaVacia(Pila *pila);
Cancion pop(Pila *pila);
void inicializarPila(Pila *pila);
void liberaMemoria(Pila *pila);

#endif // PILA_H_INCLUDED
