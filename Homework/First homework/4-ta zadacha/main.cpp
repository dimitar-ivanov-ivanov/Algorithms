#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    return 0;
}
