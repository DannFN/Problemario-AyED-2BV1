#include <stdio.h>
#include <stdlib.h>

void arbolDoble(int N, int nivel);
void arbolTriple(int N, int nivel);

int main(int argc, char *argv[]) {
    int N = 64, nivel = 0;
    
    arbolDoble(N, nivel);
    arbolTriple(N, nivel);
    
    return 0;
}

void arbolDoble(int N, int nivel) {
    int k = 0;
    
    if(N <= 0)
        return;
    
    printf("nivel = %d, N = %d\n", nivel, N);
    
    arbolDoble(N / 2, nivel + 1);
    arbolDoble(N / 2, nivel + 1);
}

void arbolTriple(int N, int nivel) {
    int k = 0;
    
    if (N <= 0)
        return;
    
    printf("nivel = %d, N = %d\n", nivel, N);
    
    arbolTriple(N / 3, nivel + 1);
    arbolTriple(N / 3, nivel + 1);
    arbolTriple(N / 3, nivel + 1);
}