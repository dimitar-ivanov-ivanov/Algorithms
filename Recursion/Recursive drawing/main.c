#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    draw(n);
    return 0;
}

void draw(int n) {
    if(n == 0) {
        return;
    }

    //draw stars *
    for(int i = 0; i < n; i++) {
        printf("*");
    }

    printf("\n");
    draw(n - 1);
    //draw #
    for(int i = 0; i < n; i++) {
        printf("#");
    }
    printf("\n");
}
