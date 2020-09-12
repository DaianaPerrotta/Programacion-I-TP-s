#include <stdio.h>
#include <stdlib.h>

char menuCalculadora(int a, int b)
{
    return printf("\n\n**Seleccione la opcion deseada**\n\n1. Ingresar 1er operando (A= %d)\n2. Ingresar 2do operando (B= %d)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\nOpcion: ", a, b);
}

int utn_getNumero(int* pResultado, char mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int buffer;

    if(pResultado != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
       do
       {
            printf("%c", mensaje);
            scanf("%d", &buffer);
            fflush(stdin);
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
       }while (reintentos >= 0);
    }
    return retorno;
}

int suma(int sumando1, int sumando2)
{
    int rdoSuma;

    rdoSuma = sumando1 + sumando2;

    return rdoSuma;
}

int resta(int minuendo, int sustraendo)
{
    int rdoResta;

    rdoResta = minuendo - sustraendo;

    return rdoResta;
}

float division(int dividendo, int divisor)
{
    float rdoDivision;

    if(divisor != 0)
    {
        rdoDivision = (float) dividendo / divisor;
    }
    else
    {
        printf("No es posible dividir por cero");
    }

    return rdoDivision;
}

int multiplicacion(int factor1, int factor2)
{
    int rdoMultiplicacion;

    rdoMultiplicacion = factor1 * factor2;

    return rdoMultiplicacion;
}

int factorial(int numero)
{
    int rdoFactorial;

    if(numero==1)
    {
           return 1;
    }
    else
    {
        rdoFactorial = numero * factorial(numero - 1);

        return (rdoFactorial);
    }
}
