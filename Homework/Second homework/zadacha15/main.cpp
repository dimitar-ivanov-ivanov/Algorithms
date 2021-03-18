#include <iostream>

using namespace std;

int main() {
    int n,m,sum;
    scanf("%d %d",&n,&m);
    int arr[n][m];
    sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    cout << sum << endl;
    return 0;
}
