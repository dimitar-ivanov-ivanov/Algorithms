#include "main.h"

/* Търсене на стринг в текст с използване на Boyer Moore алгоритъм */
int booyerMoore(string text, string shablon) {
    int shablonDaljina = shablon.size();
    int textDaljina = text.size();

    /* Проверяваме за равенство между 2-те дължини защото шаблона
       ще отчета ако имаме текст който вътрешн съдържа шаблона.
       В този случай грешно че отчетем местоположението на максималния и минималния елемент
    */
    if(shablonDaljina != textDaljina){
        return -1;
    }

    int nalichie[NO_OF_CHARS];

    /* Пълним масива с -1 за неналичие и с позиция на символа в шаблона ако има наличие */
    markiraneNaNalichie(shablon, shablonDaljina, nalichie);

    /* Индекс за показване докъде сме стигнали в текста*/
    int indexText = 0;
    while(indexText <= (textDaljina - shablonDaljina)) {
        int j = shablonDaljina - 1;

        /* Намаляваме j докато текста и шаблона са еднакви */
        while(j >= 0 && shablon[j] == text[indexText + j]) {
            j--;
        }

        /* Ако текста съдържа шаблона тогава j ще стане -1*/
        if (j < 0) {
            /* Шаблона е намерен връщаме 1 за да потвърдим */
            return 1;
        } else {
            /* Местим шаблона толкова знака напред колкото е наличието
              на символа от текста където сме имали неравенство
              от масива за наличие на символи.
              Макс функция е сложена за да осигурен преместване надясно в текста.*/
            indexText += max(1, j - nalichie[text[indexText + j]]);
        }
    }

    return -1;
}

// Предварителна фунцкия за Boyer Moore,маркиране на наличните символи
void markiraneNaNalichie(string str, int size,int nalichie[NO_OF_CHARS]) {
    int i;

    // Иниализираме всички символи с -1 за неналичие
    for (i = 0; i < NO_OF_CHARS; i++)
        nalichie[i] = -1;

    /* Поставяме индекса за да потвърдим наличие
       Ако имаме 2 еднакви символа ще се пренапише
    */
    for (i = 0; i < size; i++) {
        nalichie[(int) str[i]] = i;
    }
}

