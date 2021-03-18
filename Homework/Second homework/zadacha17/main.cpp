#include <iostream>

using namespace std;

int main() {
    int n,m,x,y,broi,index,i,j;
    cin >> n >> m;
    cin >> x >> y;

    int matrix[n][m];
    int arr[y-x];

    broi = 0;
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> matrix[i][j];
            broi++;
            if(broi >= x && broi <= y) {
                arr[index++] = matrix[i][j];
            }
        }
    }

    cout << "Output is:" << endl;
    for(i = 0; i <= y-x; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
