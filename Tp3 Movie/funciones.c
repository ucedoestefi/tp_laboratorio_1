#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

void Inicializar(eMovie* movies)
{
    int i;
    for(i=0; i<20; i++)
    {
        movies[i].estado = 0;
    }
}

int buscarlibre(eMovie* movies)
{
    int i;
    int encontro=-1;

    for(i=0; i<20; i++)
    {
        if(movies[i].estado == 0)
        {
            encontro=i;
            break;
        }
    }
    return encontro;
}

void AltasPeliculas (eMovie* movies, FILE* aMovie)
{
    int a, i;

    if(movies != NULL)
    {
        if(movies -> estado == 0)
        {
            a = buscarlibre(movies);

         printf("ingrese un titulo: \n");
         fflush(stdin);
         gets(movies->titulo);

         printf("ingrese un genero: \n");
         fflush(stdin);
         gets(movies->genero);

         printf("ingrese duracion: \n");
         scanf("%d", &movies->duracion);

         printf("ingrese una descripcion: \n");
         fflush(stdin);
         gets(movies->descripcion);

         printf("ingrese un puntaje: \n");
         scanf("%d", &movies->puntaje);

         printf("ingrese link de imagen: \n");
         fflush(stdin);
         gets(movies->linkImagen);

         movies ->estado =1;

         aMovie = fopen("movie.bin", "ab");
         if(aMovie != NULL)
         {
             fwrite(movies,sizeof(eMovie),1,aMovie);
         }
          fclose(aMovie);
        }
    }
}

void BorrarPelicula (eMovie* movies, FILE* aMovie)
{
    int encontro;
    char auxtitulo[20];

    encontro = 0;

    if(movies != NULL)
    {

       printf("ingrese titulo: \n");
       fflush(stdin);
       gets(auxtitulo);
       aMovie=fopen("movie.bin", "ab");
        if(aMovie!=NULL)
        {
            while((fread(movies,sizeof(eMovie),1,aMovie))!=0)
            {
                if(movies->estado==1)
                    {
                        strlwr(movies->titulo);
                        if(strcmp(movies->titulo,auxtitulo)==0)
                        {
                            encontro = 1;
                            fseek(aMovie,-sizeof(eMovie),SEEK_CUR);
                            movies->estado=0;
                            fwrite(movies,sizeof(eMovie),1,aMovie);
                            break;
                        }
                    }
            }

        }
    }

    if(encontro > 0)
    {
        printf("ha sido borrada\n");
    }
    else
    {
        printf("no existe la pelicula\n");
    }

}

void Modificar(eMovie *movies, FILE *aMovie)
{
    int estado;

    int aux_entModificar;
    char aux_mod[256];

    int opcion=0;

    estado=0;

    printf("Ingrese el Titulo de la pelicula que desea modificar:\n");
    fflush(stdin);
    gets(aux_mod);

    aMovie=fopen("movie.bin", "w+b");

    while(!feof(aMovie))
    {
        fread(movies,sizeof(eMovie),1,aMovie);

        if(stricmp(aux_mod, movies->titulo)==0)
        {

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",movies->titulo,movies->genero,movies->duracion,movies->descripcion,movies->puntaje,movies->linkImagen);

            while (opcion!=7)
            {
                printf("\t\t\tMENU A MODIFICAR\n\n");

                printf("1- Titulo\n");
                printf("2- Genero\n");
                printf("3- Duracion\n");
                printf("4- Descripcion\n");
                printf("5- Puntaje\n");
                printf("6- Link Imagen\n");
                printf("7- Salir\n");

                scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
               printf("Ingrese Titulo a modificar: \n");
               fflush(stdin);
               gets(aux_mod);
               strcpy(movies->titulo, aux_mod);
               break;

            case 2:
              printf("Ingrese Genero a modificar: \n");
              fflush(stdin);
              gets(aux_mod);
              strcpy(movies->genero, aux_mod);
              break;

            case 3:
               printf("Ingrese Duracion a modificar:\n");
               scanf("%d", &aux_entModificar);
               movies->duracion = aux_entModificar;
               break;

            case 4:
               printf("Ingrese Descripcion a modificar: \n");
               fflush(stdin);
               gets(aux_mod);
               strcpy(movies->descripcion, aux_mod);
               break;

            case 5:
               printf("Ingrese Puntaje a modificar: \n");
               scanf("%d", &aux_entModificar);
               movies->puntaje = aux_entModificar;
               break;

            case 6:
               printf("Ingrese Link de Imagen a modificar: \n");
               fflush(stdin);
               gets(aux_mod);
               strcpy(movies->linkImagen, aux_mod);
               break;

            case 7:
                    printf("Salir del menu a modificar");
                    break;
            }
            }
            fseek(aMovie,(-1)*sizeof(eMovie),SEEK_CUR);
            fwrite(movies, sizeof(eMovie), 1, aMovie);

            printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de Imagen: %s\n\n",movies->titulo,movies->genero,movies->duracion,movies->descripcion,movies->puntaje,movies->linkImagen);

            printf("\n\nLa Pelicula se modifico con exito\n");

            estado=0;

            return 0;
        }
    }
    if(estado==1)
    {
        printf("ERROR. No se pudo modificar la pelicula\n");
    }
    fclose(aMovie);
}

/*void generarPagina(eMovie* movies,FILE* aMovie)
{
    FILE* htmlFile;
    aMovie=fopen("movie.bin","rb");
    if(aMovie!=NULL)
    {
        htmlFile=fopen("movieHtml.html","w");
        if(htmlFile!=NULL)
        {
            fprintf(htmlFile,
            "<!DOCTYPE html>\n"
            "<html lang='en'>\n"
            "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
            "<body>\n"
            "    <div class='container'>\n"
            "        <div class='row'>\n");
            while((fread(movies,sizeof(eMovie),1,aMovie))!=1)
            {

               if(movies->estado==1)
               {
                    fprintf(htmlFile,
                    "<article class='col-md-4 article-intro'>\n"
                    "<a href='#'>\n"
                    "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                    "</a>\n"
                    "<h3>\n"
                    "<a href='#'>%s</a>\n"
                    "</h3>\n"
                    "<ul>\n"
                    "<li>Genero:%s</li>\n"
                    "<li>Puntaje:%d</li>\n"
                    "<li>Duracion:%d minutos</li>\n"
                    "</ul>\n"
                    "<p>%s</p>\n"
                    " </article>\n",movies->linkImagen,movies->titulo,movies->genero,movies->puntaje,movies->duracion,movies->descripcion);
               }

            }

            fprintf(htmlFile,
            "</div>\n"
            "</div>\n"
            "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
            "</body>\n"
            "</html>\n");
        }
        else
        {
            printf("El archivo no fue cargado");
            return 0;
        }
    }

    printf("Se genero la pagina web\n");
    fclose(aMovie);
    fclose(htmlFile);


    return 0;
}*/

int GenerarPaginaWeb(eMovie *movies,FILE *aMovie)
{
    int i;

    FILE* htmlFile;

    printf("\t\t\tGENERAR PAGINA WEB\n\n");
    printf("\t\t\t------------------\n\n");

    htmlFile=fopen("moviehtml.html","w");

    int retorno=-1;

    if(htmlFile == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {

        fprintf(htmlFile,"\n<html>");
        fprintf(htmlFile,"\n<head>");
        fprintf(htmlFile,"\n<title>Listado de  peliculas</title>");
        fprintf(htmlFile,"\n</head>");
        fprintf(htmlFile,"\n<body>");

        fprintf(htmlFile,"\n<h4> Titulo : </h4>");

         for(i=0; i<3; i++)
         {
            if(movies->estado !=1)
            {
                fprintf(htmlFile,"\n<!-- Repetir cada pelicula -->");
                fprintf(htmlFile,"\n<article class='col-md-4 article-intro'>");
                fprintf(htmlFile,"\n<a href='#'>");
                fprintf(htmlFile,"\n<img class='img-responsive img-rounded' src='%s' alt=''>",movies->linkImagen);
                fprintf(htmlFile,"\n</a>");
                fprintf(htmlFile,"\n<h3>");
                fprintf(htmlFile,"\n<a href='#'>%s</a>",movies->titulo);
                fprintf(htmlFile,"\n</h3>");
                fprintf(htmlFile,"\n<ul>");
                fprintf(htmlFile,"\n<li>Género:%s</li>",movies->genero);
                fprintf(htmlFile,"\n<li>Puntaje:%d</li>",movies->puntaje);
                fprintf(htmlFile,"\n<li>Duración:%d</li>	",movies->duracion);
                fprintf(htmlFile,"\n</ul>");
                fprintf(htmlFile,"\n<p>%s</p>",movies->descripcion);
                fprintf(htmlFile," \n</article>");
                fprintf(htmlFile,"	\n<!-- Repetir cada pelicula -->");
            }
         }
        fprintf(htmlFile,"</body>");
        fprintf(htmlFile,"</html>");
        retorno=0;
    }
    fclose(htmlFile);
    printf("PAGINA CREADA\n");
    return retorno;
}
