#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

int main() {
   char board[ROWS][COLS];

   // Inicializar el tablero
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         board[i][j] = '-';
      }
   }

   // Mostrar el tablero
   for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
      
   }

   return 0;
}
