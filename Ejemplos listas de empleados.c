#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Empleado {
    int cedula;
    float sueldo;
    struct Empleado* siguiente;
} Empleado;

// Función para generar un número aleatorio en el rango dado
int generarNumeroAleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Función para generar un sueldo aleatorio
float generarSueldoAleatorio(float min, float max) {
    float scale = rand() / (float)RAND_MAX;  // Valor entre 0 y 1
    return min + scale * (max - min);
}

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

// Función para imprimir la lista de empleados
void imprimirLista(Empleado* cabeza) {
    printf("\nCédula\tSueldo\n");
    while (cabeza != NULL) {
        printf("%d\t%.2f\n", cabeza->cedula, cabeza->sueldo);
        cabeza = cabeza->siguiente;
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
    srand(time(NULL));

    Empleado* cabeza = NULL;
    int n;

    printf("Ingrese la cantidad de empleados: ");
    scanf("%d", &n);

    // Generar empleados con cédulas y sueldos aleatorios
    for (int i = 0; i < n; i++) {
        int cedula = generarNumeroAleatorio(1000000, 9999999);
        float sueldo = generarSueldoAleatorio(1000.0, 10000.0);

        insertarEmpleado(&cabeza, cedula, sueldo);
    }

    // Ordenar la lista de forma ascendente (usando un enfoque simple de burbuja)
    int swapped;
    Empleado* ptr;
    Empleado* lptr = NULL;

    // Verificar si la lista está vacía
    if (cabeza == NULL) {
        return 0;
    }

    do {
        swapped = 0;
        ptr = cabeza;

        while (ptr->siguiente != lptr) {
            if (ptr->sueldo > ptr->siguiente->sueldo) {
                // Realizar el intercambio
                float tempSueldo = ptr->sueldo;
                ptr->sueldo = ptr->siguiente->sueldo;
                ptr->siguiente->sueldo = tempSueldo;

                swapped = 1;
            }
            ptr = ptr->siguiente;
        }
        lptr = ptr;
    } while (swapped);

    // Imprimir la lista ordenada de forma ascendente
    printf("\nLista ordenada de forma ascendente:\n");
    imprimirLista(cabeza);

    // Eliminar al empleado con el sueldo más alto
    eliminarSueldoMasAlto(&cabeza);

    // Imprimir la lista resultante después de eliminar el sueldo más alto
    printf("\nLista después de eliminar el sueldo más alto:\n");
    imprimirLista(cabeza);

    // Liberar la memoria
    liberarLista(cabeza);

    return 0;
}
