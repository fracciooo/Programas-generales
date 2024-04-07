#include <stdio.h>
#include <stdlib.h>

typedef struct Empleado {
    int cedula;
    float sueldo;
    struct Empleado* siguiente;
} Empleado;

// Función para insertar un empleado al final de la lista
void insertarEmpleado(Empleado** cabeza, int cedula, float sueldo) {
    Empleado* nuevoEmpleado = (Empleado*)malloc(sizeof(Empleado));
    nuevoEmpleado->cedula = cedula;
    nuevoEmpleado->sueldo = sueldo;
    nuevoEmpleado->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoEmpleado;
    } else {
        Empleado* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoEmpleado;
    }
}

// Función para buscar y eliminar el empleado con el sueldo más alto
void eliminarSueldoMasAlto(Empleado** cabeza) {
    if (*cabeza == NULL) {
        return;
    }

    Empleado* maximo = *cabeza;
    Empleado* anterior = NULL;
    Empleado* actual = *cabeza;

    // Buscar al empleado con el sueldo más alto
    while (actual->siguiente != NULL) {
        if (actual->siguiente->sueldo > maximo->sueldo) {
            maximo = actual->siguiente;
            anterior = actual;
        }
        actual = actual->siguiente;
    }

    // Eliminar al empleado con el sueldo más alto
    if (anterior == NULL) {
        *cabeza = maximo->siguiente;
    } else {
        anterior->siguiente = maximo->siguiente;
    }

    free(maximo);
}

// Función de comparación para el ordenamiento de la lista
int compararSueldos(const void* a, const void* b) {
    float sueldoA = (*(Empleado**)b)->sueldo;
    float sueldoB = (*(Empleado**)a)->sueldo;

    if (sueldoA > sueldoB) {
        return 1;
    } else if (sueldoA < sueldoB) {
        return -1;
    } else {
        return 0;
    }
}

// Función para liberar la memoria de la lista de empleados
void liberarLista(Empleado* cabeza) {
    while (cabeza != NULL) {
        Empleado* actual = cabeza;
        cabeza = cabeza->siguiente;
        free(actual);
    }
}

int main() {
    Empleado* cabeza = NULL;
    int n, i;
    printf("Ingrese la cantidad de empleados: "); scanf("%d", &n);

    // Solicitar al usuario ingresar los datos de cada empleado
    for (i = 0; i < n; i++) {
        int cedula;
        float sueldo;
        printf("Ingrese la cédula del empleado %d: ", i + 1); scanf("%d", &cedula);
        printf("Ingrese el sueldo del empleado %d: ", i + 1); scanf("%f", &sueldo);
        insertarEmpleado(&cabeza, cedula, sueldo);
    }

    // Convertir la lista a un arreglo para ordenarla
    Empleado** arregloEmpleados = (Empleado**)malloc(n * sizeof(Empleado*));
    int j = 0;
    Empleado* actual = cabeza;
    while (actual != NULL) {
        arregloEmpleados[j] = actual;
        actual = actual->siguiente;
        j++;
    }

    // Ordenar el arreglo de empleados de forma descendente
    qsort(arregloEmpleados, n, sizeof(Empleado*), compararSueldos);
		
    // Eliminar al empleado con el sueldo más alto
    eliminarSueldoMasAlto(&cabeza);

    // Imprimir la lista resultante
    printf("\nCédula  Sueldo\n");
    actual = cabeza;
    while (actual != NULL) {
        printf("%d     %.2f\n", actual->cedula, actual->sueldo);
        actual = actual->siguiente;
    }

    // Liberar la memoria
    liberarLista(cabeza);
    free(arregloEmpleados);

    return 0;
}
