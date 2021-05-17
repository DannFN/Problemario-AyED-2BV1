#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int *ordenamiento_rapido(int *, int);
void ordenamiento_rapido_rec(int *, int, int);
int partir(int *arr_original, int, int);

int main(int argc, char const *argv[]) {
    int arr[] = {8, 4, 1, 6, 0, 3, 25, 7, 9};
    int tam_arr = sizeof(arr) / sizeof(arr[0]);
    int *arr_ordenado = NULL;

    arr_ordenado = ordenamiento_rapido(arr, tam_arr);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        printf("%d, ", *(arr_ordenado + indx));
    }

    return 0;
}

int *ordenamiento_rapido(int *arr_original, int tam_arr) {
    int *arr = (int *) malloc(tam_arr * sizeof(int));

    for(size_t indx = 0; indx < tam_arr; indx++) 
        *(arr + indx) = *(arr_original + indx);

    ordenamiento_rapido_rec(arr, 0, tam_arr - 1);

    return arr;
}

void ordenamiento_rapido_rec(int *arr_original, int inicio, int final) {
    if(inicio > final)
        return;

    int division = partir(arr_original, inicio, final);

    ordenamiento_rapido_rec(arr_original, inicio, division - 1);
    ordenamiento_rapido_rec(arr_original, division + 1, final);
    
}

int partir(int *arr_original, int inicio, int final) {
    int pivote, aux, indx_izq, indx_der, bandera;

    pivote = *(arr_original + inicio);
    indx_izq = inicio + 1;
    indx_der = final;
    bandera = FALSE;
    
    while(!bandera) {
        while(indx_izq <= indx_der && *(arr_original + indx_izq) <= pivote)
            indx_izq++;
        
        while(indx_der >= indx_izq && *(arr_original + indx_der) >= pivote)
            indx_der--;

        if(indx_der < indx_izq) {
            bandera = TRUE;
        } else {
            aux = *(arr_original + indx_izq);
            *(arr_original + indx_izq) = *(arr_original + indx_der);
            *(arr_original + indx_der) = aux;
        }     
    }

    aux = *(arr_original + inicio);
    *(arr_original + inicio) = *(arr_original + indx_der);
    *(arr_original + indx_der) = aux;

    return indx_der;
}