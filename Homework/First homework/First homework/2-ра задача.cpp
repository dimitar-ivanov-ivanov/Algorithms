#include <iostream>
#include "math.h"
using namespace std;

int main2() {
    int num,sum,digits;
    cin >> num;

    digits = 3;
    sum = 0;
    while(num > 0) {
        sum += num % (10 ^ (digits-1));
        digits--;
    }

    cout<<sum;
    return 0;
}
