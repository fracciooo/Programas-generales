#include <iostream>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main() {
	
	queue <int> cola;
    int inicio, k, i, c = 1, vuelta = 1;
	
	srand(time(NULL));    
			
	for(inicio = 1; inicio <= 8; inicio++ )
	{
		cola.push(inicio);
	}
	
		cout << "Solucionando las colisiones hasta la persona numero : "; cin>>k;
    
	for (i = 1; i <= k; i++) {
		
		int value = cola.front();
		if(value == 1)
		{
			cout << "\n---- VUELTA NUMERO " << vuelta << " ----" << endl << endl;
			vuelta++;
		}
	        
		cout  << "Atendiendo a la persona " << value << endl;
        cola.pop();
        cola.push(value);
		
		if(value == 8){ c++; }
       
		Sleep(500);	
	}
    
    cout << "\n-------------------------\n";
    cout << "\nLa persona # " << k << endl;
    cout << "Sera atendida en la vuelta: " << c << endl;
    cout << "En la posicion: " << cola.front() - 1 << endl;
    
    return 0;
}
