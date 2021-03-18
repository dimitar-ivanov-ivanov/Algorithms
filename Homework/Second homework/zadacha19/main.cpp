#include <iostream>

using namespace std;

int main() {
    int n,sum;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i][n-i-1];
    }

    cout << sum;
    return 0;
}
