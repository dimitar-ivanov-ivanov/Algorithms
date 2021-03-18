#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            arr[i][j]++;
            arr[i][i]++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            arr[i][j]--;
            arr[i][i]++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << arr[i][j]
    }


    return 0;
}
