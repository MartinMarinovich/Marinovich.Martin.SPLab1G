#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"utn.h"
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"
#include "controller.h"



int controller_loadFromText(char* path,LinkedList* pArrayDePaises)
{
    int retorno = -1;
    FILE* f;

    if(path != NULL && pArrayDePaises != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL && !parser_CountrysFromText(f,pArrayDePaises))
        {
            printf("\nLista generada con exito!\n\n");
            retorno = 0;

        }
        else
        {
            printf("\nError al cargar el archivo\n");
        }
    }

    fclose(f);

    return retorno;
}


int controller_ListPaises(LinkedList* pArrayDePaises)
{
    int error = 1;
    int flag = 0;

    if(pArrayDePaises != NULL)
    {
        error = 0;
        printf("ID                NOMBRE                   VAC1                     VAC2             SIN VAC\n");
        printf("-------------------------------------------------------------------------------------------------\n\n");

        for(int i = 0; i<ll_len(pArrayDePaises); i++)
        {
            if(((ePais*)ll_get(pArrayDePaises,i))!= NULL)
            {
                printCountry((ePais*)ll_get(pArrayDePaises,i));
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("\nNo hay paises en la lista\n");
        }

        error = 0;
    }
    else
    {
        printf("No hay una lista disponible para mostrar\n");
    }


    return error;
}



int controller_AsignarEstadisticas(LinkedList *pArrayDePaises)
{
    int retorno = 1;
    LinkedList* auxList = NULL;

    if(pArrayDePaises != NULL)
    {

        auxList = ll_map(pArrayDePaises,asignarValores);

        if(auxList != NULL)
        {
            pArrayDePaises = auxList;
            retorno = 0;
        }

        ll_deleteLinkedList(auxList);
    }


    return retorno;

}


/** \brief Guarda los datos de las paiss en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* path, LinkedList* pArrayDePaises)
{
    int error = -1;
    int id;
    char nombre[51];
    int recuperados;
    int infectados;
    int muertos;

    ePais* pais;
    pais = NULL;

    FILE* f;


    if(pArrayDePaises != NULL && path != NULL)
    {
        f = fopen(path,"w");

        if(f != NULL)
        {
            int tamanio = ll_len(pArrayDePaises);
            fprintf(f,"id,nombre,vac1dosis,vac2dosis,sinVacunar\n");

            for(int i = 0; i<tamanio; i++)
            {
                pais = ll_get(pArrayDePaises,i);

                if(!pais_getId(pais,&id) && !pais_getNombre(pais,nombre)&&
                        !pais_GetVac1(pais,&recuperados)&&
                        !pais_GetVac2(pais,&infectados)&&
                        !pais_GetSinVac(pais,&muertos))
                {

                    fprintf(f,"%d,%s,%d,%d,%d\n",id,nombre,recuperados,infectados,muertos);
                    error = 0;
                }
            }
            fclose(f);
        }
    }
    return error;
}

int controller_FiltrarPorExitoso(LinkedList* pArrayDePaises)
{
    int retorno = 1;
    LinkedList* auxLista = NULL;

    if(pArrayDePaises != NULL)
    {

        auxLista = ll_filter(pArrayDePaises,(pais_filtrarExitosos));

        if(auxLista != NULL)
        {
            if(!controller_saveAsText("paisesExitosos.csv",auxLista))
            {
                printf("Se genero el archivo con los paises exitosos!\n");
                retorno = 0;
            }
        }

    }

    ll_deleteLinkedList(auxLista);

    return retorno;
}

int controller_FiltrarEnElHorno(LinkedList* pArrayDePaises)
{
    int retorno = 1;
    LinkedList* auxLista = NULL;

    if(pArrayDePaises != NULL)
    {
        auxLista = ll_filter(pArrayDePaises,(pais_filtrarEnElHorno));

        if(auxLista != NULL)
        {
            if(!controller_saveAsText("paisesAlHorno.csv",auxLista))
            {
                printf("Se genero el archivo con los paises en el horno!\n");
                retorno = 0;
            }
        }

    }

    ll_deleteLinkedList(auxLista);

    return retorno;
}

int controller_OrdenarPorVac1(LinkedList* pArrayDePaises)
{
    int retorno = 1;

    if(pArrayDePaises != NULL)
    {
        if(!ll_sort(pArrayDePaises,pais_compararPorVac1Dosis,0))
        {
            controller_ListPaises(pArrayDePaises);
            retorno = 0;
        }

    }

    return retorno;
}

int controller_MostrarMasCastigado(LinkedList* pArrayDePaises)
{
    int retorno = 1;
    int tamanio;
    int mayorSinVac;
    int cantSinVac;
    char paisMasSinVacunar[51];

    ePais* auxPais = NULL;

    if(pArrayDePaises != NULL)
    {
        tamanio = ll_len(pArrayDePaises);

        for(int i = 0; i<tamanio; i++)
        {
            auxPais = ll_get(pArrayDePaises,i);

            if(auxPais !=NULL )
            {
                if(!pais_GetSinVac(auxPais,&cantSinVac))
                {
                    if(i == 0 || cantSinVac >mayorSinVac)
                    {
                        mayorSinVac = cantSinVac;
                        retorno = 0;
                    }
                }

            }

        }

        for(int i = 0; i<tamanio; i++)
        {
            auxPais = ll_get(pArrayDePaises,i);

            if(auxPais !=NULL )
            {
                if(!pais_GetSinVac(auxPais,&cantSinVac))
                {
                    if(cantSinVac == mayorSinVac)
                    {
                        pais_getNombre(auxPais,paisMasSinVacunar);
                        printf("El o los paises con menos personas vacunadas: Nombre:%10s  Sin Vacunar:%5d\n",paisMasSinVacunar,cantSinVac);

                    }
                }

            }

        }
    }

    return retorno;
}

