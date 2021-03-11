#include <iostream>
#define N 5

using namespace std;

int main() {
    int i,arr[N],maxNum,k = 0,n,p = 0;
    float sum = 0;
    cin >> n;

    for(i=0; i<N; i++) {
        cout << "arr["<<i<<"] = ";
        cin >> arr[i];
    }

    maxNum = arr[0];
    for(i=0; i<N; i++) {
        sum = sum + arr[i];
        if(arr[i] > maxNum) {
            maxNum = arr[i];
        }
        if(arr[i]%2 !=0 && arr[i] != 0) {
            k++;
        }
        if(arr[i] < 0 && n == arr[i]) {
            p = 1;
        }
    }

    cout << "max = " << maxNum << "\n";
    cout << "k = " << k << "\n";
    cout << "avg = " << sum/N << "\n";

    if(p) {
        cout << "DA\n";
    } else {
        cout << "NE\n"
    }

    return 0;
}
