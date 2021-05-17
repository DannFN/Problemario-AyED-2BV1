#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *voltear_cadena(char *);

int main(int argc, char const *argv[]) {
    char *cadena = "gato magistral";

    printf("%s\n", voltear_cadena(cadena));

    return 0;
}

char *voltear_cadena(char *cadena) {
    char *cadena_volteada = (char *) malloc((strlen(cadena) + 1) * sizeof(char));
    char temp = '\n';

    strcpy(cadena_volteada, cadena);

    for(size_t indx = 0; indx < strlen(cadena_volteada) / 2; indx++) {
        temp = *(cadena_volteada + indx);
        *(cadena_volteada + indx) = *(cadena_volteada + (strlen(cadena_volteada) - 1 - indx));
        *(cadena_volteada + (strlen(cadena_volteada) - 1 - indx)) = temp;
    }

    return cadena_volteada;      
}