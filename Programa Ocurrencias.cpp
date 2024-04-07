#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

/* Programa realizado por:
	-Cristian Cova
	- Ignacio Frachia

	Programa que encuentra las ocurrencias de un X dado
	en una pila.
*/

// DECLARACION DE LA PILA
typedef struct pila{
	int dato;
	struct pila *sig;
} Pila;

// FUNCION PARA AGREGAR LOS ELEMENTOS A LA PILA
void push(Pila **p, int dato){
	Pila *nuevo=(Pila*)malloc(sizeof(Pila));
	nuevo->dato=dato;
	nuevo->sig=*p;
	*p=nuevo;
}


//FUNCION PRINCIPAL
int main(){
	
	repetir:
	system("cls");
	
	Pila *pila=NULL;
	int i=0;
	int numero;
	int contador1=0, contador2=0, contador3=0;
	char entrada[100];
	int opcion;
	 
	
	srand(time(NULL));
		printf("	+----------------+ \n");
		printf("	|	PILA     |\n");
		
	while(i<10){
		
		numero=rand()%3+1;
		
	
		printf("	+----------------+ \n");
		printf("\t|	%d	 |\n", numero);	
		
		//CONTADOR DE LOS NUMEROS DE LA PILA
		if(numero==1)
		{
			contador1++;
		}
		
		if(numero==2)
		{
			contador2++;
		}
		
		if(numero==3)
		{
			contador3++;
		}
				
		i++;
	}
	
	printf("	+----------------+ \n\n");
		
		// CICLO DE VALIDACION DE DATOS
		while(1){
		
		fflush(stdin);
		printf(" Ingrese el numero que desea conocer cuantas veces se repitio en la pila (1 2 o 3) \n");
		fgets(entrada, sizeof(entrada), stdin);
	   			
	   			//VALIDACION SI NO SE INGRESA NADA
        if (entrada[0] == '\n') {
			printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
            printf("\n\t\t\t\t\t\t\t      No ha ingresado ningun numero\n");
  	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: \n\n"); getch();
  	    	system("cls");	
			fflush(stdin);
			continue;
				//VALIDACION SI SE INGRESAN DECIMALES		
        } else if (strchr(entrada, '.') != NULL) {
			printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
            printf("\n\t\t\t\t\t\t\t\tNo se permiten decimales\n");
 	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: \n\n"); getch();
			fflush(stdin);
			continue;
   		
				//VALIDACION DE DIGITOS INGRESADOS   		
		} else if (strlen(entrada) > 3) {
			printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");						
            printf("\n\t\t\t\t\t\t\t     No se permiten mas de 3 digitos\n");
 	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: \n\n"); getch();
 	    	system("cls");	
			fflush(stdin);
			continue;
   		}
       		//VALIDACION DE LETRAS
		else if (sscanf(entrada, "%d", &opcion) != 1) {
            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\n\t\t\t\t\t\t\t\t  Debe ingresar numeros\n");
   	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: \n\n"); getch();
   	    	system("cls");	
			fflush(stdin);
			continue;
			//VALIDACION DE LA OPCION INGRESADA
        } else if (opcion < 1) {
            printf("\n\n\t\t\t\t\t\t\t\t    -----------------\n");
   			printf("\t\t\t\t\t\t\t\t    ||  E-R-R-O-R  ||");
   			printf("\n\t\t\t\t\t\t\t\t    -----------------\n");
			printf("\n\t\t\t\t\t\t\t   La cantidad debe ser superior a 0\n");
   	    	printf("\n\t\t\t\t\t\t\t Presione cualquier tecla para continuar: \n\n"); getch();
   	    	system("cls");	
			fflush(stdin);
			continue;
        }
		
		//VALIDACION DE LOS ELEMENTOS QUE ESTAN EN LA PILA
		if(opcion>3)
		{
			printf("\t Ese numero no esta en la pila.  ");
			getch();
			system("cls");
			continue;
		}
		
		// MENSAJE EN CONSOLA DEL ELEMENTO REPETIDO
		if(opcion==1){
			printf("El numero 1 se repitio %d veces \n",contador1);
			printf("\t Presione cualquier tecla para continuar y generar otros numeros en la pila...\n");
			getch();
		
			fflush(stdin);
		}
		// MENSAJE EN CONSOLA DEL ELEMENTO REPETIDO
		if(opcion==2){
			printf("El numero 2 se repitio %d veces \n",contador2);
			printf("\t Presione cualquier tecla para continuar y generar otros numeros en la pila...\n");
			getch();
			
			fflush(stdin);
		}
		// MENSAJE EN CONSOLA DEL ELEMENTO REPETIDO
		if(opcion==3){
			printf("El numero 3 se repitio %d veces \n",contador3);
			printf("\t Presione cualquier tecla para continuar y generar otros numeros en la pila...\n");
			getch();
	
			fflush(stdin);
		}
	
		break;
		getch();
		system("cls");	
	}
	
	//GENERAR OTRA PILA 	
	goto repetir;
}
