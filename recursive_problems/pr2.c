//
// Created by q on 12/27/2019.
//

#include "pr2.h"
#include <stdio.h>

int h(int k,int x) {
    if(k==0) return 1;
    else if(k==1) return 2*x;
    else return 2*k*h(k-1,x)-2*(k-1)*h(k-2,x);
}
void hermite() {
    int x,k;
    printf("Please enter the order of the hermite polynomial!\n");
    scanf("%d",&k);
    printf("Please enter the value of the variable x!\n");
    scanf("%d",&x);
    printf("The hermite polynomial of order %d, of %d: %d.\n",k,x,h(k,x));
}