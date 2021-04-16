#include <iostream>

using namespace std;

const int br= 6;
int moneti[br] = {50,20,10,5,2,1};

void stotinki(int suma) {
    int i,j;
    j = suma;
    for(i = 0; i < br && j > 0; i++) {
        cout << moneti[i] << " -> " << j /moneti[i] << endl;
        j %= moneti[i];
    }
}

int main() {

    int sum;
    cin >> sum;
    stotinki(sum);
    return 0;
}
