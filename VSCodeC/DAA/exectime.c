#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    clock_t start = clock();

    for(int i = 0;i < 10;i++){
        printf("processing %d ...\n",i);
    }

    clock_t end = clock();

    double time_taken = (double)(end - start)/ CLOCKS_PER_SEC; 

    printf("\nEXECUTION TIME: %f",time_taken);
}