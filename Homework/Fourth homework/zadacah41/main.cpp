#include <iostream>

using namespace std;

void selectionSort(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        int minEl = arr[i];
        int minIndex = -1;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < minEl) {
                minEl = arr[j];
                minIndex = j;
            }
        }

        if(minIndex != -1) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr,n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
