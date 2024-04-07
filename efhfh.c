#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estructura para el nodo de la lista

typedef struct Dato {
    int dato;
    struct Dato* primero;
    struct Dato* siguiente;	//	Punteros .siguiente
    struct Dato* anterior;	//	Punteros .anterior
    struct Dato* actual;	//	Punteros .actual
	struct Dato* nuevo;		//	Punteros .nuevo
    
} Dato;

// Función para insertar un elemento al final de la lista
void insertar(struct Dato** primero, int nuevoDato) {
    struct Dato* nuevo = (struct Dato*)malloc(sizeof(struct Dato));
    nuevo->dato = nuevo;
    nuevo->siguiente = NULL;

    if (*primero == NULL) {
        *primero = nuevo;
    } else {
        struct Dato* temp = *primero;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

// Función para imprimir la lista
void imprimirLista(struct Dato* primero) {
    while (primero != NULL) {
        printf("%d | ", primero->dato);
        primero = primero->siguiente;
    }
}

// Función para invertir la lista usando recursividad
void invertirLista(struct Dato** primero) {
    struct Dato* primero;
    struct Dato* resto;

    if (*primero == NULL) {
        return;
    }

    primero = *primero; 
    resto = primero->siguiente;

    if (resto == NULL) {
        return; 
    }

    invertirLista(&resto);
    primero->siguiente->siguiente = primero; 
    primero->siguiente = NULL;
    *primero = resto; 
}

// Función para liberar la memoria utilizada por la lista
void liberarLista(struct Dato** primero) {
    while (*primero != NULL) {
        struct Dato* temp = *primero;
        *primero = (*primero)->siguiente;
        free(temp);
    }
}

int main() {
    struct Dato* lista = NULL;
    int numElementos, i;
    char reiniciar, entrada[100];

    do {
        liberarLista(&lista); // Liberar la lista antes de ingresar nuevos elementos
        while(1){
			// Validacion para que solo ingrese numeros, no se permiten letras
			fflush(stdin);
	    	printf("- Ingrese la cantidad de elementos: ");
			fflush(stdout);
			fgets(entrada, sizeof(entrada), stdin);
		   			
		    if (entrada[0] == '\n') {
				printf("\n\n\t    -----------------\n");
				printf("\t    ||  E-R-R-O-R  ||");
				printf("\n\t    -----------------\n");						
		        printf("\n       No ha ingresado ningun numero\n");
			   	printf("\n  Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;									
		    } else if (strchr(entrada, '.') != NULL) {
				printf("\n\n\t    -----------------\n");
				printf("\t    ||  E-R-R-O-R  ||");
				printf("\n\t    -----------------\n");						
		        printf("\n        No se permiten decimales\n");
			   	printf("\n  Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;	   		
			} else if (strlen(entrada) > 4) {
				printf("\n\n\t    -----------------\n");
				printf("\t    ||  E-R-R-O-R  ||");
				printf("\n\t    -----------------\n");						
		        printf("\n    Digite una cantidad menor a 4 digitos\n");
			   	printf("\n  Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
			} else if (sscanf(entrada, "%d", &numElementos) != 1) {
		        printf("\n\n\t    -----------------\n");
				printf("\t    ||  E-R-R-O-R  ||");
				printf("\n\t    -----------------\n");
				printf("\n\t  Debe ingresar numeros\n");
		    	printf("\n  Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;			
		    } else if (numElementos <= 0) {
		        printf("\n\n\t    -----------------\n");
				printf("\t    ||  E-R-R-O-R  ||");
				printf("\n\t    -----------------\n");
				printf("\n     La cantidad debe ser superior a 0\n");
		    	printf("\n  Presione cualquier tecla para continuar: "); getch();
				system("cls");
				fflush(stdin);
				continue;
		    }
		    break;
		}
        srand(time(0));
        for (i = 0; i < numElementos; i++) {
            insertar(&lista, rand() % 100); // Generar números enteros aleatorios entre 0 y 99
        }

        printf("\nLista original:\n");
        imprimirLista(lista);

        invertirLista(&lista);
        
        printf("\nLista invertida:\n");
        imprimirLista(lista);

        printf("\n¿Desea reiniciar el programa? (s/n): ");
        scanf(" %c", &reiniciar);
        system("cls");
        
    } while (reiniciar == 's' || reiniciar == 'S');
    
    liberarLista(&lista); // Liberar la lista antes de salir del programa

    return 0;
}
