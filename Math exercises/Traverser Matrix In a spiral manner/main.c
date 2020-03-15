#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int sum = 1;
    int flag = 1;
    int topRow = 0;
    int topCol = 0;
    int bottomRow = n - 1;
    int bottomCol = n -1;
    int currentRow = 0;
    int currentCol = 0;
    int a[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }

    //flag 1 -> go down
    //flag 2 -> go right
    //flag 3 -> go up
    //flag 4 -> go left
    while(1) {
        a[currentRow][currentCol] = sum++;
        printf("%d %d %d\n",currentRow,currentCol,a[currentRow][currentCol]);
        if(flag == 1) {
            if(currentRow == bottomRow) {
                flag = 2;
            } else {
                currentRow++;
            }
        }
        if(flag == 2) {
            if(currentCol == bottomCol) {
                flag = 3;
            } else {
                currentCol++;
            }
        }
        if(flag == 3) {
            if(currentRow == topRow) {
                flag = 4;
            } else {
                currentRow--;
            }
        }

        //we have gone back to the start of th spiral -> reset the top and bottom rows to make spiral smaller
        //reset back to flag 1 to set the movement on the rigth track
        if(flag == 4) {
            if(currentCol - 1 == topCol) {
                flag = 1;
                topCol++;
                topRow++;
                bottomCol--;
                bottomRow--;
                currentRow++;

                //one cell left fill it and leave
                if(topRow == bottomRow && topCol == bottomCol) {
                    a[topRow][topCol] = sum;
                    break;
                }
            } else {
                currentCol--;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
