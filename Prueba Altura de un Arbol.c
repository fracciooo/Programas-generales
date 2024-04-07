#include <stdio.h>
#include <stdlib.h>

// Estructura para un nodo de árbol binario
struct NodoArbol {
    int dato;
    struct NodoArbol* izquierda;
    struct NodoArbol* derecha;
};

// Función para crear un nuevo nodo de árbol
struct NodoArbol* crearNodo(int valor) {
    struct NodoArbol* nuevoNodo = (struct NodoArbol*)malloc(sizeof(struct NodoArbol));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un valor en el árbol
struct NodoArbol* insertar(struct NodoArbol* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// Función para calcular la altura de un árbol
int alturaArbol(struct NodoArbol* nodo) {
    if (nodo == NULL) {
        return 0;
    } else {
        int alturaIzquierda = alturaArbol(nodo->izquierda);
        int alturaDerecha = alturaArbol(nodo->derecha);

        if (alturaIzquierda > alturaDerecha) {
            return alturaIzquierda + 1;
        } else {
            return alturaDerecha + 1;
        }
    }
}

int main() {
    struct NodoArbol* raiz = NULL;
    int numElementos, valor;

    printf("Ingrese la cantidad de elementos que desea en el árbol: ");
    scanf("%d", &numElementos);

    for (int i = 0; i < numElementos; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &valor);
        raiz = insertar(raiz, valor);
    }

    int altura = alturaArbol(raiz);
    printf("La altura del árbol es: %d\n", altura);

    return 0;
}