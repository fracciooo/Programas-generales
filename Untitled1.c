#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i = 0;

    printf("Ingrese una cadena: ");

    // Lee cada caracter ingresado y verifica si es alfabético
    do {
        str[i] = getchar();
        if (!isalpha(str[i]) && str[i] != ' ') {
            printf("\nError: Solo se permiten caracteres alfabéticos y espacios.\n");
            continue;
        }
        i++;
    } while (str[i - 1] != '\n');

    // Quita el salto de línea del final de la cadena
    str[i - 1] = '\0';

    printf("Cadena ingresada: %s\n", str);
    return 0;
}