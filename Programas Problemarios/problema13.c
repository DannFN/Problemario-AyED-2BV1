#include <stdio.h>
#include <stdlib.h>

typedef long long llong;

llong factorial_rec(llong);

int main(int argc, char const *argv[]) {
    int n = 13;

    printf("%lld", factorial_rec(n));

    return 0;
}

llong factorial_rec(llong n) {
    if (n <= 1)
        return 1;
    
    return n * factorial_rec(n - 1);
}
