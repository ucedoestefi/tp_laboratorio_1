#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    int tam = 0;
    ePersona persona[20];
    Inicializar(persona);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf(" \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                tam = ingresarPersona (persona, tam);
                break;
            case 2:
                tam = borrarPersona (persona, tam);
                break;
            case 3:
                 mostrarLista(persona, tam);
                break;
            case 4:
                graficoEdades(persona, tam);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

