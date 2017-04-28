

typedef struct
{
    char nombre [50];
    int edad;
    long int dni;
    int estados;

}ePersona;

/** \brief Carga los datos de las personas al sistema.
 * \param el array se pasa como parametro.
 */

void inicializar(ePersona persona[]);

/** \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param  lista el array se pasa como parametro.
 * \param  el dni es buscado en el array.
 * \return Retorna el indice en donde se encuentra el elemento con el parametro dni.
 */
int buscarlibre(ePersona persona[]);

/** \brief Ingresa los datos de las personas
 *
 * \param permite ingresar el nombre la edad y el dni
 * \param valida los valores
 * \return retorna tamaño
 */

int ingresarPersona(ePersona[], int tam);

/** \brief Elimina los datos almacenados en el array elegido
 *
 * \param recibe el valor del indice de la funcion buscar por dni
 * \param cambia los valores del array por 0,incluido el estado
 */

int borrarPersona(ePersona persona[], int tam);

/** \brief muestra los datos de un conjunto de personas.
 * \param  conjunto de personas a mostrar datos
 */

void ordenar(ePersona persona[], int tam);

/** \brief imprime los nombres
 *
 * \param ordena los nombres alfabeticamente
 * \return muestra los nombres de las personas ordenados con sus respectivos datos
 */

void mostrarLista(ePersona persona[], int tam);

/** \brief Grafica las personas por su edad
 *
 * \param comprueba cuantas personas hay de cada rango de edad
 * \param las ordena y grafica un "*" por cada persona
 */

void graficoEdades(ePersona persona[], int tam);
