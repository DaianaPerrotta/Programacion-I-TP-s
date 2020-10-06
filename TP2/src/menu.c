#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"
#include "arrayEmployees.h"

int menu(int flag)
{
	int opcion;

	system("cls");
	printf("*** Base de Datos Empleados ***\n\n");
	printf("1. Alta\n");
	printf("2. Modificacion\n");
	printf("3. Baja\n");
	printf("4. Informes\n");
	printf("5. Salir\n\n");
	printf("Ingrese opcion: ");

	scanf("%d", &opcion);
	fflush(stdin);

	if (flag == 0)
	{
		switch (opcion)
		{
		case 1:
		case 5:
			return opcion;
			break;
		case 2:
		case 3:
		case 4:
			printf("\nDeben darse de alta empleados\n\n");
			system("pause");
			system("cls");
			return menu(flag);
			break;
		default:
			printf("\nOpcion incorrecta. Reingrese opcion: ");
			system("pause");
			system("cls");
			return menu(flag);
			break;
		}
	}
	else
	{
		return opcion;
	}
}

int menuInformar()
{
	int opcion;

	system("cls");
	printf("   *** Informe de Datos Empleados   ***\n\n");
	printf("1. Listado de empleados ordenados alfabeticamente y por sector\n");
	printf(
			"2. Total y promedio de salarios. Cantidad de empleados que superan el salario promedio\n");
	printf("3. Cancelar\n\n");
	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}

int exitMenu(char opcion)
{
	int salida;

	printf("Salir del menu? s/n\n");
	fflush(stdin);
	scanf("%c", &opcion);
	opcion = tolower(opcion);
	if (opcion == 's')
	{
		salida = 1;
	}
	else
	{
		if (opcion == 'n')
		{
			salida = 0;
		}
		else
		{
			printf("Opcion incorrecta. Salir del menu? s/n\n");
		}
	}
	return salida;
}

void sumAverHighSalary(Employee *list, int len)
{

	int cont = 0;
	float sum = 0;
	float average;
	int high = 0;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1)
		{
			sum = sum + list[i].salary;
			cont++;
		}
	}
	average = sum / cont;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 1)
		{
			if (list[i].salary > average)
			{
				high++;
			}
		}
	}
	printf("El total de los salarios es %.2f\n", sum);
	printf("El promedio de los salarios es %.2f\n", average);
	printf("%d empleados superan el salario promedio\n", high);
}
