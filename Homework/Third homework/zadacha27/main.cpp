#include <iostream>

using namespace std;

int sum = 0;

void countSum(int arr[],int n,int index) {
    if(index < n){
        sum +=arr[index];
        countSum(arr,n,index+1);
    }
}

int main() {
    int n = 5;
    int arr[] = {1,2,3,4,5};

    countSum(arr,n,0);
    cout << sum;
    return 0;
}
