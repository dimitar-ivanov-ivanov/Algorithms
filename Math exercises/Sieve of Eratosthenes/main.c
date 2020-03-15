#include <stdio.h>
#include <stdlib.h>

#define MAXN 3000

const int n = 7;
int sieve[MAXN];

void eratosten(int n);

int main() {
    int i;
    for(i = 0; i< n; i++) {
        sieve[i] = 0;
        eratosten(n);
    }
    return 0;
}

//one number is primer if it doesnt have prime quiotient
//if sieve[i] is 1 then that number isn't prime
//when we start we assume that it is prime

void eratosten(int n) {
    int j, i = 2;

    while(i <= n) {
        if(sieve[i] == 0) {
            printf("%d",i);
            j = i * i;
            while(j <= n){
                sieve[j] = 1;
                j+= i;
            }
        }
        i++;
    }
}
