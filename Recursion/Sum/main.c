#include <stdio.h>
#include <stdlib.h>

unsigned long sum(unsigned i);

int main() {
    int n;
    scanf("%d",&n);
    printf("%u! = %lu\n",n,sum(n));

    return 0;
}

unsigned long sum(unsigned i) {
    if(i < 2) {
        return 1;
    }
    return i + sum(i-1);
}
