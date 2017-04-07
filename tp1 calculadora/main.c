#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int a = 0;
    int b = 0;
    char seguir='s';
    int opcion=0;
    int flaga = 0;
    int flagb = 0;


    while(seguir=='s')
    {
        printf(" \n");
        printf("Elija una opcion de las siguientes: \n");
        printf("------------------------------------- \n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                 a = ingresarOperando();
                 flaga = 1;
                break;
            case 2:
                 b = ingresarOperando();
                 flagb = 1;
                break;
            case 3:
                 calcularsuma (a, b, flaga, flagb);
                break;
            case 4:
                  calcularresta (a, b, flaga, flagb);
                break;
            case 5:
                 calculardivision (a, b, flaga, flagb);
                break;
            case 6:
                 calcularmultiplicacion (a, b, flaga, flagb);
                break;
            case 7:
                 calcularfactorial (a, flaga);
                break;
            case 8:
                llamarTodo (a, b, flaga, flagb);
                break;
            case 9:
                printf("Muchas gracias por utilizar nuestra calculadora \n");
                seguir = 'n';
                break;
        }



}
 return 0;
}
