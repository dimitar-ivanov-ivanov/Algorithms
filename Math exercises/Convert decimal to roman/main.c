#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d",&n);
    printRoman(n);
    return 0;
}

void printRoman(int number) {
    int num[] = {1,4,5,9,10,40,5,90,100,400,500,900,1000};
    char sym[13][3] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;

    char rslt[20];

    while(number>0) {
        int div = number/num[i];
        number = number%num[i];
        while(div--) {
            printf("%s",i,sym[i]);
        }
        i--;
    }
}

