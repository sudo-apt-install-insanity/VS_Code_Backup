#include <stdio.h>
#include <stdlib.h>
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
    printf("Original array : ");
    for (int i = 0; i < size_1482; i++)
    {   
        printf("%d ",*(arr_1482+i));
    }
    printf("\n");
    for (int i = 0; i < size_1482; i++)
    {
        if(arr_1482[i] % 2 == 0){
            for (int j = i; j < size_1482; j++)
            {
                arr_1482[j] = arr_1482[j+1];
            }
            // arr_1482[size_1482-1] = 0;// Not show garbage values in empty indexes.
            size_1482--;
        }
    }
    printf("Even deleted array :");
    for (int i = 0; i < size_1482; i++)
    {   
        printf("%d ",*(arr_1482+i));
    }
    printf("\n");
}