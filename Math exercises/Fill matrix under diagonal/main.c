#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int n,int a[n][n]);
void printMatrix(int n,int a[n][n]);

int main() {
    int n = 5;
    int a[5][5];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    int sum = 1;

    for(int j = 0; j < n; j++) {
        for(int i = 1 + j; i < n; i++) {
            a[i][j] = sum++;
        }
    }

    for(int j = n-1; j >= 0; j--) {
        for(int i = j - 1; i >= 0; i--) {
            a[i][j] = sum++;

        }
    }

    printMatrix(n,a);

    return 0;
}

void fillMatrix(int n,int a[n][n]) {
    int sum = 1;

    for(int j = 0; j < n; j++) {
        for(int i = 1 + j; i < n; i++) {
            a[i][j] = sum++;
        }
    }

}

void printMatrix(int n,int a[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
