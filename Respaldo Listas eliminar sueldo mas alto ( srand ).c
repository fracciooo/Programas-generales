#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Empleado {	// Definición de la estructura del Empleado
    int cedula; // Dato de 8 digitos
    float sueldo; // Dato base 
    struct Empleado* siguiente;
	struct Empleado* nuevoEmpleado;
	struct Empleado* EmpleadoActual;
	struct Empleado* EmpleadoAnterior;
};

void insertarInicio(struct Empleado** cabeza, int cedula, float sueldo);
void imprimirLista(struct Empleado* cabeza);
void ordenarLista(struct Empleado* cabeza);
void eliminarSueldoMasAlto(struct Empleado** cabeza);
void liberarMemoria(struct Empleado* cabeza);
int generarNumeroAleatorio(int min, int max);
float generarSueldoAleatorio(float min, float max);

int main(){
    struct Empleado* cabeza = NULL;
    struct Empleado* sueldoMayor = cabeza;
	srand(time(0));
    int sueldo_1, sueldo_2, sueldo_3, sueldo_4, sueldo_5, rango = 40000000 - 10000000 + 1;
	int cedulaAleatoria = (rand() % rango) + 1000000, cedulaAleatoria2 = (rand() % rango) + 1000000;
    int cedulaAleatoria3 = (rand() % rango) + 1000000, cedulaAleatoria4 = (rand() % rango) + 1000000;
	int cedulaAleatoria5 = (rand() % rango) + 1000000, n, i;   
//    
//    sueldo_1 = rand() % 1000000; sueldo_2 = rand() % 1000000;
//    sueldo_3 = rand() % 1000000; sueldo_4 = rand() % 1000000;
//    sueldo_5 = rand() % 1000000;
//    
//    // Insertar Empleados en la lista uno a uno, tanto la cedula como el sueldo
//    insertarInicio(&cabeza, cedulaAleatoria, sueldo_1);
//    insertarInicio(&cabeza, cedulaAleatoria2, sueldo_2);
//    insertarInicio(&cabeza, cedulaAleatoria3, sueldo_3);
//    insertarInicio(&cabeza, cedulaAleatoria4, sueldo_4);
//    insertarInicio(&cabeza, cedulaAleatoria5, sueldo_5);

    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &n);
	
    // Generar empleados con cédulas y sueldos aleatorios
    for (i = 0; i < n; i++) {
        int cedula = generarNumeroAleatorio(10000000, 99999999);
        float sueldo = generarSueldoAleatorio(0.0, 1000000.0);

        insertarInicio(&cabeza, cedula, sueldo);
    }

    printf("\n\tv-- Lista de Llenado --v\n\n"); 	imprimirLista(cabeza);
    ordenarLista(cabeza);	    		// Ordenar la lista de forma ascendente
    printf("\tv-- Lista ordenada --v\n\n");    imprimirLista(cabeza);
    eliminarSueldoMasAlto(&cabeza);		// Eliminar sueldo más alto
    printf("  v-- Lista sin el sueldo mas alto --v\n\n");    imprimirLista(cabeza);
	liberarMemoria(cabeza);	    		// Liberar memoria
	return;
}

void insertarInicio(struct Empleado** cabeza, int cedula, float sueldo) {	
    struct Empleado* nuevoEmpleado = (struct Empleado*)malloc(sizeof(struct Empleado));
    nuevoEmpleado->cedula = cedula;
    nuevoEmpleado->sueldo = sueldo;
    nuevoEmpleado->siguiente = *cabeza;
    *cabeza = nuevoEmpleado;
}

void imprimirLista(struct Empleado* cabeza) {
    struct Empleado* EmpleadoActual = cabeza;
    int i = 0;
	while (EmpleadoActual != NULL) 
	{
        printf("Cedula #%d: %d - Sueldo #%d: %.2f\n",i + 1, EmpleadoActual->cedula,i + 1, EmpleadoActual->sueldo);
        EmpleadoActual = EmpleadoActual->siguiente;
        i++;
    } 
	printf("\n"); getch();
}

void ordenarLista(struct Empleado* cabeza) {
    struct Empleado *i, *j;
    int tempCedula;
    float tempSueldo;
    
    for (i = cabeza; i != NULL; i = i->siguiente) {
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (j->sueldo > i->sueldo) {
                tempSueldo = j->sueldo;	j->sueldo = i->sueldo;	i->sueldo = tempSueldo;
                tempCedula = j->cedula;	j->cedula = i->cedula;	i->cedula = tempCedula;
            }
        }
    }
}

void eliminarSueldoMasAlto(struct Empleado** cabeza) {
    struct Empleado* EmpleadoActual = *cabeza;
    struct Empleado* EmpleadoAnterior = NULL;
    struct Empleado* maxSueldoEmpleado = *cabeza;
    float SueldoMax = (*cabeza)->sueldo;

    while (EmpleadoActual->siguiente != NULL) 
	{	    // Buscar el Empleado con el sueldo más alto
        if (EmpleadoActual->siguiente->sueldo > SueldoMax) {
            EmpleadoAnterior = EmpleadoActual;
            maxSueldoEmpleado = EmpleadoActual->siguiente;
            SueldoMax = EmpleadoActual->siguiente->sueldo;
        }
        EmpleadoActual = EmpleadoActual->siguiente;
    }

    if (EmpleadoAnterior == NULL) {	    // Eliminar el Empleado con el sueldo más alto
        *cabeza = maxSueldoEmpleado->siguiente;
    } else {
        EmpleadoAnterior->siguiente = maxSueldoEmpleado->siguiente;
    }
    free(maxSueldoEmpleado);
}

// Función para liberar la memoria utilizada por la lista
void liberarMemoria(struct Empleado* cabeza) {
    
	struct Empleado* EmpleadoActual = cabeza;
    struct Empleado* EmpleadoSiguiente = NULL;
    
    while (EmpleadoActual != NULL) 
	{
        EmpleadoSiguiente = EmpleadoActual->siguiente;
        free(EmpleadoActual);
        EmpleadoActual = EmpleadoSiguiente;
    }
}

// Función para generar un número aleatorio en el rango dado
int generarNumeroAleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Función para generar un sueldo aleatorio
float generarSueldoAleatorio(float min, float max) {
    float scale = rand() / (float)RAND_MAX;  // Valor entre 0 y 1
    return min + scale * (max - min);
}

