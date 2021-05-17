#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int apartar_memoria(int **, int);
void liberar_memoria(int **);
void mostrar_direcciones(int **, int n);
void inicializar_arreglo(int **, int n);

int main() {
    int n = 25;
    int *arr = NULL;

    if(apartar_memoria(&arr, n)) {
        mostrar_direcciones(&arr, n);
        inicializar_arreglo(&arr, n);
        liberar_memoria(&arr);
    }

    return 0;
}

int apartar_memoria(int **dir_arreglo, int n) {
    if(n <= 0 || dir_arreglo == NULL) 
        return FALSE;

    *dir_arreglo = (int *) malloc(n * sizeof(int));

    return (*dir_arreglo != NULL) ? TRUE : FALSE;
}

void liberar_memoria(int **dir_arreglo) {
    free(*dir_arreglo);
}

void mostrar_direcciones(int **dir_arreglo, int n) {
    for(size_t indx = 0; indx < n; indx++) {
        printf("Direccion del elemento %d : #%X\n", indx + 1, (*dir_arreglo + indx));
    }
}

void inicializar_arreglo(int **dir_arreglo, int n) {
    for(size_t indx = 0; indx < n; indx++) {
        *(*dir_arreglo + indx) = indx * (int) (*dir_arreglo + indx); // mala practica pero ya alv 
    }
}