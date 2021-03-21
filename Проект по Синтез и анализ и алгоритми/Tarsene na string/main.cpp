#include "main.h"

int main() {
    int redove,koloni;
    string maxStr,minStr,temp;

    /* ���� �� ������� �� ��������� */
    redove = vavedeteChislo(VAVEDETERED,MIN_DIMENSII,MAX_REDOVE);
    koloni = vavedeteChislo(VAVEDETEKOLONA,MIN_DIMENSII,MAX_KOLONI);

    cin.ignore(1,'\n'); //���������� \n ��� ���� getline �� �������

    string matrica[MAX_REDOVE][MAX_KOLONI];
    vhodMatrica(matrica,redove,koloni);

    /* ���� �� ���-����� ������� */

    maxStr = vavedeteText(VAVEDETEMAXSTRING);
    minStr = vavedeteText(VAVEDETEMINSTRING);

    proveriZaBoyerMoore(matrica,redove,koloni,maxStr,minStr);
    izhodMatrica(matrica,redove,koloni);

    return 0;
}

