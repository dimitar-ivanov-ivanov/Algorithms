#include <iostream>

using namespace std;

int main() {

    int a,b,c,maxNum;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    if(a > b) {
        maxNum = a;
    } else {
        maxNum = b;
    }

    if(c>maxNum) {
        maxNum = c;
    }

    cout << "max = " << max << "\n";
    return 0;
}
