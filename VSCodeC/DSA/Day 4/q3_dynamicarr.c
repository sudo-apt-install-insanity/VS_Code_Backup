#include <stdio.h>
#include <stdlib.h>
void input(int *,int );
void delete_beg(int *,int *);
void delete_end(int *,int *);
void delete(int *,int *);
void display(int *,int );
void delete_element(int *,int *);
int menu();

int main(){
    int *arr_1482,*size_1482;
    printf("Enter size : ");
    scanf("%d",size_1482);
    arr_1482 = (int *)malloc(sizeof(int)*(*size_1482));
    input(arr_1482,*size_1482);
    display(arr_1482,*size_1482);
    switch(menu()){
        case 1:
            delete(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        case 2:
            delete_beg(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        case 3:
            delete_end(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        case 4:
            delete_element(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        default:
            break;
    }

}
int menu(){
    int choice;
    printf("1.Delete at index.\n");
    printf("2.Delete from beginning.\n");
    printf("3.Delete from end.\n");
    printf("4.Delete element.\n");
    printf("Enter choice : ");
    scanf("%d",&choice);
    return choice;
}
void input(int *arr,int size){
    printf("Enter elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",arr+i);
    }
}
void delete_beg(int *arr,int *size){
    int value;
    for (int i = 0;i < *size;i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
    realloc(arr,sizeof(int)*(*size));
}
void delete_end(int *arr,int *size){
    (*size)--;
    realloc(arr,sizeof(int)*(*size));
}
void delete(int *arr,int *size){
    int idx;
    printf("Enter index to delete : ");
    scanf("%d",&idx);
    for (int i = idx; i < *size; i++)
    {
        arr[i] = arr[i+1];
    }
    (*size)--;
    realloc(arr,sizeof(int)*(*size)); 
}
void delete_element(int *arr,int *size){
    int element;
    printf("Enter element to delete : ");
    scanf("%d",&element);
    for (int i = 0; i < *size; i++)
    {
        if(arr[i] == element){
            for (int j = i; j < *size; j++)
            {
                arr[j] = arr[j+1];
            }
            (*size)--;  
        }
    }
    
}
void display(int *arr,int size){
    printf("Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}