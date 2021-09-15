#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[2] = {1,2};
    int b[2] = {3,4};
    int *s;
    int (*p)[2] = &a;
    s = *p+1;
    s = b;
    printf("%d %d\n%d %d",p[0][0],p[0][1],p[1][0],p[1][0]);
}