#include <iostream>

using namespace std;

int main() {
    int i,j,n,m,*p,k;
    cin >> n >> m;
    int arr[n][m];
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    p = &arr[0][0];
    cin >> k;
    cout << *(p + k - 1);
    return 0;
}
