#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include "Stack"



using namespace std;

stack <int> pila;

int validarnumero(char numero[]);

int main(){
	
	int k,m,opcvalida,nvalido,n1valido,buscarvalido;
	char opc[5],n[5],n1[5],buscar[5];
	
do{

		do{
			k=0;
			menu:
			system ("cls");
		cout<<"\tBienvenido\nPara ingresar numeros numeros en la pila presione (1)\nPara salir presione (2)\n\t\tOpc:";
		gets(opc);
		
		m=validarnumero(opc);
		
	}while(m==0);
	
	opcvalida=atoi(opc);
	
	
	if(opcvalida==1){
		
		system("cls");
		
		do{
			system("cls");
		cout<<"Ingrese cuantos numeros van en la pila:"; 
		gets(n);
		
		m=validarnumero(n);
		
		}while(m==0);
		
		nvalido=atoi(n);
		
		for(int i=0;i<nvalido;i++){
			
			do{
			system("cls");
			cout<<"Ingrese un numero: "; 
			gets(n1);
			
			m=validarnumero(n1);
			
			}while (m==0);
			
			n1valido=atoi(n1);
			
			pila.push(n1valido);
		}
		do{
		system("cls");
		cout<<"Que numero desea buscar:"; 
		gets(buscar);
		
		m=validarnumero(buscar);
		
		}while(m==0);
		
		buscarvalido=atoi(buscar);
		
		while((pila.size()>0)){
			
			if(pila.top()==buscarvalido){
				k++;
				
			}
			
			pila.pop();
			
		}
		if (k>0){
			
		cout<<"El numero "<<buscarvalido<<" esta repetido "<<k<<" veces\n";
		system("pause");	
		}else{
			cout<<"El numero "<<buscarvalido<<" no esta en la pila\n";
		system("pause");	
		}	
			}
	
		
 if(opcvalida==2){
	system("cls");
	cout<<"Hasta pronto...";
	return 0;
}
if (opcvalida!=2 && opcvalida!=1){
	
	cout<<"\tIngrese una opcion valida\n";
	system ("pause");
}

}while(opcvalida!=2||opcvalida!=1);
	
	
	return 0;
}

int validarnumero(char numero[]){
	
			int i;
			
			for(i=0; i<strlen(numero);i++){
				
				if(!(isdigit(numero[i])) && numero[i]!='-' && numero[i]!='\n' && numero[i]!='\0'){
					
					system("cls");
			 
					printf("\nERROR: INGRESE SOLO NUMEROS\n\n\n\n");
					system ("pause");
					system ("cls");

					return 0;
					
				}
			}
			
		}



