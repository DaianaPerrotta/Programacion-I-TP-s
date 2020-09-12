#include <stdio.h>
#include <stdlib.h>

#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED


/** \brief menuCalculadora      menu para la calculadora que permita mostrar valores A y B cargados
 *
 * \param a int                 valor entero A cargado por el usuario
 * \param b int                 valor entero B cargado por el usuario
 * \return char                 el mensaje del menu
 *
 */
char menuCalculadora(int a, int b);


/** \brief utn_getNumero        validar valor entero de opcion del menu
 *
 * \param pResultado char       puntero de los resultados
 * \param mensaje char          mensaje con las condiciones
 * \param mensajeError char     mensaje de error al no cumplir las condiciones
 * \param minimo char           valor minimo
 * \param maximo char           valor maximo
 * \param reintentos int        cantidad de reintentos
 * \return int                  entrega resultado entero que cumpla las condiciones
 *
 */

int utn_getNumero(int* pResultado, char mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/** \brief suma             permite sumar 2 valores enteros
 *
 * \param sumando1 int      primer numero entero a sumar
 * \param sumando2 int      segundo numero entero a sumar
 * \return int              resultado de la suma de los 2 enteros
 *
 */
int suma(int sumando1, int sumando2);


/** \brief resta            permite restar 2 valores enteros
 *
 * \param minuendo int      numero enter al que se le va a restar otro
 * \param sustraendo int    numero entero que se resta
 * \return int              resultad de la resta de 2 numeros enteros
 *
 */
int resta(int minuendo, int sustraendo);

/** \brief division         permite dividir 2 valores enteros
 *
 * \param dividendo int     numero entero que va a ser dividido
 * \param divisor int       numero entero que divide
 * \return float            numero flotante resultado de la division de 2 numeros enteros
 *
 */
float division(int dividendo, int divisor);

/** \brief multiplicacion   permite multiplicar 2 valores enteros
 *
 * \param factor1 int       primer numero entero a multiplicar
 * \param factor2 int       segundo numero entero a multiplicar
 * \return int              numero entero resultado de la mutiplicacion de 2 numeros enteros
 *
 */
int multiplicacion(int factor1, int factor2);

/** \brief factorial        permite obtener el factorial de un numero entero
 *
 * \param numero int        numero entero a obtener el factorial
 * \return int              numero entero resultado del factorial de un numero entero
 *
 */
int factorial(int numero);
