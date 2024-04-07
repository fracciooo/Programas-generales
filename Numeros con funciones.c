#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menu();
int suma(int numero_1, int numero_2, int suma);
int resta(int numero_1, int numero_2, int resta);
int multiplicacion(int numero_1, int numero_2, int multiplicacion);
int division(int numero_1, int numero_2, int division);
int numeros(int numero_1, int numero_2);

int main()
{
	int opc;
	numeros(&numero_1, &numero_2);
	menu();
	scanf("%d", &opc);
	
	switch(opc)
	{
		case 1:{
			printf("La suma es: %d", suma());
			break;
		}
		case 2:{
			printf("La resta es: %d", resta());
			break;
		}
		case 3:{
			printf("La multiplicacion es: %d", multiplicacion());
			break;
		}
		case 4:{
			printf("La division es: %d", division());
			break;
		}
		default:{
			printf("Opcion invalida:");
			getch();
			system("cls");
			break;
		}
	}
	
	return 0;
}

void menu()
{
	printf("\nOpciones:\n");
	printf("1- Suma\n"); 
	printf("2- Resta\n"); 
	printf("3- Multipliacion\n"); 
	printf("4- Division\n"); 
	printf("Opcion: "); 
}

int suma(int numero_1, int numero_2, int suma)
{
	suma = numero_1 + numero_2;
}

int resta(int numero_1, int numero_2, int resta)
{
	resta = numero_1 - numero_2;
}

int multiplicacion(int numero_1, int numero_2, int multiplicacion)
{
	multiplicacion = numero_1 * numero_2;
}

int division(int numero_1, int numero_2, int division)
{
	division = numero_1 / numero_2;
}

int numeros(int *numero_1, int *numero_2)
{
	printf("Ingrese el numero 1: "); scanf("%d", &numero_1);
	printf("\nIngrese el numero 2: "); scanf("%d", &numero_2);	
}
