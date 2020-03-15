#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    scanf("%d",&n);
    if(isPrimeWilson(n)) {
        printf("Number %d is prime",n);
    } else {
        printf("Number %d is not prime",n);
    }

    return 0;
}

int isPrime(int n) {
    //returns 1 for prime
    int i = 2;
    if(n <= 0) {
        return 0;
    }
    if(n == 2)
        return 1;

    while(i <= sqrt(n)) {
        if(n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}


int isPrimeWilson(int n) {
    int factorial = 1;
    for(int i = 1; i <= n -1 ; i++) {
        factorial *= i;
    }
    return factorial == - 1 * abs(n);
}
