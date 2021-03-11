#include <stdio.h>
#include <stdlib.h>

unsigned long factorial(unsigned i);

int main() {
    int n;
    scanf("%d",&n);
    printf("%u! = %lu\n",n,factorial(n));

    return 0;
}

unsigned long factorial(unsigned i) {
    if(i < 2) {
        return 1;
    }
    return i * factorial(i-1);
}
