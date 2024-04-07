#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validarEntrada(const char* entrada, const int *numero);

int main() 
{
    char entrada[100];
   	int numero;
   	
    while (!validarEntrada(entrada, numero)){}

	printf("Ha ingresado: %d", numero);

    return 0;
}

int validarEntrada(const char* entrada, const int *numero) {
	
	while(1)
	{	
		printf("Entrada: ");
		fgets(entrada, sizeof(entrada), stdin);
   	
		if (entrada[0] == '\n') 
		{
			printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
		    printf("\n\t\t\t\t\t\t\t      No ha ingresado ningun valor\n");
		   	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);	
			continue;		
		} 
		else if (strchr(entrada, '.') != NULL) 
		{
			printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
		    printf("\n\t\t\t\t\t\t\t\tNo se permiten decimales\n");
		   	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;		
	    }
	    else if (sscanf(entrada, "%d", &numero) != 1) {
            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\n\t\t\t\t\t\t\t\t  Debe ingresar numeros\n");
   	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
				
        } else if (numero <= 0) {
            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\n\t\t\t\t\t\t\t   La cantidad debe ser superior a 0\n");
   	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
        }
	    break;	   
	}
    return 1;
}
