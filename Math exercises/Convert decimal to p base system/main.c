#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main() {
    char rslt[SIZE];
    unsigned char base = 16;
    unsigned long n = 10;

    convert(&rslt,n,base);

    printf("%s",rslt);
    return 0;
}

char getChar(char n) {
    return (n < 10) ? n + '0' : n + 'A' - 10;
}

void reverse(char *pch) {
    for(char *pEnd = pch + strlen(pch) - 1; pch  < pEnd; pch++, pEnd--) {
        char c = *pch;
        *pch = *pEnd;
        *pEnd = c;
    }
}

void convert(char *rslt,unsigned long n,unsigned char base) {
    char *saveRslt = rslt;
    while(n > 0) {
        *rslt++ = getChar((char)(n%base));
        n /= base;
    }
    *rslt = '\0';
    reverse(saveRslt);
}
