#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 16;
    int digits[] = {7,3,-7,3,7,-3,-7,-3,3,7,-3,7,3,-7,-3,-7};

    for(int i = 0,j = 1; i < n-1;i++,j++) {
        printf("%d %d\n",digits[i] / digits[j],digits[i] % digits[j]);
    }
    return 0;
}
