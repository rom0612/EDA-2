#include <string.h>
#include "estadisticas.h"

void registrarEstadisticas_nuevaCancionEscuchada(Cancion cancionEscuchada){
    aumentarTotalReproducciones();
    obtenerCasillaEnArregloYaEscuchadas(cancionEscuchada);
}

void registrarEstadisticas_nuevaCancionRegistrada(Cancion cancionRegistrada){
    aumentarTotalCanciones();
    registrarGeneroCancion(cancionRegistrada);
    leerNombreArtista(cancionRegistrada);
    leerNombreCancion(cancionRegistrada);
    leerDuracion(cancionRegistrada);
}

void mostrarEstadisticas(){
    printf("\n1) Total de canciones: %i", totalCanciones);
    printf("\n2) Genero mas popular: %s", generos[obtenerGeneroMasPopular()-1]);
    printf("\n3) Total de reproducciones: %i", totalReproducciones);
    printf("\n4) En promedio cada genero tiene: %.2f canciones", obtenerPromedioCancionesPorGenero());
    printf("\n5) En promedio cada cancion tiene: %.2f reproducciones", obtenerPromedioReproduccionesPorCancion());
    printf("\n6) El ID de la cancion con mas reproducciones es: %i", obtenerIdCancionConMasReproducciones());
    printf("\n7) El ID mas alto, entre las canciones reproducidas es: %i", obtenerIdMasAlto());
    printf("\n8) El artista con nombre mas largo es: %s", artistaConNombreMasLargo);
    printf("9) La cancion con nombre mas largo es: %s", cancionConNombreMasLargo);
    printf("\n10) La cancion mas larga es: %s y dura %i segundos", cancionMasLarga, mayorDuracion);
}

void aumentarTotalCanciones(){
    totalCanciones++;
}

void registrarGeneroCancion(Cancion cancionRegistrada){
    cantidadDeCancionesPorgenero[cancionRegistrada.genero]++;
}

int obtenerGeneroMasPopular(){
    int generoMasPopular = 0;
    for (int i = 0; i < 8; i++){
        if (cantidadDeCancionesPorgenero[i] > cantidadDeCancionesPorgenero[generoMasPopular])
            generoMasPopular = i;
    }
    return generoMasPopular;
}

void aumentarTotalReproducciones(){
    totalReproducciones++;
}

float obtenerPromedioCancionesPorGenero(){
    if (totalCanciones == 0) return 0;
    return (float)totalCanciones / 8; 
}

int obtenerCasillaEnArregloYaEscuchadas(Cancion cancionEscuchada){
    int cancionYaFueEscuchada = 0, i;

    for (i = 0; i < cancionesDiferentesReproducidas; i++){
        if (*yaEscuchadas[i] == cancionEscuchada.ID){
            cancionYaFueEscuchada = 1;
            yaEscuchadas[i][1]++;
            break;
        }
    }
    if (cancionYaFueEscuchada == 0 && i != 49){
        *yaEscuchadas[i] = cancionEscuchada.ID;
        yaEscuchadas[i][1] = 1;
        cancionesDiferentesReproducidas++;
    }

    return i;
}

float obtenerPromedioReproduccionesPorCancion(){
    if (cancionesDiferentesReproducidas == 0) return 0;
    return (float)totalReproducciones / cancionesDiferentesReproducidas;
}

//aritmetica de apuntadores
int obtenerIdCancionConMasReproducciones(){
    int mayorValorEncontrado = -1, (*i)[2], id = -1;
    for (i = yaEscuchadas; i < yaEscuchadas + cancionesDiferentesReproducidas; i++){
        if (*(*i + 1) > mayorValorEncontrado){
            mayorValorEncontrado = *(*i + 1);
            id = **i;
        }
    }
    return id;
}

int obtenerIdMasAlto(){
    int mayorId = -1;

    for (int i = 0; i < cancionesDiferentesReproducidas; i++) {
        if (*yaEscuchadas[i] > mayorId) {
            mayorId = *yaEscuchadas[i];
        }
    }

    return mayorId;
}

void leerNombreArtista(Cancion cancion){
    if (strlen(artistaConNombreMasLargo) < strlen(cancion.artista))
        strcpy(artistaConNombreMasLargo, cancion.artista);
}

void leerNombreCancion(Cancion cancion){
    if (strlen(cancionConNombreMasLargo) < strlen(cancion.nombre))
        strcpy(cancionConNombreMasLargo, cancion.nombre);
}

void leerDuracion(Cancion cancion){
    int duracion = cancion.minutos*60 + cancion.segundos;
    if (duracion > mayorDuracion)
    {
        mayorDuracion = duracion;
        strcpy(cancionMasLarga, cancion.nombre);
    }
}