#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int apartar_memoria_hipercubo(int *******, size_t, size_t, size_t, size_t, size_t ,size_t);

int main(int argc, char const *argv[]) {
    int a, b, c, d, e, f;
    int ******hipercubo = NULL;

    a = b = c = d = e = f = 2;

    if(apartar_memoria_hipercubo(&hipercubo, a, b, c, d, e, f)) 
        printf("se aparto memoria para el hipercubo");

    return 0;
}

int apartar_memoria_hipercubo(int *******dir_hipercubo, size_t a, size_t b, size_t c, size_t d, size_t e,size_t f) {
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || e <= 0 || f <= 0)
        return FALSE;
    
    *dir_hipercubo = (int ******) malloc(a * b * c * d * e * f * sizeof(int));

    return (*dir_hipercubo != NULL) ? TRUE : FALSE;
}