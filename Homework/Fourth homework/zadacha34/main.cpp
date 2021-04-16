#include <iostream>
#include <complex>

using namespace std;

int minNum(int a,int b) {
    return a >= b ? b : a;
}

int nod(int a,int b) {
    if(a == b) {
        return a;
    } else {
        return nod(abs(a-b),minNum(a,b));
    }
}

int main() {
    int a,b;
    cin >> a >> b;
    int res = nod(a,b);
    cout << res;
    return 0;
}
