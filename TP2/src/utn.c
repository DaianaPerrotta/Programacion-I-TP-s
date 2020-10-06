#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void getString(char *name, int len, char *mensaje)
{
	char buffer[1000];
	int maxCharVerificar = len;

	printf("%s", mensaje);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > maxCharVerificar || strlen(buffer) < 1) //strlen devuelve la longitud de una cadena de texto
	{
		printf("\nError. %d caracteres maximo. %s: ", maxCharVerificar - 1,
				mensaje);
		fflush(stdin);
		gets(buffer);
	}
	strlwr(buffer);
	buffer[0] = toupper(buffer[0]);
	strcpy(name, buffer);
}

int isValidStrig(char *getString)
{
	int i = 0;
	int retorno = 0;
	int j;

	j = strlen(getString);

	while (i < j && retorno == 0)
	{
		if (isalpha(getString[i]) != 0)
		{
			i++;
		}
		else
		{
			printf("\nError. Solo caracteres alfabeticos\n");
			retorno = 1;
		}
	}
	return retorno;
}

void getValidString(char *name, int len, char *mensaje)
{
	int validar = 0;
	do
	{
		getString(name, len, mensaje);
		validar = isValidStrig(name);

	} while (validar != 0);
}

int isValidNumber(char *number)
{
	int i = 0;
	int retorno = 0;
	int j;

	j = strlen(number);

	while (i < j && retorno == 0)
	{
		if (isdigit(number[i]) != 0 || number[i] == '.' || number[i] == ','
				|| number[i] == '-')
		{
			i++;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

float getFloatNumber(char *mensaje)
{
	float valorFlotante;
	float buffer[30];

	do
	{
		printf("%s: ", mensaje);
		fflush(stdin);
		gets(buffer);

		while (isValidNumber(buffer) == 1)
		{
			printf("Error. Reingrese el numero: ");
			fflush(stdin);
			gets(buffer);
		}
		valorFlotante = atof(buffer);
	} while (valorFlotante < 0);
	return valorFlotante;
}

int isValidInt(int *number)
{
	int i = 0;
	int retorno = 0;
	int j;

	j = strlen(number);

	while (i < j && retorno == 0)
	{
		if (isdigit(number[i]) != 0)
		{
			i++;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}

int getInt(char *mensaje)
{
	int valorInt;
	char buffer[30];

	printf("%s: ", mensaje);
	fflush(stdin);
	gets(buffer);

	while (isValidInt(buffer) == 1)
	{
		printf("Error. Reingrese el numero: ");
		fflush(stdin);
		gets(buffer);
	}
	valorInt = atoi(buffer);

	return valorInt;
}
