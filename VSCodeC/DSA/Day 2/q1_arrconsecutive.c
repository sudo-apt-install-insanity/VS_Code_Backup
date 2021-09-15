#include <stdio.h>
#include <stdlib.h>
int ascarr(int *,int );
int main(){
    int *arr_1482;
    int size_1482;
    printf("Enter size:");
    scanf("%d",&size_1482);
    arr_1482 = (int*)malloc(sizeof(int)*size_1482);
    printf("Enter elements:");
    for (int i = 0; i < size_1482; i++)
    {   
        scanf("%d",arr_1482+i);
    }
    printf("The max number of ascending elements are: %d",ascarr(arr_1482,size_1482));
    
}
int ascarr(int *arr_1482,int size_1482){
    int counter = 1;
    int maxcount = 0;
    for (int i = 1; i < size_1482; i++)
    {
        if(arr_1482[i] > arr_1482[i-1]){
            ++counter;
            if(maxcount < counter)
                maxcount = counter;
        } 
        else{
            if(maxcount < counter)
                maxcount = counter;
            counter = 1;
        }
    }
    return maxcount;
}