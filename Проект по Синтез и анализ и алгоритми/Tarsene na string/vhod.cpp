#include "main.h"

void vhodMatrica(string matrica[MAX_REDOVE][MAX_KOLONI],int redove,int koloni) {
    //Въвеждане на матрицата
    for(int red=0; red<redove; red++) {
        for(int kolona = 0; kolona < koloni; kolona++) {
            //matrica[red][kolona] = vavedeteText("Vavedete stoinost za kletka (" << red << "," << kolona <<") : ");
            cout << "Vavedete stoinost za kletka (" << red << "," << kolona <<") : ";
            getline(cin,matrica[red][kolona]);
        }
    }
}

int vavedeteChislo(string saobshtenie) {
    int num;
    cout << saobshtenie;
    cin >> num;
    return num;
}

string vavedeteText(string saobshtenie) {
    string str;
    cout << saobshtenie;
    getline(cin,str);
    return str;
}
