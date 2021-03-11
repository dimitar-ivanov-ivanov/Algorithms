#include <stdio.h>
#include <stdlib.h>

int totalSolutions = 0;
int placedQueen = 0;

void placeQueens(int n,int chessboard[n][n]);
void markQueensTerritory(int row,int col,int mark,int n,int chessboard[n][n]);
void printChessboard(int n,int chessboard[n][n]);

int main() {
    int n = 8;
    int chessboard[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //0 -> no queen 1 -> queen
            chessboard[i][j] = 0;
        }
    }

    placeQueens(n,chessboard);
    printf("%d",totalSolutions);
    return 0;
}

void placeQueens(int n,int chessboard[n][n]) {
    //find place to place queen
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //no queen here place one
            if(chessboard[i][j] == 0) {
                placedQueen++;
                markQueensTerritory(i,j,1,n,chessboard);
                placeQueens(n,chessboard);
                //go back but unmark the marked cells
                markQueensTerritory(i,j,0,n,chessboard);

            }
        }
    }
}

void markQueensTerritory(int row,int col,int mark,int n,int chessboard[n][n]) {
    //mark row and col
    for(int i = 0; i < n; i++) {
        chessboard[row][i] = 1;
        chessboard[i][col] = 1;
    }

    //mark diagonals above queen
    for(int i = row,j = 0; i >= 0; i--,j++) {
        if(col - j >=0) {
            chessboard[i][col - j] = 1;
        }
        if(col + j < n) {
            chessboard[i][col + j] = 1;
        }
    }

    //mark diagonals under queen
    for(int i = row,j = 0; i < n; i++,j++) {
        if(col - j >=0) {
            chessboard[i][col - j] = 1;
        }
        if(col + j < n) {
            chessboard[i][col + j] = 1;
        }
    }
}

void printChessboard(int n,int chessboard[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",chessboard[i][j]);
        }
        printf("\n");
    }
}
