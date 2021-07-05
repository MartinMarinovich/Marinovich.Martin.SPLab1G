#include"LinkedList.h"

#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct{

int id;
char nombre[51];
int vac1dosis;
int vac2dosis;
int sinVacunar;

}ePais;


#endif // PAIS_H_INCLUDED
/*
 * \brief Constructor del espacio de memoria para la pais
 *
 * \return devuelve un puntero al espacio de memoria que encontro y si no devuelve NULL
 */

ePais* pais_new();


/** \brief Constructor que inicializa las variables que va recibe por parametro
 * de tipo char
 *
 * \param  id a asignar a la pais
 * \param   nombre a asignar a la pais
 * \param   vac1 a la pais
 * \param   aniodefabricacion a asignar a la pais
 * \param   vac2  de la pais
 * \return sinVac a la pais generado
 */

ePais* pais_newParametrosChar(char* idStr,char* nombre,char* vac1,char* vac2,char* sinVac);

/** \brief libera el espacio de memoria donde se encuentra la  pais que le pasamos
 * \param puntero a la pais que deseamos borrar
 */

void pais_delete(ePais* oneEmployee);
/*
 * \brief copia el valor introducido del id y lo copia al array
 * \param puntero array en el guardamos los ids
 * \param número de id introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
/*
 * \brief recibre el nombre y lo copia al array de nombres
 * \param puntero array en el guardamos los nombres
 * \param nombre introducido

 * \return 0 si lo devolvió sin problemas, -1 si hubo un error.
 */
int pais_setNombre(ePais* this, char* nombre);
int pais_getNombre(ePais* this, char* nombre);

int pais_SetVac1(ePais* this, int cantVac1);
int pais_GetVac1(ePais* this,int* cantVac1);

int pais_SetVac2(ePais* this, int cantVac2);
int pais_GetVac2(ePais* this, int* cantVac2);


int pais_SetSinVac(ePais* this, int cantSinVac);
int pais_GetSinVac(ePais* this, int* cantSinVac);

/** \brief Muestra la pais pasada por el puntero a donde se ubica
 *
 * \param pais puntero a la direccion del empleado a mostrar
 * \param
 * \return  0 si lo devolvió sin problemas, -1 si hubo un error.
 *
 */

int printCountry(ePais* pais);




/** \brief Realiza el filtrado de los elementos de la lista a partir del parametro ingesado por el cual va a comparar
 * \param puntero al elemento de la lista que casteamos dentro de la funcion
 * \return devuelve 1 si coincide con el criterio y 0 si no lo hace
 */

int pais_filtrarExitosos(void* pais);

/** \brief Realiza el filtrado de los elementos de la lista a partir del parametro ingesado por el cual va a comparar
 * \param puntero al elemento de la lista que casteamos dentro de la funcion
 * \return devuelve 1 si coincide con el criterio y 0 si no lo hace
 */

int pais_filtrarEnElHorno(void* pais);

/** \brief Realiza la asignacion de valores al elemento tomando como referencia el puntero que le pasamos
 * \param puntero al elemento de la lista
 * \return devuelve el pais con los valores asignados
 */

void* asignarValores(void* pais);

/** \brief Realiza la comparacion de los elementos tomando como criterio la cantidad de vacunados con 1 dosis
 * \param puntero al elemento de la lista
 * \param puntero al elemento de la lista
 * \return devuelve el pais con los valores asignados
 */
int pais_compararPorVac1Dosis(void* pais1,void* pais2);
