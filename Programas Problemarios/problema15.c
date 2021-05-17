#include <stdio.h>
#include <stdlib.h>

void arbolBinario(int nivel, int nodo, int limite, int *cont);
void arbolBaseB(int nivel, int nodo, int limite, int base, int*cont);

void main() {
    int N = 0, n = 0, lim = 4, base = 3;
    int conteo = 0;
    
    arbolBinario(N, n, lim, &conteo);
    printf("conteo arbol binario = %d\n", conteo);
    
    conteo = 0;
    
    arbolBaseB(N, n, lim, base, &conteo);
    printf("conteo arbol base %d = %d\n", base, conteo);
}

void arbolBinario(int nivel, int nodo, int limite, int *cont) {
    int k = 0;
    if (nivel >= limite)
        return;
    
    for (k = 0; k < nivel; k++)
        printf("\t"); 
    
    (*cont)++;
    
    printf("nivel = %d, nodo = %d\n", nivel, nodo);
    
    arbolBinario(nivel + 1, 2 * nodo + 0, limite, cont);
    arbolBinario(nivel + 1, 2 * nodo + 1, limite, cont);
}

void arbolBaseB(int nivel, int nodo, int limite, int base, int *cont) {
    int k = 0;
    if (nivel >= limite)
        return;

    (*cont)++;

    for (k = 0; k < nivel; k++)
        printf("\t"); 

    printf("nivel = %d, nodo = %d\n", nivel, nodo);
    
    for (k = 0; k < base; k++)
        arbolBaseB(nivel + 1, base * nodo + k, limite, base, cont);
}
