#include <stdio.h>
#include <stdlib.h>
#include "music.h"

ColaCircular *crearColaCircular(int max) {
    ColaCircular *nuevaCola;
    //crear la cola y el arreglo
    nuevaCola = malloc(1 * sizeof(ColaCircular));
    if(nuevaCola == NULL)
    {
        printf("Error al asignar memoria");             
    }
    nuevaCola->arrCola = (Cancion *)calloc(max,sizeof(Cancion));
    //INICIALIZAR
    nuevaCola->max = max;
    nuevaCola->h = nuevaCola->t= -1;
    return nuevaCola;
}

int validarEspacio(ColaCircular colaC){
    if ((colaC.h == 0 && colaC.t == colaC.max-1) || (colaC.t == colaC.h-1))
    {
        printf("\nNo hay espacio...\n");
        return 0;
    }
    return 1;
}

void insertar(ColaCircular *colaC, Cancion *dato) {
    if (colaC->h ==-1)
        colaC->h= 0;//INICIO DE LA FILA
    if (colaC->t == colaC->max-1)
        colaC->t = -1;

    colaC->t++;

    //INSERTA EL DATO EN LA FILA
    colaC->arrCola[colaC->t]=*dato;
}

void listar(ColaCircular colaC){
   int i;
   if (!validarVacio(colaC)){
        if (colaC.h<= colaC.t){
           for (i=colaC.h; i<=colaC.t ; i++)
           listarCancion(colaC.arrCola[i]);
        }
        else {
            for (i=colaC.h; i<= colaC.max-1; i++)
                listarCancion(colaC.arrCola[i]);
            for (i=0; i<=colaC.t; i++)
                listarCancion(colaC.arrCola[i]);
        }
   }
   else
        printf("  No hay datos que listar...");
}
int validarVacio(ColaCircular colaC){
    return colaC.h == -1;
}

Cancion borrar(ColaCircular *colaC){
    Cancion aux = colaC->arrCola[colaC->h];
    if (colaC->h == colaC->t)
        colaC->h = colaC->t = -1;
    else if (colaC->h == colaC->max-1)
        colaC->h = 0;
    else
        colaC->h++;

    return aux;
}

void liberarColaCircular(ColaCircular *colaC){
    if (colaC != NULL)
    {
        free(colaC->arrCola);
        free(colaC);
    }
    colaC = NULL;
}
