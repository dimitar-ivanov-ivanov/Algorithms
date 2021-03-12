#include <iostream>
#include <math.h>

using namespace std;

void eratosten(int sieve[],int n);

int main() {
    int n;
    cout << "input number:" << endl;
    cin >> n;
    int sieve[n];

    //mark as not prime
    for(int i=0; i<=n; i++) {
        sieve[i] = 0;
    }

    eratosten(sieve,n);
    return 0;
}

void eratosten(int sieve[],int n) {

    for(int i=2; i<=n; i++) {
        if(sieve[i] == 0) {
            sieve[i] = 1;
            cout << i << " is prime." << endl;
            for(int j=i * i; j<=n; j+=i) {
                sieve[j] = 1;
            }
        }
    }
}
