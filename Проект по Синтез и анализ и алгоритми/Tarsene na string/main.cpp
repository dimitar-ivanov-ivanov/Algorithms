#include "main.h"

/* Входна фунцкия на рограмата */
int main() {
    int redove,koloni;
    string maxStr,minStr,temp;

    /* Вход на размери на матрицата */
    redove = vavedeteChislo(VAVEDETERED,MIN_DIMENSII,MAX_REDOVE);
    koloni = vavedeteChislo(VAVEDETEKOLONA,MIN_DIMENSII,MAX_KOLONI);

    cin.ignore(1,'\n'); //Игнорираме \n тъй като getline го обхваща

    /* Вход на матрица */
    string matrica[MAX_REDOVE][MAX_KOLONI];
    vhodMatrica(matrica,redove,koloni);

    /* Вход на най-голям и най-малък елемент */
    maxStr = vavedeteText(VAVEDETEMAXSTRING);
    minStr = vavedeteText(VAVEDETEMINSTRING);

    /* Проверка за макс и мин чрез прилагане на алгоритма за всеки елемент */
    proveriZaBoyerMoore(matrica,redove,koloni,maxStr,minStr);

    /* Изход на матрицата */
    izhodMatrica(matrica,redove,koloni);
    return 0;
}

