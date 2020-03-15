#include <stdio.h>
#include <stdlib.h>

//Example 520 = 2^3*5^1*13^1

int main() {
    int n = 520;
    int power,i = 1;
    printf("%d = ",n);

    while(n != 1) {
        i++;
        power = 0;
        while(n % i == 0) {
            power++;
            n = n / i;
        }
        if(power != 0) {
            if(n != 1) {
                printf("%d ^%d*",i,power);
            } else {
                printf("%d ^%d",i,power);
            }
        }
    }

    printf("\n");
    return 0;
}
