#include <stdio.h>
#include <stdlib.h>
int main(){
    int *arr;
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("Enter elements:");
    for (int i = 0; i < size; i++)
    {   
        scanf("%d",arr+i);
    }
    printf("Original array : ");
    for (int i = 0; i < size; i++)
    {   
        printf("%d ",*(arr+i));
    }
    printf("\nElements with previous contiguous sum : ");
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i-1; j >= 0; j--)
        {
            sum += arr[j];
            if(sum == arr[i]){
                printf("%d ",arr[i]);
            }
        }
        
    }
    
}