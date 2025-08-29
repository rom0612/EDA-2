#include "music.h"
#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

int totalCanciones = 0, totalReproducciones = 0, cantidadDeCancionesPorgenero[8] = {0}, cancionesDiferentesReproducidas = 0, mayorDuracion = 0, yaEscuchadas[50][2] = {0}; //[0] ID //[1] reproducciones
char artistaConNombreMasLargo[50] = "", cancionConIdMasAlto[50] = "", cancionConNombreMasLargo[50] = "", cancionMasLarga[50] = "";

void registrarEstadisticas_nuevaCancionEscuchada(Cancion cancionEscuchada);
void registrarEstadisticas_nuevaCancionRegistrada(Cancion cancionRegistrada);
void mostrarEstadisticas();

void aumentarTotalCanciones();
void registrarGeneroCancion(Cancion cancionRegistrada);
int obtenerGeneroMasPopular();

void aumentarTotalReproducciones();
float obtenerPromedioCancionesPorGenero();
float obtenerPromedioReproduccionesPorCancion();

int obtenerCasillaEnArregloYaEscuchadas(Cancion cancionEscuchada);
int obtenerIdCancionConMasReproducciones();
int obtenerIdMasAlto();

void leerNombreArtista(Cancion cancion);
void leerNombreCancion(Cancion cancion);
void leerDuracion(Cancion cancion);

#endif