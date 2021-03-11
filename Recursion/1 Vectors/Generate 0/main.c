#include <stdio.h>
#include <stdlib.h>

void generateVectors(int n,int index,int v[n]);
void printVector(int n,int v[n]);

int main() {
    int n;
    scanf("%d",&n);
    int v[n];
    generateVectors(n,0,v);
    return 0;
}

void generateVectors(int n,int index,int v[n]) {
    if(index == n) {
        printVector(n,v);
        return;
    }

    v[index] = 0;
    generateVectors(n,index+1,v);
    v[index] = 1;
    generateVectors(n,index+1,v);
}

void printVector(int n,int v[n]) {
    for(int i = 0; i < n; i++) {
        printf("%d",v[i]);
    }
    printf("\n");
}
