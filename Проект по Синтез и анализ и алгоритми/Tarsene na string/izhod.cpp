#include "main.h"

void izhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni) {
//Принтиране на матрицата
    for(int red=0; red<redove; red++) {
        cout << "Red " << red + 1 << " : ";
        for(int kolona = 0; kolona < koloni; kolona++) {
            if(kolona == koloni - 1) {
                cout << matrica[red][kolona] << endl;
            } else {
                cout << matrica[red][kolona] + ", ";
            }
        }
    }
}
