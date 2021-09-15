#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
int main(){
    int *arr_1482;
    int size_1482;
    printf("Enter size of array:");
    scanf("%d",&size_1482);
    arr_1482 = (int*) malloc(sizeof(int)*size_1482);
    printf("Enter elements of array:");
    for (int i = 0; i < size_1482; i++)
    {
        scanf("%d",arr_1482+i);
    }
    for (int i = 0; i < size_1482; i++)
    {
        int min = i;
        for (int j = i; j < size_1482; j++)
        {
            if(*(arr_1482+min) > *(arr_1482+j))
                min = j;
        }
        swap(arr_1482+min,arr_1482+i);
    }
    int k_1482;
    printf("Enter K : ");
    scanf("%d",&k_1482);
    printf("%dth smallest element : %d and %dth largest element : %d \n",k_1482,*(arr_1482+k_1482-1),k_1482,*(arr_1482+size_1482-k_1482));
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}