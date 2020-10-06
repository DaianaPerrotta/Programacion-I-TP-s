#include <stdio.h>
#include <stdlib.h>

#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief getString        Se obtiene una cadena de caracteres
 *
 * \param name char*        Pointer to name
 * \param len int           Array length
 * \param mensaje char*     Pointer to message by user
 * \return void
 *
 */
void getString(char *name, int len, char *mensaje);

/** \brief getValidString   Valida que en la cadena sean unicamente caracteres
 *                          alfabeticos
 * \param getString char*   Pointer to string
 * \return int              Return (0) if get numbers or symbols - (1) if OK
 *
 */
int isValidStrig(char *getString);

/** \brief getValidString   Se obtiene una cadena de caracteres en los que se
 *                          valido que sean unicamente caracteres alfabeticos
 * \param name char*        Pointer to name
 * \param len int           Array length
 * \param mensaje char*     Pointer to message by user
 * \return void
 *
 */
void getValidString(char *name, int len, char *mensaje);

/** \brief isValidNumber    Valida que la cadena sean unicamente numeros
 *
 * \param number char*      Pointer to number
 * \return int              Return (0) if OK - (1) if not
 *
 */
int isValidNumber(char *number);

/** \brief getFloatNumber   Obtengo un numero flotante
 *
 * \param mensaje char*     Pointer to message by user
 * \return float            Get a float number
 *
 */
float getFloatNumber(char *mensaje);

/** \brief isValidInt       Validar un numero entero
 *
 * \param number char*      Pointer to message by user
 * \return int              (0) if OK - (1) if not
 *
 */
int isValidInt(int *number);

/** \brief getInt           Obtengo un numero entero validado
 *
 * \param mensaje char*     Pointer to message by user
 * \return int              Get a validate integer
 *
 */
int getInt(char *mensaje);

#endif // UTN_H_INCLUDED
