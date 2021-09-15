#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int extreme(int *,int);
int main(){
    int size_1482 = 0;
    printf("Enter size of array:");
    scanf("%d",&size_1482);
    int *arr_1482 = malloc(sizeof(int) * size_1482);
    printf("Enter elements :");
    for(int i = 0;i < size_1482;i++){
        scanf("%d",&arr_1482[i]);
    }
    extreme(arr_1482,size_1482);
    free(arr_1482);
}
int extreme(int *arr_1482,int size_1482){
    int max_1482 = INT_MIN;
    int min_1482 = INT_MAX;
    for(int i = 0;i < size_1482;i++){
        if(arr_1482[i] < min_1482)
            min_1482 = arr_1482[i];
        if(arr_1482[i] > max_1482)
            max_1482 = arr_1482[i];      
    }
    printf("MAX VALUE: %d MIN VALUE: %d",max_1482,min_1482);
}