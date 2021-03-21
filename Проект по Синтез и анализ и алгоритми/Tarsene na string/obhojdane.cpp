#include "main.h"

/* Обхождаме всички елементи в матрица и при намиране на макс и мин приключваме обхождане и разместваме тяхните редове */
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
