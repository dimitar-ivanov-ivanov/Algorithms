#include "main.h"

void vhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni) {
    //Въвеждане на матрицата
    for(int red=0; red<redove; red++) {
        for(int kolona = 0; kolona < koloni; kolona++) {
            char str[39];
            sprintf(str,VAVEDETESTOINOSTZAKLETKA, red,kolona);
            matrica[red][kolona] = vavedeteText(str);
        }
    }
}

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

string vavedeteText(string saobshtenie) {
    string str;
    cout << saobshtenie;
    getline(cin,str);

    while(str.empty()) {
        cout << VAVEDENIQTEXTEPRAZEN << endl;
        cout << saobshtenie;
        getline(cin,str);
    }

    return str;
}
