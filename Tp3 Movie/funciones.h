

typedef struct{
    int estado;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];

}eMovie;

/** \brief inicializo en cero una variable
 *
 */

void Inicializar(eMovie*);

/** \brief busca si hay una pelicula
 *
 * \param se le pasa como parametro el estado si es 1 o 0
 * \return retorna encontro
 *
 */

int buscarlibre(eMovie*);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void AltasPeliculas (eMovie*, FILE*);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void BorrarPelicula (eMovie*, FILE*);



void Modificar(eMovie*, FILE*);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int GenerarPaginaWeb(eMovie* ,FILE*);

