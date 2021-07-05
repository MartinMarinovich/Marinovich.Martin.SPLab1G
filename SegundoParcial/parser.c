#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_CountrysFromText(FILE* pFile , LinkedList* pArrayDePaises)
{
    int error = -1;
    char bufferDatos[5][128];
    int cantidadElementos;

    ePais* nuevoPais;
    nuevoPais = NULL;

    if(pFile != NULL && pArrayDePaises != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

        do{

            cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

            if(cantidadElementos == 5)
            {
                nuevoPais = pais_newParametrosChar(bufferDatos[0],bufferDatos[1],bufferDatos[2],bufferDatos[3],bufferDatos[4]);

                if(nuevoPais != NULL)
                {
                    ll_add(pArrayDePaises,nuevoPais);

                    error = 0;
                }
            }else
            {
                break;
            }

        }while(!feof(pFile));

        fclose(pFile);
    }

    return error;
}
