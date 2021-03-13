#include <iostream>

using namespace std;

#define REDOVE 50
#define KOLONI 50
#define MAX_SIZE 100
#define NO_OF_CHARS 256


// Предварителна фунцкия за Boyer Moore,маркиране на наличните символи
void markiraneNaNalichie(string str, int size,int badchar[NO_OF_CHARS]) {
    int i;

    // Иниализираме всички символи с -1 за неналичие
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Поставяме индекса
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

/* Търсене на стринг в текст с използване на Boyer Moore алгоритъм */
int booyerMoore(string text, string shablon) {
    int shablonDaljina = shablon.size();
    int textDaljina = text.size();

    int nalichie[NO_OF_CHARS];

    /* Пълним масива с -1 за неналичие и с позиция на символа в шаблона ако има наличие */
    markiraneNaNalichie(shablon, shablonDaljina, nalichie);

    int s = 0;
    while(s <= (textDaljina - shablonDaljina)) {
        int j = shablonDaljina - 1;

        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && shablon[j] == text[s + j])
            j--;

        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0) {
            cout << "pattern occurs at shift = " << s << endl;

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + shablonDaljina < textDaljina)? shablonDaljina-nalichie[text[s + shablonDaljina]] : 1;
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
            s += max(1, j - nalichie[text[s + j]]);
        }
    }

    return -1;
}

int main() {
    int redove,koloni,red,kolona,maxProverka,minProverka,namereniSa,redaNaMax,redaNaMin;
    string maxStr,minStr;

    cout << "Vavedete redovete na matricata: \n";
    cin >> redove;

    cout << "Vavedete kolonite na matricata: \n";
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
    cout << "Vavedete nai-golemiq element"  << endl;
    getline(cin, maxStr);

    /* Вход на най-малък елемент */
    cout << "Vavedete nai-malkiq element" << endl;
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

    //TODO: Разместване на редовете съдърщаши макс и мин елемент

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
