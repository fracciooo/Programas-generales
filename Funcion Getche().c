/*

DATO: la funcion getche(), valida el enter indirectamente, por lo tanto es bueno

*/

#include <stdio.h>
#include <conio.h>

void getcheConNumeros();
void getcheConLetras();

int main() {
	
	int opc;
	
	printf("Menu\n");
	printf("1- Ver numero con la funcion getche()\n");
	printf("2- Ver letra con la funcion getche()\n");
	printf("3- Exit\n");
	printf("Opc: "); scanf("%d", &opc);
	
	system("cls");
	
	switch(opc)
	{
		case 1:{
			getcheConNumeros();
			break;
		}
		case 2:{
			getcheConLetras();
			break;
		}
		case 3:{
			return 0;
			break;
		}
		default:{
			printf("Error, input no valida.");
			system("pause");
			system("cls");
			break;
		}
	}
    return 0;
}

void getcheConNumeros()
{
    char ch;
    int num;
					
    do 
	{
        printf("Ingrese un numero entre 0 y 9: ");
        ch = getche();
        num = ch - '0'; // Convertir el carácter en un número entero

        if (num >= 0 && num <= 9) 
		{
            break; // Salir del bucle si el número está en el rango válido
        } 
		else 
		{
            printf("\nEl numero ingresado esta fuera del rango. Intente nuevamente.\n");
            system("pause");
            system("cls");
        }
    } while (1);

    printf("\n\nEl numero ingresado es: %d\n", num);

}

void getcheConLetras()
{
	char letra;
    
	do 
	{
        printf("Ingrese una letra: ");
        letra = tolower(getche());

        if (letra >= 'a' && letra <= 'z') 
		{
            break; // Salir del bucle si la letra está en el abecedario
        } 
		else 
		{
            printf("\nLa letra ingresada no pertenece al abecedario. Intente nuevamente.\n");
        	system("pause");
        	system("cls");
		}
		
    } while (1);

    printf("\nLa letra ingresada es: %c\n", letra);
}
