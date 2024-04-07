#include <stdio.h>
#include <windows.h>

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int i;
    
    gotoxy(10, 9); printf("Procesando:\n");
    
    for (i = 0; i <= 20; i++) {
        gotoxy(10, 10);
        
        // Imprimir la barra de carga
        for (int j = 0; j <= 20; j++) {
            if (j <= i) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        
        printf(" %d%%", i * 5);
        fflush(stdout);
        Sleep(500); // Suspender la ejecución durante medio segundo
    
    }
    
    gotoxy(10, 11);printf("\nProceso completado!\n");
    
    return 0;
}