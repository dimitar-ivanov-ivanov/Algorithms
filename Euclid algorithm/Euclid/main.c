#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 40;
    int b = 15;
    int result = euclid(a,b);
    printf("%d",result);
    return 0;
}

int euclid(int a,int b){
    int temp = 0;
    while(b > 0){
       temp = b;
       b = a % b;
       a =temp;
    }

    return a;
}
