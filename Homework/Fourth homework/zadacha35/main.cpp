#include <iostream>

using namespace std;

void diskMove(int n,char a,char b) {
    cout << n << a << b << endl;
}

void hanoy(char a,char c,char b,int numb) {
    if(numb == 1) {
        diskMove(numb,a,c);
    } else {
        hanoy(a,b,c,numb-1);
        diskMove(numb,a,c);
        hanoy(b,c,a,numb-1);
    }
}

int main() {
    int n;
    cin >> n;
    hanoy('A','C','B',n);
    return 0;
}
