#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "UTN.h"
/*1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/
int main()
{
    int opcion;
    int respuesta;
    int continuar = 0;
    int flagOp1 = 0;
    int flagOp2 = 0;
    int flagOp3 = 0;
    int num1;
    int num2;
    int rdoSuma;
    int rdoResta;
    int rdoMultiplicacion;
    int rdoFactorial1;
    int rdoFactorial2;
    float rdoDivision;

    do
    {
        system("cls");
        //respuesta = utn_getNumero(&opcion, "\n\n**Seleccione la opcion deseada**\n\n1. Ingresar 1er operando (A=x)\n2. Ingresar 2do operando (B=y)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\nOpcion: ", "No es una opcion valida\n\n", 1, 5, 10);
        respuesta = utn_getNumero(&opcion, menuCalculadora(num1, num2), "No es una opcion valida\n\n", 1, 5, 10);
        if(respuesta == 0)
        {
            switch(opcion)
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
                    if(flagOp1 != 0 && flagOp2 != 0)
                    {
                        printf("\nCalculando las operaciones\n");
                        rdoSuma = suma(num1,num2);
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
                    if(flagOp1 != 0 && flagOp2 != 0 && flagOp3 != 0)
                    {
                        printf("\n\nInforme de los resultados\n");
                        printf("El resultado de %d+%d es: %d\n", num1, num2, rdoSuma);
                        printf("El resultado de %d-%d es:%d\n", num1, num2, rdoResta);
                        if(num2 != 0)
                        {
                            printf("El resultado de %d/%d es:%f\n", num1, num2, rdoDivision);
                            system("pause");
                        }
                        else
                        {
                            printf("No es posible dividir por cero\n");
                        }
                        printf("El resultado de %d*%d es: %d\n", num1, num2, rdoMultiplicacion);
                        printf("El factorial de %d es: %d y el factorial de %d es: %d\n\n\n", num1, rdoFactorial1, num2, rdoFactorial2);
                        system("pause");
                    }
                    else
                    {
                        printf("\nPrimero debe ingresar los valores A y B, y calcular las operaciones\n\n");
                        system("pause");
                    }
                break;
                case 5:
                    printf("Salir\n\n\n");
                    continuar = 1;
                break;
            }
        }
    }while(continuar == 0);
}


