#include <iostream>

using namespace std;

void printArr(int arr[],int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n---------------------------" << endl;

}

int swapNums(int arr[],int i,int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int findPartition(int low,int high,int arr[],int n) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swapNums(arr,i,j);
            printArr(arr,n);
        }
    }

    swapNums(arr,i+1,high);
    return i + 1;
}

void quickSort(int arr[],int low,int high,int n) {
    if(low < high) {
        int pi = findPartition(low,high,arr,n);
        quickSort(arr,low,pi-1,n);
        quickSort(arr,pi+1,high,n);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr,0,n-1,n);
    printArr(arr,n);

    return 0;
}
