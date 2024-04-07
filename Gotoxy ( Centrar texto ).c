#include <stdio.h>
#include <windows.h>
#include <conio.h>

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int consoleWidth;
    int consoleHeight;
    int textWidth;
    int textHeight;
    char text[] = "CENTRAR TEXTO";

    // Obtener las dimensiones de la ventana de la consola
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Calcular las coordenadas para posicionar el texto en el centro
    textWidth = strlen(text);
    textHeight = 1;  // Consideramos una sola línea de texto

    int xPos = (consoleWidth - textWidth) / 2;
    int yPos = (consoleHeight - textHeight) / 2;

    // Posicionar el cursor y imprimir el texto
    gotoxy(xPos, yPos);
    printf("%s\n", text);
	
	getch();
    return 0;
}