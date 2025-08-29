#include <stdio.h>
#include <stdlib.h>
#include "music.c"
#include "menu.c"
#include "pila.c"
#include "estadisticas.c"

int main(){
    historial = crearPila(50);

    int opcion, maxPlaylists, opcionR;
    int casilla;
    char nomPlaylist[MAX_TEXTO];
    FILE *datosArch;
    Playlist *playlistArray, playlist;
    printf("\n===================\nReproductor de musica \"Music.c\"\n===================\n");
    do {
        printf("\n1)Crear nueva biblioteca\n2)Cargar de archivos\nOpcion:");
        scanf("%d",&opcion);
    } while (opcion != 1 && opcion != 2);

    if (opcion == 2){
        datosArch = fopen("datos.msc", "rb");

        if (datosArch == NULL) {
            printf("\nERROR: No se pudo abrir datos.msc\n");
            return 1;
        }
        fread(&indice, sizeof(int), 1, datosArch);
        fread(&maxPlaylists, sizeof(int), 1, datosArch);

        playlistArray = (Playlist *)calloc(maxPlaylists, sizeof(Playlist));
        if (playlistArray == NULL) {
            printf("\nERROR: No se pudo asignar memoria para playlistArray\n");
            fclose(datosArch);
            return 1;
        }
        for (int i = 0; i <= indice; i++) {
            Playlist playlist;
            memset(&playlist, 0, sizeof(Playlist));
            fread(&playlist, sizeof(Playlist), 1, datosArch);

            playlistArray[i] = playlist;
            playlistArray[i].colaCanciones = crearColaCircular(playlist.maxCola);
        }
           
        fclose(datosArch);
        leerArchivosCanciones(playlistArray);
    }
    
    if (opcion == 1){
        datosArch = fopen("datos.msc", "wb");
        if (datosArch == NULL){
            printf("\nERROR CREANDO ARCHIVO");
            return 1;
        }
        printf("\nInserta el numero maximo de playlists en la biblioteca:");
        scanf("%d", &maxPlaylists);
        fwrite(&indice, sizeof(int), 1, datosArch);
        fwrite(&maxPlaylists, sizeof(int), 1, datosArch);
        playlistArray = (Playlist *)calloc(maxPlaylists, sizeof(Playlist));
        fwrite(playlistArray, sizeof(Playlist), maxPlaylists, datosArch);
        fclose(datosArch);
    }
    do{
        printf("\n\nMENU:\n\n1)Crear nueva Playlist\n2)Agregar una cancion a una playlist\n3)Listar una playlist\n4)Listar todas las playlists\n5)Cambiar Nombre de Playlist\n6)Borrar Playlist\n7)Reproducir Playlist\n8)Ver historial\n9)Reproducir historial\n10)Ver Estadisticas\n11)Salir\nOpcion:");
        scanf("%d",&opcion);
        switch (opcion) {
            case 1: //Crear nueva Playlist
                if (validarEspacioArreglo(maxPlaylists))
                {
                    insertarArreglo(playlistArray, &maxPlaylists);

                    datosArch = fopen("datos.msc", "wb");
                    fwrite(&indice, sizeof(int), 1, datosArch);
                    fwrite(&maxPlaylists, sizeof(int), 1, datosArch);
                    fwrite(playlistArray, sizeof(Playlist), maxPlaylists, datosArch);
                    fclose(datosArch);
                }
                else
                    printf("\nERROR: no hay espacio en el arreglo...");

            break;
            case 2: //Agregar una cancion a una playlist
                getchar();
                printf("\nDime el nombre de la playlist: ");
                fgets(nomPlaylist, MAX_TEXTO, stdin);
                nomPlaylist[strlen(nomPlaylist) - 1] = '\0';
                casilla = buscarArreglo(playlistArray, nomPlaylist);
                if (casilla != -1){
                    insertarEnPlaylist(&playlistArray[casilla]);

                    ActualizarDatos(playlistArray, &maxPlaylists);
                }
                else
                    printf("\nLa playlist %s no esta en la biblioteca", nomPlaylist);

            break;
            case 3: //Listar una playlist
                getchar();
                printf("\nDime el nombre de la playlist: ");
                fgets(nomPlaylist, MAX_TEXTO, stdin);
                nomPlaylist[strlen(nomPlaylist) - 1] = '\0';
                casilla = buscarArreglo(playlistArray, nomPlaylist);
                if (casilla != -1){
                    listarPlaylist(&playlistArray[casilla]);
                }  
                else
                    printf("\nLa playlist %s no esta en la biblioteca", nomPlaylist);
            break;
            case 4: //Listar todas las playlists
                if (!validarVacioArreglo())
                {
                    listarArreglo(playlistArray);
                }
                else
                    printf("\nERROR: no hay playlist registradas en el arreglo. . .");
            break;
            case 5: //Cambiar Nombre de Playlist
                getchar();
                printf("\nDime el nombre actual de la playlist: ");
                fgets(nomPlaylist, MAX_TEXTO, stdin);
                nomPlaylist[strlen(nomPlaylist) - 1] = '\0';
                casilla = buscarArreglo(playlistArray, nomPlaylist);
                if (casilla != -1){

                    if (remove(nomPlaylist) != 0){
                        printf("Error borrando nombre.\n");
                        continue;
                    }

                    printf("\nDime el nuevo nombre de la playlist: ");
                    fgets(nomPlaylist, MAX_TEXTO, stdin);
                    nomPlaylist[strlen(nomPlaylist) - 1] = '\0';

                    actualizarArreglo(playlistArray, casilla, nomPlaylist);


                    ActualizarDatos(playlistArray, &maxPlaylists);
                }
                else
                    printf("\nLa playlist %s no esta en la biblioteca", nomPlaylist);
            break;
            case 6: //Borrar Playlist
                getchar();
                printf("\nDime el nombre de la playlist: ");
                fgets(nomPlaylist, MAX_TEXTO, stdin);
                nomPlaylist[strlen(nomPlaylist) - 1] = '\0';
                casilla = buscarArreglo(playlistArray, nomPlaylist);
                if (casilla != -1){

                    if (remove(nomPlaylist) != 0){
                        printf("Error borrando archivo\n");
                        continue;
                    }

                    strcpy(nomPlaylist, borrarArreglo(playlistArray, casilla, &maxPlaylists));

                    ActualizarDatos(playlistArray, &maxPlaylists);

                    printf("Playlist %s borrada", nomPlaylist);
                }
                else
                    printf("\nLa playlist %s no esta en la biblioteca", nomPlaylist);
            break;
            case 7: //Reproducir Playlist
                getchar();
                printf("\nDime el nombre de la playlist: ");
                fgets(nomPlaylist, MAX_TEXTO, stdin);
                nomPlaylist[strlen(nomPlaylist) - 1] = '\0';
                casilla = buscarArreglo(playlistArray, nomPlaylist);

                if (casilla == -1){
                    printf("\nLa playlist %s no esta en la biblioteca", nomPlaylist);
                    continue;
                }

                reproducirPlaylist(*playlistArray[casilla].colaCanciones);
            break;
            case 8: //Ver historial
                verHistorial();
            break;
            case 9: //Reproducir Historial
                reproducirHistorial();
            break;
            case 10: //Ver Estadisticas
                mostrarEstadisticas();
            break;
        }
    } while (opcion != 11);
    liberarPila(historial);
    liberarBiblioteca(playlistArray);
    return 0;
}