#include <stdio.h>
#include <stdlib.h>
void arrrot(int * ,int ,int ,int ,int ,int );
int main(){
    int *arr;
    int size,dir,shift,start,end;
    printf("Enter size:");
    scanf("%d",&size);
    arr = (int*)malloc(sizeof(int)*size);
    printf("Enter elements:");
    for (int i = 0; i < size; i++){   
        scanf("%d",arr+i);
    }
    printf("Enter shifting direction \n1.Left\n2.Right \n");
    scanf("%d",&dir);
    printf("Enter shifting value : ");
    scanf("%d",&shift);
    printf("Enter starting and final index : ");
    scanf("%d%d",&start,&end);

    printf("Original array : ");
    for (int i = 0; i < size; i++){   
        printf("%d ",*(arr+i));
    }
    printf("\n");
    arrrot(arr,size,dir,shift,start,end);
    printf("Final array : ");
    for (int i = 0; i < size; i++){   
        printf("%d ",*(arr+i));
    }
    printf("\n");
    
}
void arrrot(int *arr,int size,int dir,int shift,int start,int end){
    switch (dir)
    {
    case 1:
        while(shift-->0){
            int temp = arr[start];
            for(int i = start;i < end;i++){
                arr[i] = arr[i+1];
            }
            arr[end] = temp;
        }
        break;
    case 2:
        while(shift-->0){
            int temp = arr[end];
            for(int i = end;i > start;i--){
                arr[i] = arr[i-1];
            }
            arr[start] = temp;
        }
        break;
    default:
        printf("Invalid rotation direction!!");
        break;
    }
}