#include <iostream>

using namespace std;

int main() {
    int num,sum=0,remainder;
    cout<<"Enter a number: ";
    cin>>num;

    while(num>0) {
        remainder=num%10;
        sum=sum+remainder;
        num=num/10;
    }

    cout<<"Sum is= "<<sum<<endl;
    return 0;
}
