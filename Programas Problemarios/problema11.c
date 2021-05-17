#include <stdio.h>
#include <stdlib.h>

#define NUM_ERROR -32768
#define TRUE 1
#define FALSE 0

int *ordenamiento_insercion(int *, int);
int *ordenamiento_seleccion(int *, int);
int *ordenamiento_burbuja(int *, int);
int *ordenamiento_mezcla(int *, int);
void ordenamiento_mezcla_rec(int *, int, int);
void mezclar(int *, int, int, int);

int main(int argc, char const *argv[]) {
    int arr[] = {8, 4, 1, 6, 0, 3, 25, 7, 9};
    int tam_arr = sizeof(arr) / sizeof(arr[0]);
    int *arr_ordenado = NULL;

    arr_ordenado = ordenamiento_insercion(arr, tam_arr);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        printf("%d, ", *(arr_ordenado + indx));
    }

    printf("\n\n");

    arr_ordenado = ordenamiento_seleccion(arr, tam_arr);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        printf("%d, ", *(arr_ordenado + indx));
    }

    printf("\n\n");

    arr_ordenado = ordenamiento_burbuja(arr, tam_arr);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        printf("%d, ", *(arr_ordenado + indx));
    }

    printf("\n\n");

    arr_ordenado = ordenamiento_mezcla(arr, tam_arr);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        printf("%d, ", *(arr_ordenado + indx));
    }

    return 0;
}

int *ordenamiento_insercion(int *arr_original, int tam_arr) {
    int pivote, aux;
    int *arr = (int *) malloc(tam_arr * sizeof(int));

    for(size_t indx = 0; indx < tam_arr; indx++) 
        *(arr + indx) = *(arr_original + indx);

    for(size_t indx = 1; indx < tam_arr; indx++) {
        pivote = *(arr + indx);
        
        for(size_t indy = indx + 1; indy --> 1;) {
            if(pivote < *(arr + (indy - 1))) {
                aux = *(arr + (indy - 1));
                *(arr + (indy - 1)) = pivote;
                *(arr + indy) = aux;
            }
        }
    }

    return arr;
} 

int *ordenamiento_seleccion(int *arr_original, int tam_arr) {
    int max_ciclo, aux, ind_aux;
    int *arr = (int *) malloc(tam_arr * sizeof(int));

    for(size_t indx = 0; indx < tam_arr; indx++) 
        *(arr + indx) = *(arr_original + indx);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        max_ciclo = aux = ind_aux = 0;

        for(size_t indy = 0; indy < tam_arr - indx; indy++) 
            if(*(arr + indy) > max_ciclo) {
                max_ciclo = *(arr + indy);
                ind_aux = indy;
            }
        
        aux = *(arr + (tam_arr - 1 - indx));
        *(arr + (tam_arr - 1 - indx)) = max_ciclo;
        *(arr + ind_aux) = aux;
    }

    return arr;
}

int *ordenamiento_burbuja(int *arr_original, int tam_arr) {
    int max_actual, aux, ind_aux;
    int *arr = (int *) malloc(tam_arr * sizeof(int));

    for(size_t indx = 0; indx < tam_arr; indx++) 
        *(arr + indx) = *(arr_original + indx);

    for(size_t indx = 0; indx < tam_arr; indx++) {
        max_actual = *(arr + 0);

        for(size_t indy = 0; indy < tam_arr - 1 - indx; indy++)  {
            if(max_actual > *(arr + indy + 1)) {
                aux = *(arr + indy + 1);
                *(arr + indy + 1) = max_actual;
                *(arr + indy) = aux;
            }else {
                max_actual = *(arr + indy + 1);
            }
        }
            
    }
    
    return arr;
}

int *ordenamiento_mezcla(int *arr_original, int tam_arr) {
    int *arr = (int *) malloc(tam_arr * sizeof(int));

    for(size_t indx = 0; indx < tam_arr; indx++) 
        *(arr + indx) = *(arr_original + indx);

    ordenamiento_mezcla_rec(arr, 0, tam_arr - 1);

    return arr;
}

void ordenamiento_mezcla_rec(int *arr_original, int inicio, int final) {
    if(inicio < final) {
        int medio = inicio + (final - inicio) / 2;
        
        ordenamiento_mezcla_rec(arr_original, inicio, medio);
        ordenamiento_mezcla_rec(arr_original, medio + 1, final);

        mezclar(arr_original, inicio, medio, final);
    }
}

void mezclar(int *arr_original, int inicio, int medio, int final) {
    int indx, indy, indz, tam_izq, tam_der;
    
    indx = indy = indz = 0;
    tam_izq = medio - inicio + 1;
    tam_der = final - medio;

    int *arr_par_izq = (int *) malloc(tam_izq * sizeof(int));
    int *arr_par_der = (int *) malloc(tam_der * sizeof(int));

    for(indx = 0; indx < tam_izq; indx++)
        *(arr_par_izq +indx) = *(arr_original + (inicio + indx));
    
    for(indx = 0; indx < tam_der; indx++)
        *(arr_par_der + indx) = *(arr_original + (medio + 1 + indx));

    indx = indy = 0;
    indz = inicio;

    while(indx < tam_izq && indy < tam_der) {
        if (*(arr_par_izq + indx) <= *(arr_par_der + indy)) {
            *(arr_original + indz) = *(arr_par_izq + indx);
            indx++;
        } else {
            *(arr_original + indz) = *(arr_par_der + indy);
            indy++;
        }

        indz++;
    }

    while (indx < tam_izq) {
        arr_original[indz] = arr_par_izq[indx];
        indx++;
        indz++;
    }

    while (indy < tam_der) {
        arr_original[indz] = arr_par_der[indy];
        indy++;
        indz++;
    }
}