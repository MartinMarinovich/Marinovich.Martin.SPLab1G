#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"
#include "menu.h"
int main()
{

    srand(time(NULL));
    int opcion;
    int auxMenu;
    int flagValores = 0;
    LinkedList* listaDePaises;
    listaDePaises = ll_newLinkedList();
    char path[25];

    do
    {
        auxMenu = menu(&opcion);

        while(auxMenu)
        {
            auxMenu = menu(&opcion);
        }

        switch(opcion)
        {
        case 1:
            if(ll_isEmpty(listaDePaises))
            {
                if(utn_getCadena(path,25,"Ingrese le nombre del archivo sin la extension'.csv' \n","Error, nombre demasiado largo\n",4))
                {
                    strcat(path,".csv");

                    if(!controller_loadFromText(path,listaDePaises))
                    {
                        printf("Archivo iniciado con exito!\n");

                    }
                    else
                    {
                        printf("Se produjo un error al iniciar el archivo\n");
                    }
                }
            }
            else
            {
                printf("Usted ya ha abierto el archivo!\n");
            }

            break;
        case 2:
            if(!ll_isEmpty(listaDePaises))
            {
                 if(flagValores)
                {
                    if(controller_ListPaises(listaDePaises))
                    {
                        printf("Se produjo un error al mostrar los paises\n");
                    }
                }else
                {
                     printf("El archivo no tiene valores para mostrar, esta todo en 0\n");
                }
            }
            else
            {
                printf("No hay paises para mostrar\n");
            }
            break;
        case 3:
            if(!ll_isEmpty(listaDePaises))
            {
                if(!flagValores)
                {
                    if(!controller_AsignarEstadisticas(listaDePaises))
                    {

                        printf("Estadisticas asignadas con exito!\n");
                        flagValores = 1;
                    }
                    else
                    {
                        printf("Error al asignar valores\n");
                    }
                }
                else
                {
                    printf("Usted ya ha asignado los valores a la lista\n");
                }
            }
            else
            {
                 printf("No hay paises en la lista para asignarle valores\n");
            }
            break;

        case 4:
            if(!ll_isEmpty(listaDePaises))
            {
                if(flagValores)
                {
                    if(!controller_FiltrarPorExitoso(listaDePaises))
                    {
                        printf("Filtrado exitoso\n");
                    }
                    else
                    {
                        printf("Error al filtrar el archivo de exitosos\n");
                    }
                }
                else
                {
                    printf("El archivo no tiene valores para filtrar\n");
                }
            }
            else
            {
                printf("No hay paises en la lista\n");
            }
            break;
        case 5:
            if(!ll_isEmpty(listaDePaises))
            {
                if(flagValores)
                {
                    if(!controller_FiltrarEnElHorno(listaDePaises))
                    {
                        printf("Filtrado exitoso\n");
                    }
                    else
                    {
                        printf("Error al filtrar el archivo de en el horno\n");
                    }
                }
                else
                {
                    printf("El archivo no tiene valores para filtrar\n");
                }
            }
            else
            {
                printf("No hay paises para asignarles valores\n");
            }
            break;
        case 6:
            if(!ll_isEmpty(listaDePaises))
            {
                if(flagValores)
                {
                    if(!controller_OrdenarPorVac1(listaDePaises))
                    {
                        printf("Se realizo el ordenamiento de manera exitosa\n");
                    }
                    else
                    {
                        printf("Error al ordenar el listado\n");
                    }
                }
                else
                {
                    printf("El archivo no tiene valores para ordenar\n");
                }
            }
            else
            {
                printf("No hay paises para realizar el ordenamiento\n");
            }
            break;

        case 7:
            if(!ll_isEmpty(listaDePaises))
            {
                if(flagValores)
                {
                    if(!controller_MostrarMasCastigado(listaDePaises))
                    {
                        printf("Se ha encontrado el o los paises con la mayor cantidad de personas sin vacunar\n");
                    }
                    else
                    {
                        printf("Error al buscar al mas castigado por la pandemia\n");
                    }
                }
                else
                {
                    printf("El archivo no tiene valores para buscar\n");
                }
            }
            else
            {
                printf("No hay paises para realizar la busqueda\n");
            }
            break;

        };
        system("pause");
    }
    while(opcion !=8);

    ll_deleteLinkedList(listaDePaises);
    return 0;
}

