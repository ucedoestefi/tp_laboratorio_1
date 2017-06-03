#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    int flag =0;

    eMovie movies[20];
    FILE* aMovie;

    Inicializar(movies);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        if((opcion>0) && (opcion<5))
        {
           /* if((opcion == 1) || (flag ==1) || (opcion ==4))
            {
                if(opcion == 1)
                {
                    flag = 1;
                }*/

        switch(opcion)
        {
            case 1:
                AltasPeliculas (movies, aMovie);
                break;
            case 2:
                BorrarPelicula (movies, aMovie);
                break;
            case 3:
                Modificar(movies, aMovie);
               break;
            case 4:
                GenerarPaginaWeb(movies, aMovie);
                break;
            case 5:
                seguir = 'n';
                break;
       }
            }
            /*else
            {
                printf("primero debe dar de alta una pelicula");
            }
        }*/
        else
        {
            printf("la opcion ingresada no es correcta");
        }
     }


    return 0;
}
