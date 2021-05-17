#include <stdio.h>

int main(int argc, char *argv[]) {
    int *u = NULL, *v = NULL, *w = NULL, *q = NULL;
    int a = 101, b= 201, c= 301;

    u = &c;                 // u = #C003
    v = &b;                 // V = #B002
    w = &a;                 // W = #A001

    (*w) += a + b + c;      // a = 302
    (*u)++;                 // c = 804
    (*v) *= 4;              // b = 704

    q = w;                  // q = #A001
    w = u;                  // w = #C003
    u = v;                  // u = #B002
    v = q;                  // v = #A001

    (*u) -= (*q) % 5 - a;   // b = 1504
    (*v) -= (*q) % 3 - b;   // a = 2206
    (*w) -= (*q) % 2 - c;   // c = 604

    printf("a = %d b = %d c = %d\n", a, b, c);

    return 0;
}