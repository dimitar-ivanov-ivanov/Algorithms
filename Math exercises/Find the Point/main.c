#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,px,py,qx,qy,i,rx,ry;

    scanf("%d",&n);


    //we have two points find the reflective of p to q
    //example p(0,0) q(1,1) -> r(2,2)
    //to solve image we have a line between p and r this way q is the middle and we need to find r ->qx = (rx + px) / 2
    for(i = 0; i < n; i++) {
        scanf("%d %d %d %d",&px,&py,&qx,&qy);
        rx = 2 * qx - px;
        ry = 2 * qy - py;
        printf("%d %d\n",rx,ry);
    }

}
