#include <iostream>

using namespace std;

bool findDigit(int n,int digitToFind) {

    if(n == 0) {
        return false;
    }

    int currentDigit = n % 10;
    if(currentDigit == digitToFind) {
        return true;
    }
    return findDigit(n / 10,digitToFind);
}

int main() {
    int n = 254;
    bool findDigitFalse =  findDigit(n,8);
    bool findDigitTrue =  findDigit(n,2);
    cout << findDigitFalse << endl;
    cout << findDigitTrue << endl;
    return 0;
}
