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
    printf("\n");
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; ){
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size; k++){
                    arr[k] = arr[k+1];
                }
                size--;
            }else
                j++;
        }
    }
    
    
    printf("New array: ");
    for (int i = 0; i < size; i++)
    {   
        printf("%d ",arr[i]);
    }
}