#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 2;
    int m = 3;
    int p = 3;
    int i,j,k;

    int A[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int B[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int C[2][3];

    for(i = 0; i < n; i++) {
        for(j = 0; j < p; j++) {
            C[i][j] = 0;
            for(k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < p; j++) {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }


    return 0;
}
