#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int busqueda_binaria(int *, int, int);

int main(int argc, char const *argv[]) {
    int arr[] = {1,2, 4, 16, 28, 29, 33, 40, 52, 54, 55, 58, 59, 64, 65, 75, 83, 89, 90, 94, 95};
    int busquedas[] = {2,7,29,59, 89};

    for(size_t indx = 0; indx < sizeof(busquedas) / sizeof(*(busquedas)); indx++) {
        printf("Existencia de %d es %d\n", *(busquedas + indx), busqueda_binaria(arr, sizeof(arr) / sizeof(*(arr)), *(busquedas + indx)));
    }
    
    return 0;
}

int busqueda_binaria(int *arr_original, int tam_arr, int parametro) {
    int inicio, final, medio;
    
    inicio = 0;
    final = tam_arr - 1;

    while(inicio <= final) {
        medio = (final + inicio) / 2;

        if(parametro == *(arr_original + medio))
            return TRUE;
        
        inicio = (parametro < *(arr_original + medio)) ? inicio : medio + 1;
        final = (parametro < *(arr_original + medio)) ? medio - 1 : final;
    }

    return FALSE;
}
