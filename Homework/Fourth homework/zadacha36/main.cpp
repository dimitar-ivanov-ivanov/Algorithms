#include <iostream>

using namespace std;

int countFib(int n,int fib[]) {
    if(n < 2) {
        return fib[n] = n;
    } else {
        return fib[n] = countFib(n-1,fib) + countFib(n-2,fib);
    }
}

int main() {

    int n;
    cin >> n;
    int fib[n + 1];

    for(int i = 0; i <= n; i++) {
        fib[i] = 0;
    }

    countFib(n,fib);

    cout << fib[n];
    return 0;
}
