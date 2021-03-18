#include <iostream>

using namespace std;

int main() {
    int n,i,res;
    cin>>n;
    int arr[n];

    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    res = 1;
    for(i = 0; i < n -1; i++) {
        if(arr[i] + arr[i+1] <= 120) {
            res *= arr[i];
        }
    }

    cout << res;

    return 0;
}
