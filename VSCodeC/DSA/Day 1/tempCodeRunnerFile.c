#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
int main(){
    int *arr;
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    arr = (int*) malloc(sizeof(int)*size);
    printf("Enter elements of array:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",arr+i);
    }
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if(*(arr+min) > *(arr+j))
                min = j;
        }
        swap(arr+min,arr+i);
        
    }
    int k;
    printf("Enter K : ");
    scanf("%d",&k);
    printf("%dth smallest element : %d and %dth largest element : %d \n",k,*(arr+k-1),k,*(arr+size-k));
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}