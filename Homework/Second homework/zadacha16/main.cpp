#include <iostream>

using namespace std;

int main() {
    int n,m,sumDiagonal,sum,sumUnderDiagonal;
    cin >> n;
    int arr[n][n];
    int result[3];
    sum = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    sumDiagonal = 0;
    for(int i = 0; i < n; i++) {
        sumDiagonal +=  arr[i][i];
    }

    sumUnderDiagonal = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            sumUnderDiagonal += arr[i][j];
        }
    }

    result[0] = sumDiagonal;
    result[1] = sumUnderDiagonal;
    result[2] = sum;

    for(int i = 0; i < 3; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
