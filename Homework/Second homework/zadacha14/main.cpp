#include <iostream>

using namespace std;

#define N 2
#define M 2

int main() {
    int arr[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}
