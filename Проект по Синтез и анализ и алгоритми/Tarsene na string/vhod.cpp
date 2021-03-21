#include "main.h"

/* Въвеждане на матрицата чрез готовата фунцкия имплементирана по-надолу */
void vhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni) {
    for(int red=0; red<redove; red++) {
        for(int kolona = 0; kolona < koloni; kolona++) {
            char str[39];
            sprintf(str,VAVEDETESTOINOSTZAKLETKA, red,kolona);
            matrica[red][kolona] = vavedeteText(str);
        }
    }
}

/* Въвеждаме число и валидираме дали е в подадените граници */
int vavedeteChislo(string saobshtenie,int minGranica,int maxGranica) {
    int num;

    cout << saobshtenie;
    cin >> num;

    while(num < minGranica || num > maxGranica) {
        if(num < minGranica) {
            cout << VAVEDENOCHISLONEMALKO << minGranica << endl;
        }
        if(num > maxGranica) {
            cout << VAVEDENOCHISLOGOLQMO << maxGranica << endl;
        }
        cout << saobshtenie;
        cin >> num;
    }

    return num;
}

/* Въвеждаме текст и валидираме дали не е празен */
string vavedeteText(string saobshtenie) {
    string str;
    cout << saobshtenie;
    getline(cin,str);

    while(str.length() == 0) {
        cout << VAVEDENIQTEXTEPRAZEN << endl;
        cout << saobshtenie;
        getline(cin,str);
    }

    return str;
}
