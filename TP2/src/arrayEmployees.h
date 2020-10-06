#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;  //=1 está vacía  =0 está llena
} Employee;

/** \brief initEmployees    Para indicar que todas las posiciones del array estan vacias,
 *                          esta funcion pone la banera (isEmpty) en TRUE en todas las
 *                          posiciones del array
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \return int              Return (1) if Error [Invalid length or NULL pointer] - (0) if OK
 *
 */
int initEmployees(Employee *list, int len);

/** \brief findFree         Busca el primer espacio libre en el array de empleados
 *
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \return int              Return (-1) if Error [Invalid length or NULL pointer] - employee index position if OK
 *
 */
int findFree(Employee *list, int len);

/** \brief add Employees    Agrega en un array de empleados existentes los valores recibidos
 *                          como parametro en la primer posicion libre
 * \param list employee*    Pointer to array of employees
 * \param len int           Array length
 * \param id int            Id by system
 * \return int              Return (1) if Error [Invalid length or NULL pointer or without free space]
 *                          - (0) if OK
 */
int addEmployees(Employee *list, int len, int id);

/** \brief findEmployeeById Busca un empleado recibiendo como parametro de busqueda su Id
 *
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \param id int            Find by Id by user
 * \return int              Return employee index position or (-1) if [Invalid length or NULL pointer
 *                          or employee not found]
 */
int findEmployeeById(Employee *list, int len, int id);

/** \brief showEmployee     Muestra los datos de un empleado
 *
 * \param empleado
 * \return void
 *
 */
void showEmployee(Employee empleado);

/** \brief printEmployees   Muestra los datos de todos los empleados ingresados
 *
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \return int              Return (1) if Error [Invalid length or NULL pointer]
 *                          - (0) if OK
 */
int printEmployees(Employee *list, int len);

/** \brief modifyEmployeeById   Modifica los datos de un empleado recibiendo como
 *                              parametro su Id
 * \param list Employee*        Pointer to array of employees
 * \param len int               Array length
 * \param id int				Id by user
 * \return int                  Return (1) if Error [Invalid length or NULL pointer or
 *                              if can't find a employee] - (0) if OK
 */
int modifyEmployeeById(Employee *list, int len, int id);

/** \brief removeEmployee   Elimina de manera logica (isEmpty Flag en 1) un empleado
 *                          recibiendo como parametro su Id
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \param id int			Id by user
 * \return int              Return (1) if Error [Invalid length or NULL pointer or
 *                          if can't find a employee] - (0) if OK
 */
int removeEmployee(Employee *list, int len, int id);

/** \brief sortEmployees    Ordena el array de empleados por apellido y sector de manera
 *                          ascendente o descendente
 * \param list Employee*    Pointer to array of employees
 * \param len int           Array length
 * \param order int         [1] indicate UP - [2] indicate DOWN
 * \return int              Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 *
 */
int sortEmployees(Employee *list, int len, int orden);

#endif // ARRAYEMPLOYEES_H_INCLUDED
