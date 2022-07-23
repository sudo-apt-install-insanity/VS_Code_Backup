#include <stdio.h>

int main(){
    int x,y;
    int *a,*b;
    a = &x;
    b = &y;
    printf("Enter two numbers : ");
    scanf("%d%d",&x,&y);
    printf("a : %d\nb: %d\n",x,y);

    int temp = *a;
    *a = *b;
    *b = temp;

    printf("a : %d\nb: %d\n",x,y);



    return 0;
}