/*
PROGRAMA DE PLATOS/RESTAURANTE
	
	REALIZADO POR:
	- Cristian Cova C.I.27750961
	- Ignacio Fracchia C.I.28484721
*/

// LIBRERIAS A USAR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pilas.h"
#define MAX_PLATOS 100

// FUNCIONES A USAR
void imprimir_platos();
void push(); 
int pop();

//FUNCION PRINCIPAL
int main() {
    
    Pila *pila_morados = NULL, *pila_verdes = NULL, *pila_blancos = NULL;
	int cantidad_platos, i, j, k, morados = 0, verdes = 0, blancos = 0;
    char entrada[100];
    
    srand(time(NULL) % 100);
    
    // CICLO DEL PROGRAMA
    while(1)
    {
	    	fflush(stdin);		
			printf("Ingrese la cantidad de platos (Max %d): ", MAX_PLATOS);
   			fflush(stdout);
  			fgets(entrada, sizeof(entrada), stdin);
	    			
	    	//VALIDACION DE DATOS
        if (entrada[0] == '\n') {
			printf("\n\n           -----------------\n");
   			printf("           ||  E-R-R-O-R  ||");
   			printf("\n           -----------------\n");						
            printf("\n      No ha ingresado ningun numero\n");
  	    	printf("\n Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
			//VALIDACION DE DATOS					
        } else if (strchr(entrada, '.') != NULL) {
			printf("\n\n           -----------------\n");
   			printf("           ||  E-R-R-O-R  ||");
   			printf("\n           -----------------\n");						
            printf("\n\tNo se permiten decimales\n");
  	    	printf("\n Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
   		}
	       //VALIDACION DE DATOS 		
		else if (sscanf(entrada, "%d", &cantidad_platos) != 1) {
	        printf("\n\n           -----------------\n");
			printf("           ||  E-R-R-O-R  ||");
			printf("\n           -----------------\n");
			printf("\n\t Debe ingresar numeros\n");
   	    	printf("\n Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
			//VALIDACION DE DATOS				
        } else if (cantidad_platos < 1 || cantidad_platos  > 100) {
            printf("\n\n           -----------------\n");
   			printf("           ||  E-R-R-O-R  ||");
   			printf("\n           -----------------\n");
			printf("\nLa cantidad debe ser superior a 0 y menor a 100\n");
   	    	printf("\n    Presione cualquier tecla para continuar: "); getch();
			system("cls");
			fflush(stdin);
			continue;
        }
		system("cls");
		break;
	}    

	
    for (i = 1; i <= cantidad_platos; i++) {
        j = rand() % 3;
        if (j == 0) {
            morados++;
            push(&pila_morados, j);
        } else if (j == 1) {
            verdes++;
            push(&pila_verdes, j);
        } else {
            blancos++;
            push(&pila_blancos, j);
        }
    }
    
    imprimir_platos(morados, verdes, blancos);
    
    k = rand() % 100;
    
    int input;
    
    printf("Retirando y agregando platos hasta el plato N°%d...\n", k);
    
	for (i = 1; i <= k; i++) {
    	
    	Sleep(900);
    	
        j = rand() % 5;
        input = rand() % 1;
    
        if(input == 0)
        {
        	
		if (j == 0) {
            if (pila_morados != NULL) {
                morados++;
                pop(&pila_morados);
                printf("Se ingreso  un plato \033[1;35mMAGENTA\x1b[0m.\n");
            }
        } else if (j == 1) {
            if (pila_verdes != NULL) {
                verdes++;
                pop(&pila_verdes);
                printf("Se ingreso  un plato \x1b[32mVERDE\x1b[0m.\n");
            }
        } else if (j == 2){
            if (pila_blancos != NULL) {
                blancos++;
                pop(&pila_blancos);
                printf("Se ingreso  un plato \033[1;37mBLANCO\x1b[0m.\n");
            }
        }else if(input == 0){
        	
		}if (j == 3){
        	if(pila_morados != NULL){
        		morados--;
        		push(&pila_morados, j);
        		printf("Se retiro un plato \033[1;35mMAGENTA\x1b[0m.\n");
			}
		}
		
		}else if (j == 4){
        	if(pila_verdes != NULL){
        		verdes--;
        		push(&pila_verdes, j);
        		printf("Se retiro un plato \x1b[32mVERDE\x1b[0m.\n");
			}else {
        	if(pila_blancos != NULL){
        		blancos--;
        		push(&pila_blancos, j);
        		printf("Se retiro un plato \033[1;37mBLANCO\x1b[0m.\n");
			}
		}
		
		}
    }
    
    imprimir_platos(morados, verdes, blancos);

	// VACIAR LA PILA
    
    while (pila_morados != NULL || pila_verdes != NULL || pila_blancos != NULL) {
        pop(&pila_morados);
        pop(&pila_verdes);
        pop(&pila_blancos);
    }
    return 0;
} 

void push(Pila **p, int color) {
    Pila *nuevo = (Pila*) malloc(sizeof(Pila));
    nuevo->color = color;
    nuevo->sig = *p;
    *p = nuevo;
}

int pop(Pila **p) {
    int color = -1;
    if (*p != NULL) {
        color = (*p)->color;
        Pila *aux = *p;
        *p = (*p)->sig;
        free(aux);
    }
    return color;
}

void imprimir_platos(int morados, int verdes, int blancos) {
    printf("Platos:\n");
    printf("- \033[1;35mMAGENTAS\x1b[0m: %d\n", morados);
    printf("- \x1b[32mVERDES\x1b[0m: %d\n", verdes);
    printf("- \033[1;37mBLANCOS\x1b[0m: %d\n", blancos);
}
