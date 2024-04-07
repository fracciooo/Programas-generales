#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define TAMANO 10

void invertirArray(int array[], int incio, int final);

int main() 
{
    char array[TAMANO];
    int i, j, array_int[TAMANO];
    int randomizador;
    
	srand(time(NULL));	
//    Solicitar al usuario que ingrese los elementos del arreglo
    printf("Ingrese %d números diferentes:\n", TAMANO);
    for (i = 0; i < TAMANO; i++) 
	{
	  	while(1)
		{	
	    	fflush(stdin);
			fgets(array, sizeof(array), stdin);
	   			
	        if (array[0] == '\n') {
				printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
	   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
	   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
	            printf("\n\t\t\t\t\t\t\t      No ha ingresado ningun numero\n");
	  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
												
	        } else if (strchr(array, '.') != NULL) {
				printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
	   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
	   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
	            printf("\n\t\t\t\t\t\t\t\tNo se permiten decimales\n");
	 	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
	   		
			} else if (strlen(array) > 3) {
				printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
	   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
	   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
	            printf("\n\t\t\t\t\t\t\t     No se permiten mas de 3 digitos\n");
	 	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
	   		}
	       		
			else if (sscanf(array, "%d", &array_int) != 1) {
	            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
	   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
	   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
				printf("\n\t\t\t\t\t\t\t\t  Debe ingresar numeros\n");
	   	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
					
	        } 
			else if (array_int < 1) {
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
    }
	        
//	 Presentamos aleatoreamente los numeros almacenados en el array
//    for(i = 0; i < TAMANO; i++)
//    {
//    	randomizador = rand();
//    	for(j = 0; j < i; j++)
//    	{
//    		if(array[i] ==  randomizador)
//    		{// Utilizamos el if para comparar uno a uno los valores e intentar que no se repitan
//    			randomizador == rand();
//    			j = -1;
//			}
//		}
//		array[i] = randomizador;
//	}
    
    // Se presenta el arreglo principal sin aplicar recursividad
    printf("| Arreglo original |\n");
    for (i = 0; i < TAMANO; i++) 
	{
        printf("| P%i => ", i+1);
        printf("%d\n", array_int[i]);
    }
    
    // Se llama a la funcion para aplicar la recursividad en el array principal
    invertirArray(array_int, 0, TAMANO - 1);
    
    // Se presenta el arreglo principal con la recursividad ya aplicada    
    printf("\n\n| Arreglo invertido |\n");
    
	for (i = 0; i < TAMANO; i++) 
	{
        printf("| P%i => ", i+1);
        printf("%d\n", array_int[i]);
    }
     
    return EXIT_FAILURE;
}
// Función recursiva para invertir el arreglo
void invertirArray(int array[], int inicio, int final) 
{    
    int temp;    
    // Con esta condicion estamos cambiando las posiciones del arrat
	if (inicio >= final) 
	{
        return; 
    }
    // Intercambiamos los elementos en las posiciones con el metodo burbuja
    temp = array[inicio];
    array[inicio] = array[final];
    array[final] = temp;
    
    // Se llama posicion 1 a 1 para poder invertir las posiciones
    invertirArray(array, inicio + 1, final - 1);
}
