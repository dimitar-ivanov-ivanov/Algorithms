#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long calculate(char *numb,unsigned char base);

int main() {
    unsigned char base = 16;
    char numb[100];
    strcpy(numb,"A");
    unsigned long res =  calculate(&numb,base);
    printf("%lu",res);
    return 0;
}

char getValue(char c) {
    return (c >='0' && c <= '9') ? c - '0' : c - 'A' + 10;
}

unsigned long calculate(char *numb,unsigned char base) {
    unsigned long result;
    for(result = 0; *numb != '\0'; numb++) {
        result = result * base + getValue(*numb);
    }
    return result;
}
