#include <iostream>
#include <complex>

using namespace std;

int minNum(int p,int q) {
    return p >= q ? q : p;
}

int nod(int c,int d) {
    if(c==d) {
        return c;
    } else {
        int mina = minNum(c,d);
        return nod(abs(c-d),minNum(c,d));
    }
}

int main() {
    int a,b;
    cin >> a >> b;
    int res = nod(a,b);
    cout << res;
    return 0;
}
