#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief Carga los datos del archivo data.csv en modo texto
 *
 * \param  path ruta del archivo que tiene los datos
 * \param  pArrayDePaises puntero al archivo de lista de paises
 * \return 0 si salio ok -1 si salio mal
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayDePaises);


/** \brief Realiza la muestra del listado de las paises
 *
 * \param  pArrayDePaises puntero al array de paises
 * \
 * \return 0 si salio ok -1 si salio mal
 *
 */


int controller_ListPaises(LinkedList* pArrayDePaises);


/** \brief Realiza el guardado de los datos en modo texto con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (data.csv)
 *
 * \param  pArrayDePaises punteroa la lista de paises
 *\param  path ruta al archivo csv
 * \return 0 si salio ok -1 si hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayDePaises);

/** \brief Realiza la asignacion de estadisticas a la lista tomando como referencia el puntero a la lista

 *
 * \param  pArrayDePaises punteroa la lista de paises

 * \return 0 si salio ok -1 si hubo error
 *
 */

int controller_AsignarEstadisticas(LinkedList *pArrayDePaises);

/** \brief Realiza el filtrado de los paises exitosos segun el criterio y crea la lista
 * \param  pArrayDePaises punteroa la lista de paises
 * \return 0 si salio ok -1 si hubo error
 */

int controller_FiltrarPorExitoso(LinkedList* pArrayDePaises);

/** \brief Realiza el filtrado de los paises en el horno segun el criterio y crea la lista
 * \param  pArrayDePaises punteroa la lista de paises
 * \return 0 si salio ok -1 si hubo error
 */

int controller_FiltrarEnElHorno(LinkedList* pArrayDePaises);

/** \brief Realiza el ordenamiento de los paises por cantidad de vacunados con 1 dosis
 * \param  pArrayDePaises punteroa la lista de paises
 * \return 0 si salio ok -1 si hubo error
 */
int controller_OrdenarPorVac1(LinkedList* pArrayDePaises);

/** \brief Realiza la busqueda del pais con mayor cantidad de no vacunados
 * \param  pArrayDePaises punteroa la lista de paises
 * \return 0 si salio ok -1 si hubo error
 */
int controller_MostrarMasCastigado(LinkedList* pArrayDePaises);

#endif // CONTROLLER_H_INCLUDED
