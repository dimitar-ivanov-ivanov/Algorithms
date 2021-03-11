#include <stdio.h>
#include <stdlib.h>

void genCombs(int n,int k,int index,int last,int arr[n],int set[k]);
void printSet(int k,int set[k]);

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n],set[k];

    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for(int i = 0; i < k; i++) {
        set[i] = 0;
    }

    genCombs(n,k,0,0,arr,set);
    return 0;
}

void genCombs(int n,int k,int index,int last,int arr[n],int set[k]) {
    if(index == k) {
        printSet(k,set);
        return;
    }

    for(int i = last; i < n; i++) {
        set[index] = arr[i];
        genCombs(n,k,index+1,i+1,arr,set);
    }
}

void printSet(int k,int set[k]) {
    for(int i = 0; i < k; i++) {
        printf("%d ",set[i]);
    }
    printf("\n");
}



