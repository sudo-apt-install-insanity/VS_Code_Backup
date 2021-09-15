#include <stdio.h>
#include <stdlib.h>
void f1(int *b){
    *b = 9;
}
int main(){
    int a = 5;
    f1(&a);
    printf("a = %d",a);
}