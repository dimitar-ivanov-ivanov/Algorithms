#include "main.h"

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

/* ������� �� ������ � ����� � ���������� �� Boyer Moore ��������� */
int booyerMoore(string text, string shablon) {
    int shablonDaljina = shablon.size();
    int textDaljina = text.size();

    /* ����������� �� ��������� ����� 2-�� ������� ������ �������
       �� ������ ��� ����� ����� ����� ������� ������� �������.
       � ���� ������ ������ �� ������� ���������������� �� ����������� � ���������� �������
    */
    if(shablonDaljina != textDaljina){
        return -1;
    }

    int nalichie[NO_OF_CHARS];

    /* ������ ������ � -1 �� ��������� � � ������� �� ������� � ������� ��� ��� ������� */
    markiraneNaNalichie(shablon, shablonDaljina, nalichie);

    /* ������ �� ��������� ������ ��� �������� � ������*/
    int indexText = 0;
    while(indexText <= (textDaljina - shablonDaljina)) {
        int j = shablonDaljina - 1;

        /* ���������� j ������ ������ � ������� �� ������� */
        while(j >= 0 && shablon[j] == text[indexText + j]) {
            j--;
        }

        /* ��� ������ ������� ������� ������ j �� ����� -1*/
        if (j < 0) {
            /* ������� � ������� ������� 1 �� �� ��������� */
            return 1;
        } else {
            /* ������ ������� ������� ����� ������ ������� � ���������
              �� ������� �� ������ ������ ��� ����� �����������
              �� ������ �� ������� �� �������.
              ���� ������� � ������� �� �� �������� ����������� ������� � ������.*/
            indexText += max(1, j - nalichie[text[indexText + j]]);
        }
    }

    return -1;
}

// ������������� ������� �� Boyer Moore,��������� �� ��������� �������
void markiraneNaNalichie(string str, int size,int nalichie[NO_OF_CHARS]) {
    int i;

    // ������������ ������ ������� � -1 �� ���������
    for (i = 0; i < NO_OF_CHARS; i++)
        nalichie[i] = -1;

    /* ��������� ������� �� �� ��������� �������
       ��� ����� 2 ������� ������� �� �� ���������
    */
    for (i = 0; i < size; i++) {
        nalichie[(int) str[i]] = i;
    }
}

