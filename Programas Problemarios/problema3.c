#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int **q = NULL, *p = NULL;
    int *a = NULL, *b = NULL, *x = NULL, *y = NULL;
    int N = 10, k = 0;
    
    // suponinendo que a = #A001 y b = #B002 y que &a = #AA01 y b = #BB01
    a = (int *) malloc(N * sizeof(int));    // a = #A001
    b = (int *) malloc(N * sizeof(int));    // b = #B002

    /*
     * Al iniciar el ciclo for y despues del primer ciclo
     * x = a = #A001
     * y = b = #B002
     * a = [0 , , , , , , , , , ]
     * b = [0 , , , , , , , , , ] 
     */

    for (x = a, y = b, k = 0;  k < N;  k++,  x++,  y++) {
        (*x) = 2 * k;                                   
        (*y) = 3 * k;
    }

    /* 
     * Con cada iteracion x y y saltan al siguiente espacio de memoria entero en los
     * respectivos arreglos a los que apuntan
     * 
     * Al finalizar el ciclo k < N (ultimo cliclo)
     * x = a + ((N - 1) * sizeof(int)) = #A001 + 9 espacios de memoria (saltos de 2 o 4 bytes)
     * y = b + ((N - 1) * sizeof(int)) = #B002 + 9 espacios de memoria (saltos de 2 o 4 bytes)
     * a = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
     * b = [0, 3, 6, 9, 12, 15, 18, 21, 24, 27]
     */

    /*
     * Al iniciar el ciclo for y despues del primer ciclo
     * q = #AA01
     * p = a + (k * sizeof(int)) = #A001 + 1 espacio de memoria (saltos de 2 o 4 bytes)
     * a = [0, 2, 4, 6, 8, 10, 12, 14, 16, 18]
     * b = [0, 3, 6, 9, 12, 15, 18, 21, 24, 27]
     */

    for (k = 0; k < N; k++) {
        if (k % 2 == 0)
            q = &a;
        else
            q = &b; 

        p = *q;
        p = p + k;
        (*p) *= -1;
        (**q) += *p;
    }

    /*
     * Con cada iteracion q cambia de arreglo y p hace que avance k lugares
     * en ese arreglo para operar con el elemento en a/b[k].
     * La ultima instruccion opera sumandole a el primer elemento de a o b
     * el valor actual que tenga el espacio de memoria al que apunta p (a/b[k])
     * 
     * Al finalizar
     * q = #BB02 
     * p = b + ((N - 1) * sizeof(int)) = #B002 + 9 espacios de memoria (saltos de 2 o 4 bytes)
     * **q = *b, q = #B002, *p = -27 => **q = -75,
     * a = [-40, 2, -4, 6, -8, 10, -12, 14, -16, 18]
     * b = [-75, -3, 6, -9, 12, -15, 18, -21, 24, -27]
     */

    printf("\n");

    for (k = 0; k < N; k++)
        printf("%X :: a[%d] = %d\n", &(a[k]), k, a[k]);
    
    printf("\n");
    
    for (k = 0; k < N; k++)
        printf("%X :: b[%d] = %d\n", &(b[k]), k, b[k]);
    
    free(a);
    free(b);
    
    return 0;
}