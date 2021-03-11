#include <iostream>

using namespace std;

int main() {
    int n,prevX,currentX;
    n = 1;
    prevX = 2;
    currentX = 0;

    while(true) {
        currentX = 2 * prevX + 10;
        if(currentX > 100) {
            cout << "n = " << n;
            return 0;
        }
        prevX = currentX;
        n++;
    }

    return 0;
}
