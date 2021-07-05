#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief Transforma los datos del archivo de paises data.csv modo texto
 * \param pFile ruta al archiv data.csv
 * \param pArrayPai puntero al array de paises donde depositamos los dat
 * \return devuelve 0 si salio ok -1 si salio mal
 */

int parser_CountrysFromText(FILE* pFile , LinkedList* pArrayDePaises);

#endif // PARSER_H_INCLUDED
