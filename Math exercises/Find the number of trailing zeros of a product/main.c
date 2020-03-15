#include <stdio.h>
#include <stdlib.h>

//Important to note that the product of only 2 and 5 ends in 0
int main() {
    int n = 10;
    int zeroes = 0;
    int p = 5;

    while(n >= p){
        zeroes += n / p;
        p *= 5;
    }

    printf("Number of zeroes at the end of %d! = %d\n",n,zeroes);
    return 0;
}
