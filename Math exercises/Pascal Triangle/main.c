#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
const int n = 5;
const int k = 1;
long lastLine[MAXN + 1];

int main() {
    int i,j;

    //first number of line is always 1
    lastLine[0] = 1;

    for(i = 1; i <= n; i++) {
        //last number of line is always 1
        lastLine[i] = 1;

        //start from second to last and go to first
        for(j = i - 1; j >= 1; j--) {
            lastLine[j] += lastLine[j-1];
        }

        for(int p = 0; p <= i; p++) {
            printf("%d ",lastLine[p]);
        }
        printf("\n");
    }
    printf("C(%d,%d) = %d\n",n,k,lastLine[k]);
    return 0;
}
