#include <stdio.h>
#include <stdlib.h>
#define __INT_FAST64_MAX__ iint;
typedef long long  ll;
void sort(ll*);
int main(){
    int T;
    scanf("%d",&T);
    while(T > 0){
        ll num[3];
        scanf("%lld %lld %lld",&num[0],&num[1],&num[2]);
        sort(num);
        printf("%lld",num[2]+num[1]);
        T--;
    }
}
void sort(ll *arr){
    ll temp;
    for(int i = 0;i < 3;i++){
        for (int j = 1; j < 3; j++)
        {
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}