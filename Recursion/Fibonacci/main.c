#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int arr[SIZE];
unsigned long fib(unsigned n);

int main() {
    int n;
    scanf("%d",&n);

    for(int i = 0; i < SIZE; i++) {
        arr[i] = 0;
    }

    printf("%lu",fib(n));
    return 0;
}

unsigned long fib(unsigned n) {
    if(n < 2)
        return 1;
    if(arr[n] != 0) {
        return arr[n];
    }
    return arr[n] =  fib(n-1) + fib(n-2);
}
