#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 100

int main() {
    char rslt[SIZE];
    unsigned char base = 2;
    double n = -0.2;

    convertReal(&rslt,n,base,5);
    printf("%s",rslt);
    return 0;
}

void convertReal(char *rslt,double n,unsigned char base,unsigned char cnt) {
    //Convert real number to p base number system
    double integer, fraction;

    //Find if it is signed
    if(n < 0) {
        *rslt++ = '-';
        n = -n;
    }

    //Break down the integer part and the fraction part
    fraction = modf(n,&integer);

    //Convert the integer part
    convert(rslt,(unsigned long)integer,base);

    //Put the '.'
    if(*rslt == '\0') {
        *rslt++ = '\0';
    } else {
        *rslt += strlen(rslt);
    }
    *rslt++ = '.';


//Convert the fraction
    convertLessThan1(rslt,fraction,base,cnt);
    if(*rslt == '\0') {
        *rslt++ ='\0';
        *rslt = '\0';
    }
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

void convertLessThan1(char *rslt,
                      double n,
                      unsigned char base,
                      unsigned char cnt) {

    double EPS = 0.01;
    while (cnt--) {
        /* Дали не сме получили 0? */
        if (fabs(n) < EPS)
            break;
        /* Получаване на следващата цифра */
        n *= base;
        *rslt++ = getChar((char)(int)floor(n));
        n -= floor(n);
    }
    *rslt = '\0';
}
