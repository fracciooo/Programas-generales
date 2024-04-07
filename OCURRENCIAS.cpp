#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

/* Programa realizado por:

	-Cristian Cova
	- Ignacio Fracchia

	Programa que encuentra las ocurrencias de un X dado
	en una pila.
	
*/

typedef struct pila{
	int dato;
	struct pila *sig;
} Pila;

void push(Pila **p, int dato);

int main(){
	
	repetir:
	system("cls");
	
	Pila *pila=NULL;
	
	int i=0;
	int j=0;
	int numero;
	int contador1=0, contador2=0, contador3=0;
	
	srand(time(NULL));
		printf("	+----------------+ \n");
		printf("	|      PILA      |\n");
		
	j=rand()%100+1;	
		
	while(i<j){
		
		numero=rand()%3+1;
		
		push(&pila,numero);
		printf("	+----------------+ \n");
		printf("\t|	%d	 |\n",numero);

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
	printf("	+----------------+ \n");
	printf("\n\n");
	printf("\t-Contador del numero 1: %d \n",contador1);
	printf("\t-Contador del numero 2: %d \n",contador2);
	printf("\t-Contador del numero 3: %d \n",contador3);
	
	printf("\t-Numeros totales generados: %d \n",j);
	
	printf("Presione enter para generar otros numeros en la pila \n");
	getch();
	goto repetir;
}

void push(Pila **p, int dato){
	Pila *nuevo=(Pila*)malloc(sizeof(Pila));
	nuevo->dato=dato;
	nuevo->sig=*p;
	*p=nuevo;
}
