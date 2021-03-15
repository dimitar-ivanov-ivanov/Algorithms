#include <iostream>

using namespace std;

#define NO_OF_CHARS 256

// Предварителна фунцкия за Boyer Moore,маркиране на наличните символи
void markiraneNaNalichie(string str, int size,int nalichie[NO_OF_CHARS]) {
    int i;

    // Иниализираме всички символи с -1 за неналичие
    for (i = 0; i < NO_OF_CHARS; i++)
        nalichie[i] = -1;

    // Поставяме индекса
    for (i = 0; i < size; i++)
        nalichie[(int) str[i]] = i;
}

/* Търсене на стринг в текст с използване на Boyer Moore алгоритъм */
int booyerMoore(string text, string shablon) {
    int shablonDaljina = shablon.size();
    int textDaljina = text.size();

    int nalichie[NO_OF_CHARS];

    /* Пълним масива с -1 за неналичие и с позиция на символа в шаблона ако има наличие */
    markiraneNaNalichie(shablon, shablonDaljina, nalichie);

    /* Индекс за показване докъде сме стигнали в текста*/
    int indexText = 0;
    while(indexText <= (textDaljina - shablonDaljina)) {
        int j = shablonDaljina - 1;

        /* Намаляваме j докато текста и шаблона са еднакви */
        while(j >= 0 && shablon[j] == text[indexText + j])
            j--;

        /* Ако текста съдържа шаблона тогава j ще стане -1*/
        if (j < 0) {

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            indexText += (indexText + shablonDaljina < textDaljina)?
                         shablonDaljina-nalichie[text[indexText + shablonDaljina]]
                         : 1;
            return 1;
        } else {
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            indexText += max(1, j - nalichie[text[indexText + j]]);
        }
    }

    return -1;
}

int main() {
    int redove,koloni,red,kolona,maxProverka,minProverka,namereniSa,redaNaMax,redaNaMin;
    string maxStr,minStr,temp;

    cout << "Vavedete redovete na matricata: ";
    cin >> redove;

    cout << "Vavedete kolonite na matricata: ";
    cin >> koloni;
    cin.ignore(1,'\n'); //Игнорираме \n тъй като getline го обхваща

    string matrica[redove][koloni];

    //Въвеждане на матрицата
    for( red=0; red<redove; red++) {
        for( kolona = 0; kolona < koloni; kolona++) {
            cout << "Vavedete stoinost za kletka (" << red << "," << kolona <<") : ";
            getline(cin,matrica[red][kolona]);
        }
    }

    /* Вход на най-голям елемент */
    cout << "Vavedete nai-golemiq element: ";
    getline(cin, maxStr);

    /* Вход на най-малък елемент */
    cout << "Vavedete nai-malkiq element: ";
    getline (cin, minStr);

    //Прилагаме алгоритъма за всеки елемент, проверяваме дали е макс или мин елемент
    maxProverka = -1;
    minProverka = -1;
    namereniSa = -1;
    redaNaMax = -1;
    redaNaMin = -1;

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
    if(redaNaMax != -1 && redaNaMin != -1){
        string temp;

        for(kolona = 0; kolona < koloni; kolona++){
          temp = matrica[redaNaMax][kolona];
          matrica[redaNaMax][kolona] = matrica[redaNaMin][kolona];
          matrica[redaNaMin][kolona] = temp;
        }
    }

    //Принтиране на матрицата
    for(red=0; red<redove; red++) {
        cout << "Red " << red + 1 << " : ";
        for(kolona = 0; kolona < koloni; kolona++) {
            if(kolona == koloni - 1) {
                cout << matrica[red][kolona] << endl;
            } else {
                cout << matrica[red][kolona] + ", ";
            }
        }
    }

    return 0;
}
