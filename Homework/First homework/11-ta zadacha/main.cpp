#include <iostream>
#define N 5

using namespace std;

int main() {

    int i,arr[N],counter = 0;

    for(i =0; i<N; i++) {
        cout << "arr["<<i<<"] = ";
        cin >> arr[i];
    }

    for(i =1; i<N; i++) {
        if((arr[i] >= 0 && arr[i-1] <0) || (arr[i] <0 && arr[i-1]>=0)) {
            counter++;
        }
    }

    cout << "Broq na sasedni dvoiki s razlichni znachi e:" <<counter;
    return 0;
}
