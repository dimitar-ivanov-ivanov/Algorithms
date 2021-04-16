#include <iostream>

using namespace std;

void getLowestCountOfCoins(int n,int coins[],int sum,int index) {
    if(sum > 0) {
        if(coins[index] <= sum) {
            cout << coins[index] << " -> " << sum /coins[index] << endl;
            getLowestCountOfCoins(n,coins,sum % coins[index],index);
        } else {
            getLowestCountOfCoins(n,coins,sum,index+1);
        }
    }
}

void sortArr(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n,sum;
    cin >> n >> sum;
    int coins[n];

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sortArr(coins,n);
    getLowestCountOfCoins(n,coins,sum,0);
    return 0;
}
