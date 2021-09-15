#include <stdio.h>
#include <stdlib.h>
void input(int *,int );
void insert_beg(int *,int *);
void insert_end(int *,int *);
void insert(int *,int *);
void display(int *,int );
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
            insert(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        case 2:
            insert_beg(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        case 3:
            insert_end(arr_1482,size_1482);
            display(arr_1482,*size_1482);
            break;
        default:
            break;
    }
}
int menu(){
    int choice;
    printf("1.Insert at postion.\n");
    printf("2.Insert at beginning.\n");
    printf("3.Insert at end.\n");
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
void insert_beg(int *arr,int *size){
    int value;
    printf("Enter element to insert : ");
    scanf("%d",&value);
    (*size)++;
    realloc(arr,sizeof(int)*(*size));
    for (int i = (*size)-1;i > 0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
}
void insert_end(int *arr,int *size){
    int value;
    printf("Enter element to insert : ");
    scanf("%d",&value);
    (*size)++;
    realloc(arr,sizeof(int)*(*size));
    arr[(*size)-1] = value;
}
void insert(int *arr,int *size){
    int idx,value;
    printf("Enter index and element to insert : ");
    scanf("%d%d",&idx,&value);
    (*size)++;
    realloc(arr,sizeof(int)*(*size));
    for (int i = (*size)-1; i > idx; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[idx] = value; 
}
void display(int *arr,int size){
    printf("Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}