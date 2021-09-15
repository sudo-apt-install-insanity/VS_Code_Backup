#include <stdio.h>
#include <stdlib.h>
void reverse(int *, int);
void printarr(int *,int);
int main(){
    int size_1482 = 0;
    printf("Enter size:");
    scanf("%d",&size_1482);
    int *arr_1482 = malloc(sizeof(int) * size_1482);
    printf("Enter elements :");
    for(int i = 0;i < size_1482;i++){
        scanf("%d",&arr_1482[i]);
    }
    printarr(arr_1482,size_1482);
    reverse(arr_1482,size_1482);
    printarr(arr_1482,size_1482);
    free(arr_1482);
    return 0;

}
void reverse(int *arr_1482, int size_1482){
    int temp_1482 = 0;
    for(int i = 0;i < size_1482/2;i++){
        temp_1482 = arr_1482[i];
        arr_1482[i] = arr_1482[size_1482-1-i];
        arr_1482[size_1482-1-i] = temp_1482;
    }
}
void printarr(int *arr_1482,int size_1482){
    for(int i = 0;i < size_1482;i++)
        printf("%d ",arr_1482[i]);
    printf("\n");
}