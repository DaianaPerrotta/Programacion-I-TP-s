#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "UTN.h"

int main()
{
	setbuf(stdout, NULL);

	int opcion;
	int respuesta;
	int continuar = 0;
	int flagOp1 = 0;
	int flagOp2 = 0;
	int flagOp3 = 0;
	int num1 = 0;
	int num2 = 0;
	int rdoSuma;
	int rdoResta;
	int rdoMultiplicacion;
	int rdoFactorial1;
	int rdoFactorial2;
	float rdoDivision;

	do
	{
		system("cls");
		respuesta = utn_getNumero(&opcion, menuCalculadora(num1, num2),
				"No es una opcion valida\n\n", 1, 5, 10);
		if (respuesta == 0)
		{
			switch (opcion)
			{
			case 1:
				printf("\nIngresar 1er operando A = ");
				scanf("%d", &num1);
				flagOp1++;
				break;
			case 2:
				printf("\nIngresar 2do operando B = ");
				scanf("%d", &num2);
				flagOp2++;
				break;
			case 3:
				if (flagOp1 != 0 && flagOp2 != 0)
				{
					printf("\nCalculando las operaciones\n");
					rdoSuma = suma(num1, num2);
					rdoResta = resta(num1, num2);
					rdoDivision = division(num1, num2);
					rdoMultiplicacion = multiplicacion(num1, num2);
					rdoFactorial1 = factorial(num1);
					rdoFactorial2 = factorial(num2);
					printf("...\nFinalizo el calculo\n\n");
					flagOp3++;
					system("pause");
				}
				else
				{
					printf("\nPrimero debe ingresar los valores A y B\n\n");
					system("pause");
				}
				break;
			case 4:
				if (flagOp1 != 0 && flagOp2 != 0 && flagOp3 != 0)
				{
					printf("\n\nInforme de los resultados\n");
					printf("El resultado de %d+%d es: %d\n", num1, num2,
							rdoSuma);
					printf("El resultado de %d-%d es: %d\n", num1, num2,
							rdoResta);
					if (num2 != 0)
					{
						printf("El resultado de %d/%d es: %.2f\n", num1, num2,
								rdoDivision);
					}
					else
					{
						printf("No es posible dividir por cero\n");
					}
					printf("El resultado de %d*%d es: %d\n", num1, num2,
							rdoMultiplicacion);
					if (rdoFactorial1 == -1 && rdoFactorial2 == -1)
					{
						printf(
								"No es posible calcular el factorial de %d y de %d\n\n\n",
								num1, num2);
					}
					else
					{
						if (rdoFactorial2 == -1)
						{
							printf(
									"El factorial de %d es: %d y no es posible calcular el factorial de %d\n\n\n",
									num1, rdoFactorial1, num2);
						}
						else
						{
							if (rdoFactorial1 == -1)
							{
								printf(
										"No es posible calcular el factorial de %d y el factorial de %d es: %d\n\n\n",
										num1, num2, rdoFactorial2);
							}
							else
							{
								printf(
										"El factorial de %d es: %d y el factorial de %d es: %d\n\n\n",
										num1, rdoFactorial1, num2,
										rdoFactorial2);
							}
						}
					}
					system("pause");
				}
				else
				{
					printf(
							"\nPrimero debe ingresar los valores A y B, y calcular las operaciones\n\n");
					system("pause");
				}
				break;
			case 5:
				printf("Salir\n\n\n");
				continuar = 1;
				break;
			}
		}
	} while (continuar == 0);
}

