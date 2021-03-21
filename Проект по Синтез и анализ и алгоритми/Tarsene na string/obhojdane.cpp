#include "main.h"

/* ��������� ������ �������� � ������� � ��� �������� �� ���� � ��� ����������� ��������� � ����������� ������� ������ */
void proveriZaBoyerMoore(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni,string maxStr,string minStr) {
    int red,kolona,maxProverka,minProverka,namereniSa,redaNaMax,redaNaMin;

    maxProverka = -1;
    minProverka = -1;
    namereniSa = -1;
    redaNaMax = -1;
    redaNaMin = -1;

    //��������� ���������� �� ����� �������, ����������� ���� � ���� ��� ��� �������
    for(red=0; red<redove; red++) {
        for(kolona = 0; kolona < koloni; kolona++) {

            //��� ���� ��� ��� �������� ���-������� ������ ���� ������ ������ �� �� ������
            if(maxProverka == -1) {
                maxProverka = booyerMoore(matrica[red][kolona],maxStr);
            }

            //��������� ���� �� ����������� �������, ������ �������� ���� ���� �� ��� �� ��������
            if(maxProverka == 1 && redaNaMax == -1) {
                redaNaMax = red;
            }

            //��� ���� ��� ��� �������� ���-������ ������ ���� ������ ������ �� �� ������
            if(minProverka == -1) {
                minProverka = booyerMoore(matrica[red][kolona],minStr);
            }

            //��������� ���� �� ���������� �������, ������ �������� ���� ���� �� ��� �� ��������
            if(minProverka == 1 && redaNaMin == -1) {
                redaNaMin = red;
            }

            //�������� ��� � ���-������� � ���-������ ������
            if(maxProverka == 1 && minProverka == 1) {
                namereniSa = 1;
                break;
            }
        }

        //��� ��� �������� �������� �� ����������� � ���������� ���� ����� �� ������������ �����������
        if(namereniSa == 1) {
            break;
        }
    }

    //����������� �� �������� ��������� ���� � ��� �������
    if(redaNaMax != -1 && redaNaMin != -1) {
        string temp;

        for(kolona = 0; kolona < koloni; kolona++) {
            temp = matrica[redaNaMax][kolona];
            matrica[redaNaMax][kolona] = matrica[redaNaMin][kolona];
            matrica[redaNaMin][kolona] = temp;
        }
    }
}
