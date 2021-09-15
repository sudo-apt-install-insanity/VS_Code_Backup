#include <stdio.h>
#include <stdlib.h>
void f1(int (*b)[5]){
    printf("%d",*(*b+1));
    *(*b+1) = 99;
}
void f2(int b[5]){
    printf("%d",*(b+1));
    *(b+1) = 99;
}
int main(){
    int a[5] = {5,9,7,8,2};
    int *q = &a[0];
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(&q[0]+i));
        // q++;
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",q[0]);
        q++;
    }
    printf("\n");
    f2(a);//9
    printf("\n");
    printf("%d",a[1]);//99
    printf("\n");
    f1(&a);//99
    printf("\n");
    printf("%d",a[1]);//99
}