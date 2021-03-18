#include <iostream>

using namespace std;

int main() {
    int n,broi,ploshtatka;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    broi = 0;
    ploshtatka = 0;
    for(int i = 0; i < n-1; i++) {
        if(arr[i] == arr[i+1]) {
            broi++;
            ploshtatka = 1;
        } else {
            ploshtatka = 0;
        }

        if(i > 0 && ploshtatka == 1 &&
                arr[i] == arr[i-1]) {
            broi--;
        }
    }

    cout << broi;

    return 0;
}
