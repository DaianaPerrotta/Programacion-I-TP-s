#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief menu     Menu principal del programa, que valida que la opciones 2,
 *                  3 y 4 no puedan ser seleccionadas antes de la opcion 1
 * \param flag int  Bandera para asegurar que primero se da de alta un empleado
 * \return int      Devuelve la opcion elegida por el usuario cuando cumpla
 *                  las condiciones
 */
int menu(int flag);

/** \brief menuInformar Submenu opcion 4.Informar
 *
 * \return int          Devuelve la opcion elegida por el usuario
 *
 */
int menuInformar();

/** \brief exitMenu     Salida con confirmacion de los menus
 *
 * \param opcion char   Opcion s/n para confirmar o no la salida
 * \return int          (1) Salir - (0) Cancelar
 *
 */
int exitMenu(char opcion);

/** \brief sumAverHighSalary    Se obtienen carteles informando la suma y promedio de
 *                              los salarios, y cuantos empleados lo superan
 * \param list Employee*        Puntero al array Employee
 * \param len int               Tamaño del array
 * \return void
 *
 */
void sumAverHighSalary(Employee *list, int len);

#endif // MENU_H_INCLUDED
