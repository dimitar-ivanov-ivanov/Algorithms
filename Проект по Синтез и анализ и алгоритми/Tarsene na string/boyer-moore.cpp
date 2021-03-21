#include "main.h"

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

