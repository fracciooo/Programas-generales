#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Arbol{
	int dato;
	struct Arbol *der;
	struct Arbol *izq;
	struct Arbol *nuevo;
	struct Arbol *rec;
	struct Arbol *raiz;
};


Arbol *rec = NULL; // revisa la igualacion cambia arbol por ARBOL

// Funcion para crear un nuevo nodo de Arbol
struct Arbol* crearNodo(int valor) {
	
	struct Arbol *nuevo = new Arbol();
    
	nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    
	return nuevo;	//	retornamos el valor del nuevo elemento que se vaya ingresando 1 a 1 
}

void arbolEnOrden(Arbol *rec){
	if(rec==NULL){
		return;
	}
	else{
		arbolEnOrden(rec->izq);
		cout << rec->dato << " - ";
		arbolEnOrden(rec->der);
	}
}

void arbolEnPostOrden(Arbol *rec){
	if(rec==NULL){
		return;
	}
	else{
		arbolEnPostOrden(rec->izq);
		arbolEnPostOrden(rec->der);
		cout << rec->dato << " - ";
	}
}

void arbolEnPreOrden(Arbol *rec){
	if(rec==NULL){
		return;
	}
	
	else{
		cout << rec->dato << " - ";
		arbolEnPreOrden(rec->izq);
		arbolEnPreOrden(rec->der);
		
	}
}

void insertarNodo(Arbol *&rec, int dato) {
    if (rec == NULL) {
        Arbol *nuevo_nodo = crearNodo(dato);
        rec = nuevo_nodo;
    } else {
        if (rec->izq == NULL) {
            insertarNodo(rec->izq, dato);
        } else if (rec->der == NULL) {
            insertarNodo(rec->der, dato);
        } else {
            // Generar un número aleatorio para decidir en qué dirección insertar el nuevo nodo
            int direccion = rand() % 2;
            if (direccion == 0) {
                insertarNodo(rec->izq, dato);
            } else {
                insertarNodo(rec->der, dato);
            }
        }
    }
}

void mostrarArbol(Arbol *rec,int cont){ // cambia arbol por ARBOL el que tiene la funcion
	
	if(rec==NULL){
		return;
	}else{
		mostrarArbol(rec->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"    ";
		}
		cout<<rec->dato<<endl;
		mostrarArbol(rec->izq,cont+1);
	}
}

int alturaArbol(struct Arbol* rec) {
    if (rec == NULL) {
        return 0;//	Verificamos si el arbol no esta vacio
    } else {
		int alturaIzquierda = alturaArbol(rec->izq);	// Inicializamos la variable para contabilizar la altura del lado izquierdo
	    int alturaDerecha = alturaArbol(rec->der);	// Inicializamos la variable para contabilizar la altura del lado derecho
	
        if (alturaIzquierda > alturaDerecha) {	// Verificamos si el lado izquierdo es mayor que el lado derecho
            return alturaIzquierda + 1;	// Si es asi se le suma un nivel al lado izquierdo
        } else {
            return alturaDerecha + 1;	// Caso contrario se le suma al lado derecho
        }
    }
}

int contadorDeHojas(struct Arbol* rec) {
    if (rec == NULL) {
        return 0;
    }
    if (rec->izq == NULL && rec->der == NULL) {
        return 1;
    }
    return contadorDeHojas(rec->izq) + contadorDeHojas(rec->der);
}
int main(){
	
    struct Arbol* raiz = NULL;
    struct Arbol* rec = NULL; 
    int cantidadElementos, elemento, valor, i, opc, cont = 0;
    
    do{
    	fflush(stdin);
    	cout<<"--- 00 --- MENU --- 00 ---\n";
    	cout<<"1- Insertar nodos al arbol.\n";
    	cout<<"2- Mostrar nodos del arbol.\n";
    	cout<<"3- Visualizar la altura del arbol.\n";
    	cout<<"4- Visualizar las hojas del arbol ingresado.\n";
		cout<<"5- Visualizar el PreOrden del arbol.\n";
		cout<<"6- Visualizar el InOrden del arbol.\n";
		cout<<"7- Visualizar el PostOrden del arbol.\n";
		cout<<"8- Salir.\n";
    	cout<<"Opcion: "; scanf("%d", &opc);
    	fflush(stdout);
    	
    	switch(opc)
    	{
    		case 1:{
				system("cls");		
			    cout<<"Ingrese la cantidad de elementos que desea agregar al Arbol: ";
			    scanf("%d", &cantidadElementos);
			
			    for (i = 0; i < cantidadElementos; i++) {
			        cout<<"Ingrese el valor "<< i + 1 <<": ";
			        scanf("%d", &valor);
			        insertarNodo(rec, valor);
			    }
			
			    cout<<"\nArbol ingresado: \n\n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
			    getch();
			    system("cls");
				break;
			}
			case 2:{
			    cout<<"\nArbol ingresado: \n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
			    getch();
			    system("cls");				
				break;
			}
			case 3:{
				int altura = alturaArbol(rec);
			    cout<<"\nLa altura del arbol es: " << altura - 1 << "\n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
				getch();
			    system("cls");
				break;
			}
			case 4:{
				int hojas = contadorDeHojas(rec);
    			cout<<"\nEl arbol tiene "<< hojas << " hojas.\n";
				mostrarArbol(rec, cont);
			    cout<<"\n";
				getch();
			    system("cls");
				break;
			}
			case 5:{
				cout<<"\nRecorrido en PreOrden.\n\n";
				arbolEnPreOrden(rec);
			    cout<<"\n\nArbol ingresado: \n\n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
			    getch();
			    system("cls");
				break;
			}
			case 6:{
				cout<<"\nRecorrido en InOrden.\n\n";
				arbolEnOrden(rec);			
			    cout<<"\n\nArbol ingresado: \n\n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
			    getch();
			    system("cls");				
				break;
			}
			case 7:{
				cout<<"\nRecorrido en PostOrden.\n\n";
				arbolEnPostOrden(rec);			
			    cout<<"\n\nArbol ingresado: \n\n";
			    mostrarArbol(rec, cont);
			    cout<<"\n";
			    getch();
			    system("cls");
				break;
			}
			case 8:{
				return 0;	
			}
			default:{
				cout<<"Opcion Invalida. . .\n";
				getch();
				system("cls");
				break;
			}
		}
	}while(opc != 8);
    
	return 0;
}