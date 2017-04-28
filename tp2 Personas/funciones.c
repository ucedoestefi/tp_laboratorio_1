#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


void Inicializar(ePersona persona[])
{

    int i;
    for(i=0; i<20; i++)
        {
            persona[i].estados=0;
    }
}

int buscarlibre(ePersona persona[])
{
    int i;
    int encontro=-1;
    for(i=0; i<20; i++)
    {
        if(persona[i].estados==0)
        {
            encontro=i;
            break;
        }
    }
    return encontro;
}


int ingresarPersona(ePersona persona[], int tam)
{
    int a;
    a = buscarlibre(persona);
  if(a > -1)
  {

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(persona[a].nombre);
    printf("Ingrese un dni: \n");
    scanf("%d", &persona[a].dni);
    printf("Ingrese una edad: \n");
    scanf("%d", &persona[a].edad);
    persona[a].estados=1;
    int i;
    if(a == tam)
    {
        tam++;
    }

    for(i=0; i<tam; i++)
        {
            if((persona[i].dni)==(persona[a].dni) && (a != i))
                {
                    printf("Es la misma persona\n");
                    printf(" \n");
                    persona[a].estados=0;
                    persona[a].dni = 0;
                }
        }
 }
 else
 {
     printf("no hay mas espacio para agregar persona \n");
     printf(" \n");
 }
 return tam;
}

int borrarPersona(ePersona persona[], int tam)
{
    long int dni;
    int i;
    int cont = 0;

    printf("ingrese un dni: \n");
    scanf("%d", &dni);

    for(i=0; i<tam; i++)
    {
        if(persona[i].dni == dni)
        {
            persona[i].estados = 0;
            persona[i].dni = 0;
            printf("El registro se borro exitosamente \n");
            printf(" \n");
            cont++;
            if((i+1) == tam)
            {
                tam--;
            }
        }
    }
      if(cont<1)
      {
          printf("el dni ingresado no existe entre los datos cargados \n");
          printf(" \n");
      }
   return tam;
}

void ordenar(ePersona persona[], int tam)
{
    int i, j, comp;
    ePersona aux;
    for(i=0; i<tam - 1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            comp= strcmp(persona[i].nombre ,persona[j].nombre);
            if(comp>0)
            {
                aux = persona[i];
                persona[i] = persona[j];
                persona[j]= aux;

            }
        }
    }
}


void mostrarLista(ePersona persona[], int tam)
{
    printf("Nombre\t Edad\t DNI\t \n");
    printf(".........................\n");
    ordenar(persona, tam);
    int i;
    for(i=0; i<tam; i++)
    {
        if (persona[i].estados ==1)
        {
            printf("%s\t%d\t%d\n", persona[i].nombre, persona[i].edad, persona[i].dni);
        }
    }

}

void graficoEdades(ePersona persona[], int tam)
{
    int i;
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;
    for(i=0; i<tam; i++)
    {
        if (persona[i].estados==1)
        {
            if((persona[i].edad<=18) && (persona[i].edad > 0))
            {
                c1++;
            }
            else
            {
                if((persona[i].edad>=19)&&(persona[i].edad<35))
                {
                    c2++;
                }
                else
                {
                    c3++;
                }
            }
        }
    }
    printf("<18\t 19-35\t 35>\t\n");
    printf("----------------------");
    for(i=0; i<tam; i++)
    {
        printf(" \n");
        if(c1>0)
        {
            printf("*");
            c1--;
        }
        if(c2>0)
        {
            printf("\t*");
            c2--;
        }
        if(c3>0)
        {
            printf("\t\t*");
            c3--;
        }

    }
    printf(" \n");
}

