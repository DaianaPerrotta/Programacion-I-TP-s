#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "utn.h"

int initEmployees(Employee *list, int len)
{
	int error = 1;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = 0;
		}
		error = 0;
	}
	return error;
}

int findFree(Employee *list, int len)
{
	int indice = -1;

	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int addEmployees(Employee *list, int len, int id)
{
	int error = 1;
	int indice;

	Employee newEmployee;

	system("cls");

	if (list != NULL && len > 0 && id > 0)
	{
		printf("   ***Alta de empleado***   \n\n");

		indice = findFree(list, len);

		if (indice == -1)
		{
			printf("La base de datos se encuentra completa\n");
		}
		else
		{
			newEmployee.id = id + indice;
			newEmployee.isEmpty = 1;

			getValidString(newEmployee.name, 51, "Ingrese el nombre: ");

			getValidString(newEmployee.lastName, 51, "Ingrese el apellido: ");
			fflush(stdin);

			newEmployee.salary = getFloatNumber("Ingrese el salario: ");

			newEmployee.sector = getInt("Ingrese el sector: ");

			list[indice] = newEmployee;
			error = 0;

			printf("   Id       Nombre        Apellido     Salario   Sector\n");
			printf(
					"*********************************************************\n");
			showEmployee(list[indice]);
			system("pause");
		}
	}
	if (error == 0)
	{
		printf("Empleado inicializado con exito\n");
	}
	else
	{
		printf("Error al inicializar empleado\n");
	}
	return error;
}

int findEmployeeById(Employee *list, int len, int id)
{
	int indice = -1;

	printf("Ingrese el Id: ");
	scanf("%d", &id);
	for (int i = 0; i < len; i++)
	{
		if (list != NULL && list[i].id == id && list[i].isEmpty == 1)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

void showEmployee(Employee empleado)
{
	printf("%4d %15s  %15s  %8.2f    %2d\n", empleado.id, empleado.name,
			empleado.lastName, empleado.salary, empleado.sector);
}

int printEmployees(Employee *list, int len)
{
	int error = 1;
	int flag = 0;

	if (list != NULL && len > 0)
	{
		system("cls");
		printf("   Id       Nombre        Apellido     Salario   Sector\n");
		printf("*********************************************************\n");

		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 1)
			{
				showEmployee(list[i]);
				flag = 1;
				error = 0;
			}
		}
		if (flag == 0)
		{
			printf("Aún no se han ingresado empleados\n\n");
		}
		printf("\n\n");
	}
	return error;
}

int modifyEmployeeById(Employee *list, int len, int id)
{
	int error = 1;
	int indice;
	int opcion;
	char confirma;

	Employee oldEmployee;

	if (list != NULL && len > 0)
	{
		system("cls");
		printf("    ***Modificar dato de empleado***   \n\n");

		indice = findEmployeeById(list, len, id);

		if (indice == -1)
		{
			printf("No existe el Id ingresado\n");
		}
		else
		{
			printf("   Id       Nombre        Apellido     Salario   Sector\n");
			printf(
					"*********************************************************\n");
			showEmployee(list[indice]);
			printf("\n\n");
			oldEmployee = list[indice];
			printf(
					"Que dato desea modificar?\n\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\nOpcion: ");
			fflush(stdin);
			scanf("%d", &opcion);

			switch (opcion)
			{
			case 1:
				getValidString(gets(oldEmployee.name), 51,
						"\nIngrese el nuevo nombre: ");
				break;
			case 2:
				getValidString(gets(oldEmployee.lastName), 51,
						"\nIngrese el nuevo apellido: ");
				break;
			case 3:
				oldEmployee.salary = getFloatNumber(
						"\nIngrese el nuevo salario: ");
				break;
			case 4:
				oldEmployee.sector = getInt("Ingrese el sector: ");
				break;
			default:
				printf(
						"La opcion es incorrecta. \nQue dato desea modificar?\n\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\nOpcion: ");
				break;
			}

			printf("Confirma los cambios? s/n\n");
			scanf("%c", &confirma);
			confirma = tolower(confirma);

			if (confirma == 's')
			{
				oldEmployee.isEmpty = 1;
				list[indice] = oldEmployee;
				printf("Cambios realizados con exito\n");
				printf(
						"   Id       Nombre        Apellido     Salario   Sector\n");
				printf(
						"*********************************************************\n");
				showEmployee(list[indice]);
				error = 0;
			}
			else
			{
				if (confirma == 'n')
				{
					printf("Los cambios han sido cancelados\n");
				}
				else
				{
					printf("Opcion incorrecta. Confirma los cambios? s/n\n");
				}
			}
		}
	}
	return error;
}

int removeEmployee(Employee *list, int len, int id)
{
	int error = 1;
	int indice;
	char confirma;

	if (list != NULL && len > 0)
	{
		system("cls");
		printf("    ***Baja de empleado***   \n\n");

		indice = findEmployeeById(list, len, id);

		if (indice == -1)
		{
			printf("No existe el Id ingresado\n");
		}
		else
		{
			printf("   Id       Nombre        Apellido     Salario   Sector\n");
			printf(
					"*********************************************************\n");
			showEmployee(list[indice]);
			printf("\n\n");
			printf("Confirma baja? s/n\n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);

			if (confirma == 's')
			{
				list[indice].isEmpty = -1; //para diferenciarlo del =1, que es espacio libre
				printf("Baja realizada con exito\n");
				error = 0;
			}
			else
			{
				if (confirma == 'n')
				{
					printf("La baja ha sido cancelada\n");
				}
				else
				{
					printf("La opcion incorrecta. Confirma baja? s/n\n");
				}
			}
		}
	}
	return error;
}

int sortEmployees(Employee *list, int len, int orden)
{
	int error = 1;

	Employee auxEmployee;

	if (list != NULL && len > 0)
	{
		if (orden == 1)
		{
			for (int i = 0; i < len - 1; i++)
			{
				for (int j = i + 1; j < len; j++)
				{
					if ((strcmp(list[i].lastName, list[j].lastName)) > 0)
					{
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
					}
					else
					{
						if ((strcmp(list[i].lastName, list[j].lastName)) == 0)
						{
							if (list[i].sector > list[j].sector)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
						}
					}
				}
			}
			error = 0;
		}
		else
		{
			if (orden == 2)
			{
				for (int i = 0; i < len - 1; i++)
				{
					for (int j = i + 1; j < len; j++)
					{
						if ((strcmp(list[i].lastName, list[j].lastName)) < 0)
						{
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}
						else
						{
							if ((strcmp(list[i].lastName, list[j].lastName))
									== 0)
							{
								if (list[i].sector < list[j].sector)
								{
									auxEmployee = list[i];
									list[i] = list[j];
									list[j] = auxEmployee;
								}
							}
						}
					}
				}
				error = 0;
			}
			else
			{
				printf("Dato erroneo. Reingrese orden a presentar\n");
			}
		}
	}
	return error;
}

