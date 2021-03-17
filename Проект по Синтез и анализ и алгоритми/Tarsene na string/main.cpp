#include "main.h"

int main() {
    int redove,koloni;
    string maxStr,minStr,temp;

    /* ���� �� ������� �� ��������� */
    redove = vavedeteChislo(VAVEDETERED);
    koloni = vavedeteChislo(VAVEDETEKOLONA);

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

