#include <stdio.h>
#include "colaCircular.c"
#include "music.c"
#include "menu.c"
#include "pila.c"

int main() {
    //VARIABLES LOCALES
    Pila *pila;
    int max, opcion;
    Cancion *dato;

    printf("Dame el tamanio de la pila: ");
    scanf ("%i", &max);
    //crear la pila din�micamente
    pila= crearPila(max);

   do {
      printf("\n\nEstructura Pila\n====================");
      opcion = desplegarMenu ("\n1)Push\n2)Pop\n3)Listar\n4)Salir\nOpcion:",4);
      switch (opcion) {
        case 1://push
                if (!pilaLLena(pila)){
                    dato = capturarCancion();
                    push(*dato, pila);
                    listarPila(*pila);
                }
                else
                    printf("\nPila llena....\n");

             break;
        case 2: //pop
                if (!pilaVacia(pila)){
                    printf("\nBORRANDO DATOS DE LA PILA\n");
                    *dato = pop(pila);
                    listarPila(*pila);
                }
                else
                     printf("\nPila vacia....\n");
             break;
        case 3://listar
               listarPila(*pila);
             break;
             
        case 4: liberaMemoria(pila
        );
            break;
      }
    }while (opcion !=4);

    return 0;
}
