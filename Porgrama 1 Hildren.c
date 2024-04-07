/*

Prograna #1 
Profesora: Hildren Morales

Rev: 16

Ingenieros creadores del programa: 

	- Cristian Cova C.I.27750961
	- Ignacio Fracchia C.I.28484721

Escriba un algoritmo en lenguaje C/C++ que presente un menú en el que se presente:

1- Modulo el cual genere una cantidad finita de números enteros aleatorios 

2- Modulo el cual genere una cantidad de colores mostrados en pantalla
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

void menu();

	char *colores[] = {"\x1b[31m""Rojo""\x1b[0m", "\x1b[32m""Verde""\x1b[0m", "\x1b[34m""Azul""\x1b[0m", "\x1b[33m""Amarillo""\x1b[0m", 
	                   "\x1B[38;2;255;151;203m""Rosa""\x1b[0m", "\x1B[38;2;255;128;0m""Naranja""\x1b[0m", "\x1B[38;2;176;174;174m""Gris""\x1b[0m", "\033[1;37m""Blanco""\x1b[0m", 
					   "\x1B[40m""Negro""\x1b[0m", "\x1b[36m""Turquesa""\x1b[0m", "\033[1;36m""Celeste""\x1b[0m", "\x1b[35m""Morado""\x1b[0m",
					   "\033[1;35m""Magenta Claro""\x1b[0m", "\033[1;31m""Rojo Claro""\x1b[0m", "\033[1;32m""Verde Claro""\x1b[0m",
					   "\033[0;34m""Azul Claro""\x1b[0m"
	};

int main()
{
	int cantidad_numeros, i, a, b, numeros[5], num_opcion;
    int index, f, cantidad_colores = sizeof(colores) / sizeof(colores[0]), colores_mostrar; 
    char opcion[10], entrada[10];
    
    do 
	{
        while(1)
	    {
	    	fflush(stdin);
	    	menu();
			printf("\t\t\t\t\t| Opcion: ");
			fflush(stdout);
        	
			fgets(opcion, sizeof(opcion), stdin);
        	
			if (opcion[strlen(opcion) - 1] == '\n') 
			{
            	opcion[strlen(opcion) - 1] = '\0';	
        	}
			if (strchr(opcion, '.') != NULL)
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
			if (sscanf(opcion, "%d", &num_opcion) != 1) 
			{
		    	printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    	printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    	printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
		    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
		    	continue;;
		   	
        	}else if (num_opcion < 1 || num_opcion > 3) {    
				printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		   		printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		   		printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
				printf("\n\t\t\t\t\t\t\t      Elija una opcion entre 1 y 3\n");
		       	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
			}
			break;
		}		
		system("cls");
        
		switch (num_opcion)
		{
            case 1:{
		        while(1)
			    {	// Correccion cantidad de numeros infinita
			    	fflush(stdin);
					printf("\n\n\t\t\t\t\t| Ingrese la cantidad de numeros aleatorios que desea generar |");
    				printf("\n\t\t\t\t\t| Cantidad de numeros: ");
					fflush(stdout);
    				fgets(entrada, sizeof(entrada), stdin);
    				
			        if (entrada[0] == '\n') {
						printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
			            printf("\n\t\t\t\t\t\t\t      No ha ingresado ningun numero\n");
			  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
						
			        } else if (strchr(entrada, '.') != NULL) {
						printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
			            printf("\n\t\t\t\t\t\t\t\tNo se permiten decimales\n");
			  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
        			}
					else if (sscanf(entrada, "%d", &cantidad_numeros) != 1) {
			            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
						printf("\n\t\t\t\t\t\t\t\t  Debe ingresar numeros\n");
        		    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
			        }
			        
					system("cls");
				
					printf("\n\n\t\t\t\t\t\t\t(%d) Numeros aleatorios mostrados en pantalla:\n", cantidad_numeros);
	                
					printf("\n");
					srand(time(NULL));
	    			for (i = 0; i < cantidad_numeros; i++) 
					{
	    	    		printf("\t\t\t\t\t\t\%i- %d\n", i+1, rand());
	    			}
	    			printf("\n\t\t\t\t\t\t\t  Presione cualquier tecla para continuar: "); getch();
					system("cls");
					break;
				}
				break;	
			}
            case 2:{
            	
				srand(time(NULL));
    			
                while(1)
			    {	//Coreccion, no darle limites a la cantidad de cobinaciones de colores mostrados en pantalla
                
			    	fflush(stdin);
					printf("\n\n\t\t\t\t\t| Ingrese la cantidad de colores aleatorios que desea generar (Max 16 combinaciones) |");
    				printf("\n\t\t\t\t\t| Cantidad de colores: ");
					fflush(stdout);
    				fgets(entrada, sizeof(entrada), stdin);
    				
			        if (entrada[0] == '\n') {
						printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
			            printf("\n\t\t\t\t\t\t\t      No ha ingresado ningun numero\n");
			  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
						
			        } else if (strchr(entrada, '.') != NULL) {
						printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
			            printf("\n\t\t\t\t\t\t\t\tNo se permiten decimales\n");
			  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
        			}
					else if (sscanf(entrada, "%d", &colores_mostrar) != 1) {
			            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
						printf("\n\t\t\t\t\t\t\t\t  Debe ingresar numeros\n");
        		    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
			        }				
					else if (colores_mostrar < 1) {
			            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
		    			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
		    			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
						printf("\n\t\t\t\t\t\t\t   Debe ingresar un numero entre 1 y 16\n");
        		    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
						system("cls");
						fflush(stdin);
						continue;
			        }
					break;				
				}				
					
					for (a = 0; a < 5; a++) {
        				numeros[a] = rand() % cantidad_colores;
        				for (b = 0; b < a; b++) {
            				if (numeros[b] == numeros[a]) {
 	          					a--;
    	       					break;
           					}
   						}
  					}
					printf("\n\n\t\t\t\t\t\t\tColores aleatorios mostrados en pantalla:\n\n");
                
                //No darle limites, que el usuario elija el limite
				for (f = 0; f < colores_mostrar; f++) {
        			index = rand() % cantidad_colores;
        			
					printf("\t\t\t\t\t\t\%i- %s\n", f+1, colores[index]);
					
    			}
    			
    			printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: "); getch();
				system("cls");
				break;
			}
			case 3:{
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  -------------------------\n");
				printf("\t\t\t\t\t\t\t\t  || PROGRAMA FINALIZADO ||");
		   		printf("\n\t\t\t\t\t\t\t\t  -------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				getch();
				return 0;
			}
    	fflush(stdin);
	
	
		}
	}while(1);
    	
	return 0;

}
void menu()
{
	printf("\n\n\t\t\t\t\t\t\t\t|--- MENU DE OPCIONES ---|\n");
	printf("\t\t\t\t\t| 1- Modulo para generar una cantidad finita de numeros aleatorios. |\n");
	printf("\t\t\t\t\t| 2- Modulo para generar una cantidad de colores en pantalla.       |\n");
	printf("\t\t\t\t\t| 3- Modulo para finalizar el programa.				    |\n");
}
