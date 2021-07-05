#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

int menu(int*pOpcionMenu)
{
    int error = 0;
    int opcion;

    if(pOpcionMenu != NULL)
    {

        system("cls");
        do
        {
            printf("*** MENU DE OPCIONES PAISES VACUNAS ***\n");
            printf("1 Cargar archivo\n");
            printf("2 Imprimir listado\n");
            printf("3 Asignar Estadisticas\n");
            printf("4 Filtrar paises exitosos\n");
            printf("5 Filtrar paises en el horno\n");
            printf("6 Ordenar paises por cantidad de vacunados con 1 dosis de manera descendente\n");
            printf("7 Mostrar pais con mas personas sin vacunar\n");
            printf("8 Salir\n");

            utn_getNumeroInt(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",1,8,4);

            error = 0;
        }
        while(opcion<1 || opcion>8);
        *pOpcionMenu = opcion;
    }
    return error;
}
