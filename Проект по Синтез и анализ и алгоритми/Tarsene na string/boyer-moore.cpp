#include "main.h"

void proveriZaBoyerMoore(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni,string maxStr,string minStr) {
    int red,kolona,maxProverka,minProverka,namereniSa,redaNaMax,redaNaMin;

    maxProverka = -1;
    minProverka = -1;
    namereniSa = -1;
    redaNaMax = -1;
    redaNaMin = -1;

    //Прилагаме алгоритъма за всеки елемент, проверяваме дали е макс или мин елемент
    for(red=0; red<redove; red++) {
        for(kolona = 0; kolona < koloni; kolona++) {

            //Ако един път сме намерили най-големия стринг няма смисъл отново да го търсим
            if(maxProverka == -1) {
                maxProverka = booyerMoore(matrica[red][kolona],maxStr);
            }

            //Записваме реда на максималния елемент, правим проверка дали вече не сме го записали
            if(maxProverka == 1 && redaNaMax == -1) {
                redaNaMax = red;
            }

            //Ако един път сме намерили най-малкия стринг няма смисъл отново да го търсим
            if(minProverka == -1) {
                minProverka = booyerMoore(matrica[red][kolona],minStr);
            }

            //Записваме реда на минималния елемент, правим проверка дали вече не сме го записали
            if(minProverka == 1 && redaNaMin == -1) {
                redaNaMin = red;
            }

            //Намерили сме и най-големия и най-малкия стринг
            if(maxProverka == 1 && minProverka == 1) {
                namereniSa = 1;
                break;
            }
        }

        //Ако сме намерили редовете на максималния и минималния няма нужда да продължаваме обхождането
        if(namereniSa == 1) {
            break;
        }
    }

    //Разместване на редовете съдърщаши макс и мин елемент
    if(redaNaMax != -1 && redaNaMin != -1) {
        string temp;

        for(kolona = 0; kolona < koloni; kolona++) {
            temp = matrica[redaNaMax][kolona];
            matrica[redaNaMax][kolona] = matrica[redaNaMin][kolona];
            matrica[redaNaMin][kolona] = temp;
        }
    }
}

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

