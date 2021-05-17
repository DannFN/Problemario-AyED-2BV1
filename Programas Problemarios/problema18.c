#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int busqueda_binaria_rec(int *, size_t, size_t, int);

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 4, 16, 28, 29, 33, 40, 52, 54, 55, 58, 59, 64, 65, 75, 83, 89, 90, 94, 95};
    int busquedas[] = {2,7,29,59, 89};

    for(size_t indx = 0; indx < sizeof(busquedas) / sizeof(*(busquedas)); indx++) {
        printf(
            "Existencia de %d es %d\n", 
            *(busquedas + indx), 
            busqueda_binaria_rec(arr, 0, sizeof(arr) / sizeof(*(arr)) - 1, *(busquedas + indx))
        );
    }
    
    return 0;
}

int busqueda_binaria_rec(int *arr_original, size_t inicio, size_t final, int parametro) {
    size_t medio = (inicio + final) / 2;
    
    if (inicio > final)
        return FALSE;
    
    if(parametro == *(arr_original + medio)) 
        return TRUE;
    else 
        return busqueda_binaria_rec(
            arr_original, 
            (parametro < *(arr_original + medio)) ? inicio : medio + 1, 
            (parametro < *(arr_original + medio)) ? medio - 1 : final,
            parametro
        );

    return FALSE;
}