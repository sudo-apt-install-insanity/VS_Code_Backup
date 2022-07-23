#include <stdio.h>

int main(){
    int a = 256;
    int byte[4], ff = 255,k = 0;
    
    while(k < 4){
        byte[k] = a&ff;
        a= a >> 8;
        printf("%d\n",byte[k]);
        k++;
    }
    if(byte[k-1] == 0){
        printf("Little Endian");
    }else{
        printf("Big Endian");
    }

    return 0;

}