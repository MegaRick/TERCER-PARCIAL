#include <stdio.h>


int getEntero(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            while (getchar() != '\n') continue; // Limpiar el buffer de entrada manualmente
            return value;
        } else {
            printf("Entrada invalida. Por favor, ingrese un numero entero valido.\n");
            while (getchar() != '\n') continue; // Limpiar el buffer de entrada manualmente
        }
    }
}


char getCaracter(const char* prompt) {
    char value;
    while (1) {
        printf("%s", prompt);
        if (scanf(" %c", &value) == 1) {
            while (getchar() != '\n') continue; // Limpiar el buffer de entrada manualmente
            return value;
        } else {
            printf("Entrada invalida. Por favor, ingrese un caracter valido.\n");
            while (getchar() != '\n') continue; // Limpiar el buffer de entrada manualmente
        }
    }
}




