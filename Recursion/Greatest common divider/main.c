#include <stdio.h>
#include <stdlib.h>

unsigned gcd(unsigned a,unsigned b);

int main() {
/*iterative
    unsigned swap;
    while(b > 0) {
        swap = b;
        b = a % b;
        a = swap;
    }
    */
    unsigned c = gcd(100,15);
    printf("%d",c);
    return 0;
}

unsigned gcd(unsigned a,unsigned b) {
    return (b == 0) ? a : gcd(b,a % b);
}
