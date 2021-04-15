#include <iostream>

using namespace std;

int factorial(int n) {
    if(n <= 1) {
        return 1;
    }
    return n*factorial(n-1);
}

int main() {
    int n;
    cin >> n;
    int res = factorial(n);
    cout << res;
    return 0;
}
