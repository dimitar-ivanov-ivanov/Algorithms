#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const unsigned long n = 123;

int main() {

    double digits = 0;
    unsigned i;
    for(int i = 1; i <= n; i++) {
            digits += log10(i);
    }

    printf("Number of digits of %lu! is %lu\n",(unsigned long)digits + 1);

    return 0;
}
