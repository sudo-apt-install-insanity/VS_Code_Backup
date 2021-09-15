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
    printf("The sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",*(arr+i));
    }
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}