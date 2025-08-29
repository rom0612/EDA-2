#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "colaCircular.c"
#include "music.h"
#include "pila.h"
#include "estadisticas.h"

Pila *historial;

Playlist *capturarPlaylist(Playlist *playlistArray){
    Playlist *nuevaPlaylist;
    char nombrePlaylist[MAX_TEXTO];
    int max, casilla;
    printf("\nNombre de la playlist:");
    fgets(nombrePlaylist, MAX_TEXTO, stdin);
    nombrePlaylist[strlen(nombrePlaylist) - 1] = '\0';

    casilla = buscarArreglo(playlistArray, nombrePlaylist);
    if (casilla != -1){
        printf("La playlist %s ya esta en el arreglo", nombrePlaylist);
        return NULL;
    }

    nuevaPlaylist = crearPlaylist(nombrePlaylist);
    //CREA LA COLA CIRCULAR
    printf("Cantidad de canciones maxima de la playlist:");
    scanf("%i",&max);
    nuevaPlaylist->maxCola = max;
    nuevaPlaylist->colaCanciones = crearColaCircular(max);
    return nuevaPlaylist;
}

Playlist *crearPlaylist(char *nombre){
    Playlist* nuevaPlaylist = (Playlist *) malloc(1 * sizeof(Playlist));
    strcpy(nuevaPlaylist->nombre, nombre);
    nuevaPlaylist->cantidadCanciones = 0;
    return nuevaPlaylist;
}

Cancion *capturarCancion(){
    int ID;
    char nombre[MAX_TEXTO], artista[MAX_TEXTO];
    int minutos, segundos, genero;
    printf("\nIngrese ID de cancion: ");
    scanf("%i", &ID);
    getchar();
    printf("\nIngrese nombre de cancion: ");
    fgets(nombre, MAX_TEXTO, stdin);
    nombre[strlen(nombre) - 1] = '\0';
    printf("\nIngrese artista de cancion: ");
    fgets(artista, MAX_TEXTO, stdin);
    printf("\nIngrese duración de la cancion en formato mm:ss ");
    scanf("%i:%i", &minutos, &segundos);
    printf("\nEscoga el genero de la siguiente lista:\n\t1) Pop\n\t2) Rock\n\t3) Hip-Hop\n\t4) K-Pop\n\t5) Reggaeton\n\t6) Electronica\n\t7) Jazz\n\t8) Otro\nIngrese el número: ");
    scanf("%i", &genero);
    return crearCancion(ID, nombre, artista, minutos, segundos, genero);
}

Cancion *crearCancion(int ID, char *nombre, char *artista, int minutos, int segundos, int genero){
    Cancion *nuevaCancion = (Cancion *)malloc(1 * sizeof(Cancion));
    nuevaCancion->ID = ID;
    strcpy(nuevaCancion->nombre, nombre);
    strcpy(nuevaCancion->artista, artista);
    nuevaCancion->minutos = minutos;
    nuevaCancion->segundos = segundos;
    nuevaCancion->genero = genero;
    return nuevaCancion;
}

void listarCancion(Cancion cancion){
    printf("\n\t\tID: %i\n\t\tNombre: %s\n\t\tAutor: %s\t\tDuracion: [%i:%i]\n\t\tGenero: %s\n\n", cancion.ID, cancion.nombre, cancion.artista, cancion.minutos, cancion.segundos, generos[cancion.genero - 1]);
}

void insertarEnPlaylist(Playlist *playlist){
    Cancion *dato;
    if (validarEspacio(*playlist->colaCanciones)){
        dato = capturarCancion();
        insertar(playlist->colaCanciones, dato);
        playlist->cantidadCanciones++;
    }

    registrarEstadisticas_nuevaCancionRegistrada(*dato);

    listar(*playlist->colaCanciones);
    guardarPlaylistCanciones(playlist);
}

void guardarPlaylistCanciones(Playlist *playlist) {
    FILE* datosArch;
    datosArch = fopen(playlist->nombre, "wb");
    if (datosArch == NULL) {
        printf("\nError al guardar las canciones de la playlist %s\n", playlist->nombre);
        return;
    }

    if (!validarVacio(*playlist->colaCanciones)) {
        int i;
        ColaCircular colaC = *playlist->colaCanciones;
        if (!validarVacio(colaC)){
            if (colaC.h <= colaC.t){
            for (i=colaC.h; i<=colaC.t ; i++)
                fwrite(&colaC.arrCola[i], sizeof(Cancion), 1, datosArch);
            }
            else {
                for (i=colaC.h; i<= colaC.max-1; i++)
                   fwrite(&colaC.arrCola[i], sizeof(Cancion), 1, datosArch);
                for (i=0; i<=colaC.t; i++)
                    fwrite(&colaC.arrCola[i], sizeof(Cancion), 1, datosArch);
            }
        }
    }

    fclose(datosArch);
}

void borrarEnPlaylist(Playlist *playlist){
    Cancion dato;
    if (!validarVacio(*playlist->colaCanciones)){
        dato = borrar(playlist->colaCanciones);
        printf ("El dato borrado es:\n");
        listarCancion(dato);
        listar(*playlist->colaCanciones);
    }
    else
        printf("\nNo hay datos en la fila...\n");
}

void listarPlaylist(Playlist *playlist){
    printf("Playlist: %s", playlist->nombre);
    listar(*playlist->colaCanciones);
}

void insertarArreglo(struct playlist *playlistArray, int* maxPlaylists)
{
    Playlist *playlist;
    getchar();
    playlist = capturarPlaylist(playlistArray);
    if (playlist == NULL) return;
    indice++;
    playlistArray[indice]=*playlist;
    crearArchivoArreglo(playlistArray);
    ActualizarDatos(playlistArray, maxPlaylists);
}

void crearArchivoArreglo(struct playlist *playlistArray){
    FILE* datosArch;

    datosArch = fopen(playlistArray[indice].nombre, "wb");
    if (datosArch == NULL) {
        printf("\nError al crear el archivo %s\n", playlistArray[indice].nombre, playlistArray[indice].nombre);
    } else {
        fclose(datosArch);
    }
}

void listarArreglo(struct playlist *playlistArray)
{
    Playlist* casilla;
    for(casilla = playlistArray; casilla <= playlistArray + indice; casilla++)
    {
        printf("\n\t- %s", casilla->nombre);
    }
}

int validarEspacioArreglo(int n)
{
    if (indice < n-1)
        return 1;
    else
        return 0;
}

int validarVacioArreglo()
{
    return (indice == -1); //ARREGLO VACIO
}

int buscarArreglo(struct playlist *playlistArray, char *nomPlaylist)
{
    int casilla;

    for(casilla = 0; casilla <= indice; casilla++)
    {
        if (strcmp((playlistArray + casilla)->nombre,nomPlaylist)==0)
        {
            return casilla;
        }
    }
        return -1;
}
void actualizarArreglo(struct playlist *playlistArray, int casilla, char *nomPlaylist)
{
    strcpy(playlistArray[casilla].nombre,nomPlaylist);

    guardarPlaylistCanciones(&playlistArray[casilla]);
}

char* borrarArreglo(struct playlist *playlistArray, int casilla, int* maxPlaylists)
{
    char *aux = (char*)malloc(MAX_TEXTO * sizeof(char));
    strcpy(aux, playlistArray[casilla].nombre);
    free(&playlistArray[casilla]); //No se libera la cola porque las canciones podrían estar todavía en el historial
    if (casilla != indice) {
        playlistArray[casilla] = playlistArray[indice];
    }
    indice--;
    ActualizarDatos(playlistArray, maxPlaylists);

    return aux;
}

void liberarBiblioteca(Playlist *playlistArray) {
    if (playlistArray != NULL) {
        for (int i = 0; i <= indice; i++) {
            liberarColaCircular(playlistArray[i].colaCanciones);
        }
        free(playlistArray);
    }
}

void reproducirPlaylist(ColaCircular colaC){
    int opcionR;
    Cancion borrada;
    if (!validarVacio(colaC)){ 
        do
        {
            printf("\n==Reproduciendo==\n\n");
            borrada = borrar(&colaC);
            listarCancion(borrada);
            
            if (validarVacio(colaC))
            {
                printf("\nEsa fue la ultima cancion de la playlist");
                opcionR = 2;
            }
            else
            {
                printf("\n\n==Canciones Restantes==\n\n");
                listar(colaC);
                printf("\n¿Desea reproducir la siguiente cancion? \n\n  1) Reproducir siguiente\n  2)Salir\n\n");
                scanf("%d", &opcionR);
            }
            if (!pilaLLena(historial))
                push(borrada, historial);
            else printf("\nNo hay espacio para guardar dato en el historial");

            registrarEstadisticas_nuevaCancionEscuchada(borrada);
        } while (opcionR == 1);
    }
    else
        printf("No hay canciones en la playlist");
}

//Aritmetica de apuntadores
void reproducirPlaylistAleatoria(Playlist* playlistArray){
    srand(time(NULL));
    int r = rand()%indice+1;
    reproducirPlaylist(*((playlistArray+r)->colaCanciones));
}

void verHistorial(){
    listarPila(*historial);
}

void reproducirHistorial(){
    int opcionR;
    Cancion borrada;
    if (!pilaVacia(historial)){ 
        do
        {
            printf("\n==Reproduciendo==\n\n");
            borrada = pop(historial);
            listarCancion(borrada);
            
            if (pilaVacia(historial))
            {
                printf("\nEsa fue la ultima cancion de la playlist");
                opcionR = 2;
            }
            else
            {
                printf("\n\n==Canciones Restantes==\n\n");
                listarPila(*historial);
                printf("\n¿Desea reproducir la siguiente cancion? \n\n  1) Reproducir siguiente\n  2)Salir\n\n");
                scanf("%d", &opcionR);
            }
            registrarEstadisticas_nuevaCancionEscuchada(borrada);
        } while (opcionR == 1);
    }
    else
        printf("No hay canciones en el historial");
}

//aritmetica de apuntadores
void leerArchivosCanciones(Playlist *playlistArray){
    Playlist* playlist;
    FILE* datosArch;
    Cancion cancion;

    for(playlist = playlistArray; playlist <= playlistArray + indice; playlist++) {
        datosArch = fopen(playlist->nombre, "rb");
        playlist->colaCanciones = crearColaCircular(playlist->maxCola);
        if (datosArch == NULL) {
            printf("\nError al abrir el archivo de la playlist %s\n", playlist->nombre);
            continue;
        }
        for (int j = 0; j < playlist->cantidadCanciones; j++){
            fread(&cancion, sizeof(Cancion), 1, datosArch);
            insertar(playlist->colaCanciones, &cancion);
        }
        fclose(datosArch);
    }
}

//aritmetica de apuntadores
void ActualizarDatos(Playlist* playlistArray, int* maxPlaylists){

    FILE *datosArch;
    datosArch = fopen("datos.msc", "wb");

    if (datosArch != NULL) {
        fwrite(&indice, sizeof(int), 1, datosArch);
        fwrite(maxPlaylists, sizeof(int), 1, datosArch);

        for (Playlist* i = playlistArray; i <= playlistArray + indice; i++) {
            fwrite(i, sizeof(Playlist), 1, datosArch);
        }

        fclose(datosArch);
    }
}