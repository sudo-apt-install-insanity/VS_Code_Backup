#include <stdio.h>
#include <stdlib.h>

int chk(int j){
    static int sum = 0;
    sum += j;
    return sum;
}
void chkB(int n){
    int i,total;
    for (i = 1; i <= n; ++i)
    {
        total = chk(i);
    }
    printf("%d",total);
    
}
int main(){
    chkB(4);
}