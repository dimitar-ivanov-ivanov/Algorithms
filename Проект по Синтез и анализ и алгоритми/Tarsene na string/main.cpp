#include "main.h"

int main() {
    int redove,koloni;
    string maxStr,minStr,temp;

    /* Вход на размери на матрицата */
    redove = vavedeteChislo(VAVEDETERED,MIN_DIMENSII,MAX_REDOVE);
    koloni = vavedeteChislo(VAVEDETEKOLONA,MIN_DIMENSII,MAX_KOLONI);

    cin.ignore(1,'\n'); //Игнорираме \n тъй като getline го обхваща

    string matrica[MAX_REDOVE][MAX_KOLONI];
    vhodMatrica(matrica,redove,koloni);

    /* Вход на най-голям елемент */

    maxStr = vavedeteText(VAVEDETEMAXSTRING);
    minStr = vavedeteText(VAVEDETEMINSTRING);

    proveriZaBoyerMoore(matrica,redove,koloni,maxStr,minStr);
    izhodMatrica(matrica,redove,koloni);

    return 0;
}

