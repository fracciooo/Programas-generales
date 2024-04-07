#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h>

int main() {
    
	int i, j;
	
	Inicio:
	printf("Presione enter para empezar: ");
	
	while(getch() != 13) {
		
		printf("\n\nError, tecla no disponible\n");
		system("pause");
		system("cls");
		goto Inicio;
		continue;
	}
	
	system("cls");
	printf("Procesando ...\n\n");
	
    for (i = 0; i <= 20; i++)  {
        fflush(stdin);
		printf("\r[");
        
        for (j = 0; j < i; j++) {
            printf("=");
        }
        
        if(i < 20)
        {
        	printf(">");	
		}
        else if(i == 20){
        	printf("=");
		}
        
        for (j = i; j < 20; j++) {
            printf(" ");
        }
        
        printf("] %d%%", i*5);
        fflush(stdout);
        usleep(300000);
	}
    
    printf("\n\n    Proceso completado\n");
    getch();
    return 0;
}
