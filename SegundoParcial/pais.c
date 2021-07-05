#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "utn.h"


ePais*  pais_new()
{

    ePais* nuevoPais;

    nuevoPais = (ePais*) malloc(sizeof(ePais));

    return nuevoPais;
}



ePais* pais_newParametrosChar(char* idStr,char* nombre,char* vac1,char* vac2,char* sinVac)
{
    ePais* nuevoPais;
    nuevoPais = NULL;
    nuevoPais = pais_new();

    if(nuevoPais != NULL)
    {

        if(pais_setId(nuevoPais,atoi(idStr))||
                pais_setNombre(nuevoPais,nombre) ||
                pais_SetVac1(nuevoPais,atoi(vac1)) ||
                pais_SetVac2(nuevoPais,atoi(vac2)) ||
                pais_SetSinVac(nuevoPais,atoi(sinVac)))
        {
            pais_delete(nuevoPais);
        }

    }
    return nuevoPais;

}




void pais_delete(ePais* this)
{
    free(this);
}


int printCountry(ePais* pais)
{
    int error = 0;
    char nombre[50];
    int id;
    int vac1;
    int vac2;
    int sinVac;

    if(pais != NULL )
    {
        if(!pais_getId(pais,&id) &&
                !pais_getNombre(pais,nombre) && !pais_GetVac1(pais,&vac1) &&
                !pais_GetVac2(pais,&vac2) && !pais_GetSinVac(pais,&sinVac))
        {

            printf("%d           %15s               %5d                  %5d                %5d\n",id,nombre,vac1,vac2,sinVac);
            error = 1;
        }
    }

    return error;
}

int pais_setId(ePais* this, int id)
{
    int error = 1;

    if(this != NULL && id>0)
    {
        this->id = id;
        error = 0;
    }
    return error;
}

int pais_getId(ePais* this,int* id)
{
    int error = 1;

    if(this != NULL && id !=NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int pais_setNombre(ePais* this, char* nombre)
{
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }
    return error;
}

int pais_getNombre(ePais* this, char* nombre)
{
    int error = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        error = 0;
    }
    return error;
}


int pais_SetVac1(ePais* this, int vac1dosis)
{
    int error = 1;

    if(this != NULL && vac1dosis>=0)
    {
        this->vac1dosis = vac1dosis;
        error = 0;
    }
    return error;
}

int pais_GetVac1(ePais* this,int* vac1dosis)
{
    int error = 1;

    if(this != NULL && vac1dosis !=NULL)
    {
        *vac1dosis = this->vac1dosis;
        error = 0;
    }
    return error;
}

int pais_SetVac2(ePais* this, int vac2dosis)
{
    int error = 1;

    if(this != NULL && vac2dosis>=0)
    {
        this->vac2dosis = vac2dosis;
        error = 0;
    }
    return error;
}


int pais_GetVac2(ePais* this, int* vac2dosis)
{
    int error = 1;

    if(this != NULL && vac2dosis !=NULL)
    {
        *vac2dosis = this->vac2dosis;
        error = 0;
    }
    return error;
}



int pais_SetSinVac(ePais* this, int sinVacunar)
{
    int error = 1;

    if(this != NULL && sinVacunar>=0)
    {
        this->sinVacunar = sinVacunar;
        error = 0;
    }
    return error;
}


int pais_GetSinVac(ePais* this, int* sinVacunar)
{
    int error = 1;

    if(this != NULL && sinVacunar !=NULL)
    {
        *sinVacunar = this->sinVacunar;
        error = 0;
    }
    return error;
}


void* asignarValores(void* pais)
{
    ePais* paisA = (ePais*) pais;
    int cantVac1;
    int cantVac2;
    int cantSinVac;
    int aux;



    if(paisA!=NULL)
    {
        cantVac1=rand()%(60-1)+1;
        cantVac2=rand()%(40-1)+1;

        aux = 100-(cantVac1 + cantVac2);

        cantSinVac = aux;

        pais_SetVac1(paisA,cantVac1);
        pais_SetVac2(paisA,cantVac2);
        pais_SetSinVac(paisA,cantSinVac);


    }

    return paisA;
}

int pais_filtrarExitosos(void* pais)
{
    int retorno = 0;

    ePais* paisA = (ePais*) pais;
    int vac2;

    if(paisA != NULL)
    {
        pais_GetVac2(pais,&vac2);

        if(paisA->vac2dosis > 30)
        {
            retorno = 1;
        }

    }
    return retorno;
}

int pais_filtrarEnElHorno(void* pais)
{
    int retorno = 0;

    ePais* paisA = (ePais*) pais;
    int vacunados;
    int sinVacunar;

    if(paisA !=NULL)
    {
        pais_GetSinVac(paisA,&sinVacunar);
        pais_GetVac1(paisA,&vacunados);

        if(vacunados < sinVacunar)
        {
            retorno = 1;
        }
    }

    return retorno;
}


int pais_compararPorVac1Dosis(void* pais1,void* pais2)
{
    int retorno = 0;
    ePais* paisA  = NULL;
    ePais* paisB = NULL;

    paisA = (ePais*) pais1;
    paisB = (ePais*) pais2;


    if(paisA->vac1dosis > paisB->vac1dosis)
    {
        retorno = 1;
    }else
    {
        if(paisA->vac1dosis < paisB->vac1dosis)
        {
            retorno = -1;
        }
    }

    return retorno;
}

