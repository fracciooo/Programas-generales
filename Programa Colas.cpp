/*
	PROGRAMA DE COLA EN UN BANCO
	REALIZADO POR:
	- Cristian Cova C.I.27750961
	- Ignacio Fracchia C.I.28484721
	

*/

//DECLARACION DE LIBRERIAS
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <unistd.h>

using namespace std;


// FUNCION PARA MOSTRAR LA COLA EN CONSOLA

void mostrarcola(queue<int> cola){
	
	int z=1;
	
	/*Errores:
	-No se mostraba la cola en la consola, solo 2 eventos de los clientes: Salir  de la cola  
	o que el cliente se devuelva al final de la cola)

	-La cola no se llenaba aleatoriamente a medida que corra el programa. Solo se que llenaba cuando se vaciaba
	*/
	
	cout<<"(El numero al lado del cliente NO representa cuantos hay en la cola) "<<endl;
	
	cout<<"+------------------------------------+"<<endl;	
	cout<<"|         TAQUILLA                   |"<<endl;
	cout<<"+------------------------------------+"<<endl;
	cout<<"|        v INICIO v                  |"<<endl;
	cout<<"+------------------------------------+"<<endl;
	
	while(!cola.empty()){
		
		cout<<"| Cliente "<<cola.front()<<"                    "<<endl;
		cout<<"+------------------------------------+"<<endl;
		cola.pop();
	}
	cout<<"|        ^ FINAL ^                   |"<<endl;
	cout<<"+------------------------------------+"<<endl;
	
	/*
	Correccion:
	-Ahora se muestra el estado de la cola en la consola con los eventos/acciones
	-Se agrego un "evento" adicional para que pueda ocurrir lo siguiente:
	
	+Que el cliente salga de la cola con la transaccion realizada exitosamente.
	+Que el cliente se devuelva al final de la cola debido a una falla en su transaccion
	+Que ingrese un nuevo cliente a la cola
	*/
}

//FUNCION PRINCIPAL
int main()
{
	int i;
	int evento;
    queue<int> fila;
    srand(time(NULL));	
    
	repetir:
		
	i=rand()%7+1;
	// SE GENERAN N NUMEROS DE CLIENTES 
	for(i; i<=8; i++)
		fila.push(i);

    while(true)
    {    	
    	// SE LLENA LA COLA NUEVAMENTE
    	if(fila.empty())
        {
            cout << "La cola esta vacia. Entran los nuevos clientes..." << endl;
            Sleep(1500);
            system("cls");
            goto repetir;
        }
    	
    	// LLAMADO A LA FUNCION PARA MOSTRAR LA COLA EN PANTALLA	
		mostrarcola(fila);
		
        int persona = fila.front();
       	int j;
        	
		cout<<endl;
			
        cout<< " Evento: "<< endl;
        
        Sleep(1500);
    	
    	// OCURREN UNO DE LOS TRES EVENTOS
		evento=rand()%3+1;	
		
		// LA PERSONA SALE DE LA COLA
        if(evento==1)
        {
        	cout<<endl;
        	cout << " El cliente del INICIO  ha realizado su transaccion y sale de la cola. " << endl;
        	fila.pop();   	
          	Sleep(1500);
        }
        
        // LA PERSONA TUVO UN PROBLEMA Y PASA AL FINAL DE LA COLA
        if(evento==2)
        {
        	cout<<endl;
        	fila.pop();
            cout << "El cliente ha tenido un problema en su transaccion y vuelve al FINAL de la cola" << endl;
            
            fila.push(persona);
            Sleep(1500);
        }
        
        // SE INGRESAN LAS PERSONAS A LA COLA
        if(evento==3)
        {	    		
        	//IDENTIFICACION DEL CLIENTE Y AGREGARLO A LA COLA
			j=rand()%93+8;
			fila.push(j);
        	cout<<" Ingresaron personas a la cola... "<<endl;
        	Sleep(1500);	
		}
		system("cls");
    }
    return 0;
}
