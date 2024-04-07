#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Declarando la matriz que representa el tablero
char tablero[ROWS][COLS];

// Función para inicializar el tablero
void initializeBoard() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            tablero[i][j] = '-';
        }
    }
}

// Función para imprimir el tablero
void mostrar_tablero() {
    int i, j;

    printf("   ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("%d |", i);
        for (j = 0; j < COLS; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Función para colocar un barco en el tablero
void imprimir_barcos(int row, int col) {
    tablero[row][col] = 'S';
}

// Función para registrar un ataque en el tablero
void ataques(int row, int col) {
	
    if (tablero[row][col] == 'S') {
        tablero[row][col] = 'X';
        printf("¡Acertaste! ¡Barco hundido!\n");        system("pause");
        system("cls");
    } else if (tablero[row][col] == '-') {
        tablero[row][col] = 'O';
        printf("¡Has fallado!\n");
        system("pause");
        system("cls");
    } else {
        printf("Ya has atacado esa posición.\n");
         system("pause");
        system("cls");
    }
}

int main() {
    int row, col;
    int random_posicion;
    int random_posicion_2;

    Inicio:
    initializeBoard();
    mostrar_tablero();
    
    // Inicializamos la semilla para colocsr el barco en donde queramos
    srand(time(0));
    
    random_posicion = rand() % 10;
    random_posicion_2 = rand() % 10;

    // Colocacion de barcos de manera aleatoria
    imprimir_barcos(random_posicion, random_posicion);
    imprimir_barcos(random_posicion_2, random_posicion_2);

    // Empieza la partida
    while (1) {
    	
        printf("Ingresa la fila: ");
        scanf("%d", &row);
        if(row > 10 || row < 0)
        {
        	fflush(stdin);
        	printf("Error, vuelta a poner la fila\n");
        	system("pause");
        	system("cls");
        	goto Inicio;
        	fflush(stdout);
         }

        printf("Ingresa la columna: ");
        scanf("%d", &col);
        
		if(col > 10 || col < 0)
        {
        	fflush(stdin);
        	printf("Error, vuelta a poner la columna\n");
        	system("pause");
        	system("cls");
        	goto Inicio;
        	fflush(stdout);
         }

        ataques(row, col);
        mostrar_tablero();
    }

    return 0;
}
