#include <iostream>
#include <vector>

using namespace std;

void toBinary(int n,vector<int> arr) {
    if(n > 0) {
        toBinary(n/2,arr);
        arr.push_back(n%2);
    }
}


int main() {
    int n,index;
    cin >> n;
    vector<int> arr;
    arr.reserve(n);
    toBinary(n,arr);

    for(int i = 0; i < arr.size(); i++) {
        cout<< arr[i] << endl;
    }
    return 0;
}
