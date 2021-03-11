#include <iostream>

using namespace std;

int main() {
    int n,i;
    float factorial;
    cin >> n;
    factorial = 1;

    for(i = 1; i<=n; i++) {
        factorial *=i;
    }

    cout << n << "! = " << factorial << "\n";
    return 0;
}
