#include <stdio.h>
#include <stdlib.h>

void sortArr(int *arr,int n);

int main() {
    //Write a program, which gathers a sum of money,
    // using the least possible number of coins. This is the range of possible coin values:
    int n,currentCoin,totalCoins,sum;
    int max = -1;

    scanf("%d",&n);
    int coins[n];

    for(int i = 0; i < n; i++) {
        scanf("%d, ",&coins[i]);
        if(coins[i] > max) {
            max = coins[i];
        }
    }

    scanf("%d",&sum);

    int coinCount[max+1];
    for(int i = 0; i <= max; i++) {
        coinCount[i] = 0;
    }

    sortArr(coins,n);

    totalCoins = 0;
    for(int i = n-1; i >= 0; i--) {
        currentCoin = coins[i];
        while(currentCoin <= sum) {
            sum -= currentCoin;
            coinCount[currentCoin]++;
            totalCoins++;
        }
    }

    if(sum > 0) {
        printf("Cannot reach desired sum with these coin values");
        return 0;
    }

    printf("Number of coins to take: %d\n",totalCoins);

    for(int i = n-1; i >= 0; i--) {
        currentCoin = coins[i];
        if(coinCount[currentCoin] != 0) {
            printf("%d coin(s) with value %d\n",coinCount[currentCoin],currentCoin);
        }
    }

    return 0;
}

void sortArr(int *arr,int n) {
    int temp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}
