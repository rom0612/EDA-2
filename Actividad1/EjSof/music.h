#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#define MAX_TEXTO  50

int indice = -1;
char generos[8][20] = {"Pop", "Rock", "Hip-Hop", "K-Pop", "Reggaeton", "Electronica", "Jazz", "Otro"};

typedef struct cancion{
    int ID;
    char nombre[MAX_TEXTO], artista[MAX_TEXTO];
    int minutos, segundos, genero, totalReproducciones;
} Cancion;

typedef struct {
    int max; // tama�o de la cola
    int h;
    int t;
    Cancion *arrCola; //arreglo cola
} ColaCircular;

typedef struct playlist{
    char nombre[MAX_TEXTO];
    int cantidadCanciones, maxCola;
    ColaCircular *colaCanciones;
} Playlist;

//FUNCIONES MUSIC_C
Playlist *capturarPlaylist(Playlist *playlistArray);
Playlist *crearPlaylist(char *nombre);
Cancion *capturarCancion();
void listarCancion(Cancion cancion);
Cancion *crearCancion(int ID, char *nombre, char *artista, int minutos, int segundos, int genero);
void insertarEnPlaylist(Playlist *playlist);
void borrarEnPlaylist(Playlist *playlist);
void listarPlaylist(Playlist *playlist);

//OPERACIONES DEL TAD COLA
void insertar(ColaCircular *colaC, Cancion *dato) ;
Cancion borrar(ColaCircular *colaC);
//OPERACIONES AUXILIARES TAD COLA
ColaCircular *crearColaCircular(int max);
int validarEspacio(ColaCircular colaC);
int validarVacio(ColaCircular colaC);
void listar(ColaCircular colaC);
void liberarColaCircular(ColaCircular *colaC);

void ActualizarDatos(Playlist* playlistArray, int* maxPlaylists);
void leerArchivosCanciones(Playlist *playlistArray);
void guardarPlaylistCanciones(Playlist *playlist);
void crearArchivoArreglo(struct playlist *playlistArray);
void liberarBiblioteca(Playlist *playlistArray);

void insertarArreglo(struct playlist *playlistArray, int* maxPlaylists);
void listarArreglo(struct playlist *playlistArray);
int validarEspacioArreglo(int n);
int validarVacioArreglo();
int buscarArreglo(struct playlist *playlistArray, char *nomPlaylist);
#endif
