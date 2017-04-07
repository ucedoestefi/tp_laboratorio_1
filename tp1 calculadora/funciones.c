int ingresarOperando();
void calcularsuma (int a, int b, int flaga, int flagb);
void calcularresta (int a, int b, int flaga, int flagb);
void calculardivision (int a, int b, int flaga, int flagb);
void calcularmultiplicacion (int a, int b, int flaga, int flagb);
void calcularfactorial (int numero, int flaga);
void llamarTodo (int a, int b, int flaga, int flagb);

//int ingresaOperando2 ();

int ingresarOperando()
{
    int x;
    printf("ingrese un valor: ");
    scanf("%d", &x);
    return x;
}

/*int ingresarOperando2 ()
{
    int b;
    printf("ingrese un valor");
    scanf("%d", &b);
    return b;
}
*/

void calcularsuma (int a, int b, int flaga, int flagb)
{
   int suma;

   if(flaga == 1 && flagb == 1)
   {
     suma = a + b;

     printf("la suma es: %d\n", suma);

   }
   else
   {
       printf("Falta ingresar algun numero");
   }
   //printf("ingrese un numero: ");
   //scanf("%d", &suma);

   //return suma;
}

void calcularresta (int a, int b, int flaga, int flagb)
{
   int resta;
   if(flaga == 1 && flagb == 1)
   {
      resta = a - b;
      printf("la resta es: %d\n", resta);
      //return resta;
   }
   else
   {
       printf("Falta ingresar algun numero");
   }

}

void calculardivision (int a, int b, int flaga, int flagb)
{
    float division;

    if(flaga == 1 && flagb == 1)
    {
        if (b !=0)
        {
          division = ((float)a / b);
          printf("la division es: %f\n", division);
        }

       else
       {
         printf("no se puede realizar la operacion por que el divisor es igual cero");
       }
    }
    else
   {
       printf("Falta ingresar algun numero");
   }
}

void calcularmultiplicacion (int a, int b, int flaga, int flagb)
{
    int multiplicacion;
    if(flaga == 1 && flagb == 1)
    {
      multiplicacion = a*b;
      printf("la multiplicacion es: %d\n", multiplicacion);
      //return multiplicacion;
    }
    else
   {
       printf("Falta ingresar algun numero");
   }

}

void calcularfactorial (int numero, int flaga)
{
   //int numero;
   int factorial = 0;
   int i = 0;
   if (flaga == 1)
   //printf("ingrese un numero: ");
   {
       if (numero>=0)
          {
            for (i = 1; i < numero; i++)
            {
                factorial = factorial + (numero*i);
            }
            printf("el factorial es %d\n", factorial);
          }
        else
          {
             printf("no se puede realizar el calculo");
          }
    }
        //return factorial;
   else
   {
       printf("debe ingresar el valor a para calcular el factorial");
   }
}


void llamarTodo (int a, int b, int flaga, int flagb)
{
    if(flaga == 1 && flagb == 1)
   {
    calcularsuma (a, b, flaga, flagb);
    calcularresta (a, b, flaga, flagb);
    calculardivision (a, b, flaga, flagb);
    calcularmultiplicacion (a, b, flaga, flagb);
    calcularfactorial (a, flaga);
   }
   else
   {
       printf("Falta ingresar algun valor");
   }
}

