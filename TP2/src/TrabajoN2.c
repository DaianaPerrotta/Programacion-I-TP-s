#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "utn.h"
#include "menu.h"

#define TAM 1000

int main()
{
	int seguir = 0;
	int opcion;
	int flagOp1 = 0;
	char salir = 's';
	int id = 1;
	int opcInformar;
	int orden;
	int seguirInformar = 0;

	Employee list[TAM];
	initEmployees(list, TAM);

	do
	{
		system("cls");
		opcion = menu(flagOp1);
		switch (opcion)
		{
		case 1:
			addEmployees(list, TAM, id);
			flagOp1 = 1;
			break;
		case 2:
			modifyEmployeeById(list, TAM, id);
			break;
		case 3:
			removeEmployee(list, TAM, id);
			break;
		case 4:
			do
			{
				system("cls");
				opcInformar = menuInformar();
				switch (opcInformar)
				{
				case 1:
					printf("   ***Informe de empleados ***   \n");
					printf(
							"Como desea ordenarlos?\n1. Ascendente\2. Descendente\nOpcion: ");
					fflush(stdin);
					scanf("%d", &orden);
					if (sortEmployees(list, TAM, orden) == 0)
					{
						printf(
								" Id         Nombre        Apellido  Salario  Sector\n");
						printf(
								"**********************************************************\n");
						printEmployees(list, TAM);
						system("pause");
					}
					break;
				case 2:
					sumAverHighSalary(list, TAM);
					system("pause");
					break;
				case 3:
					seguirInformar = exitMenu(salir);
					break;
				}
			} while (seguirInformar == 0);
			break;
		case 5:
			seguir = exitMenu(salir);
			break;
		default:
			printf("Opcion invalida\n");
			break;
		}
		system("pause");
	} while (seguir == 0);
	return 0;
}
