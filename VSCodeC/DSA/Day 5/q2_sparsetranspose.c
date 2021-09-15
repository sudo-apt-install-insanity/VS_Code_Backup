#include <stdio.h>
#include <stdlib.h>
typedef struct triplet{
    int x;
    int y;
    int val;
}triplet;
void swap (triplet *,triplet *);
void tripletSort(triplet *);
void tripletTranspose(triplet *);
void matrixFromTriplet(triplet *,int **);
void printMatrix(int **,int ,int );
int** makeMatrix(int ,int );
void printTriplet(triplet *);
int main(){
    int **org_1482,**trans_1482;
    int elements_1482,row_1482,col_1482;
    printf("Enter number of elements : ");
    scanf("%d",&elements_1482);
    triplet *triplist_1482;
    triplist_1482 = (triplet *)malloc(sizeof(triplet)*(elements_1482+1));
    (triplist_1482+0)->val = elements_1482;
    printf("Enter number of rows and columns : ");
    scanf("%d%d",&row_1482,&col_1482);
    (triplist_1482+0)->x = row_1482;
    (triplist_1482+0)->y = col_1482;
    for (int i = 1; i <= elements_1482; i++)
    {
        printf("Enter x,y and value : ");
        scanf("%d%d%d",&(triplist_1482+i)->x,&(triplist_1482+i)->y,&(triplist_1482+i)->val);
    }
    org_1482 = makeMatrix(row_1482,col_1482);
    trans_1482 = makeMatrix(col_1482,row_1482);
    matrixFromTriplet(triplist_1482,org_1482);
    printf("Original matrix : \n");
    printMatrix(org_1482,row_1482,col_1482);
    // printTriplet(triplist);
    tripletTranspose(triplist_1482);
    // printTriplet(triplist);
    matrixFromTriplet(triplist_1482,trans_1482);
    printf("Transpose matrix : \n");
    printMatrix(trans_1482,col_1482,row_1482);
}

int** makeMatrix(int row,int col){
    int **p;
    p =(int **)malloc(sizeof(int *)*row);
    for (int i = 0; i < row; i++)
    {
        p[i] = (int *)calloc(col,sizeof(int));
    }
    return p;
}
void printMatrix(int **p,int row,int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
    
}
void matrixFromTriplet(triplet *p,int **mat){
    for (int i = 1; i <= (p+0)->val; i++)
    {
       mat[(p+i)->x][(p+i)->y] = (p+i)->val;
    }
    
}
void tripletTranspose(triplet *p){
    for (int i = 1; i <= (p+0)->val; i++)
    {
        int temp = (p+i)->x;
        (p+i)->x = (p+i)->y;
        (p+i)->y = temp;
    }
    tripletSort(p);
}
void tripletSort(triplet *p){
    int elements = (p+0)->val;
    for (int i = 1; i <= elements; i++)
    {
        for (int j = i+1; j <= elements; j++)
        {
            if((p+i)->x > (p+j)->x){
                swap(p+i,p+j);
            }else if((p+i)->x == (p+j)->x){
                if((p+i)->y > (p+j)->y){
                    swap(p+i,p+j);
                }
            }
        }
    }
    
}
void printTriplet(triplet *p){
    int size = (p+0)->val;
    printf("Triplet : \n");
    for (int i = 0; i <= size; i++)
    {
        int x = (p+i)->x;
        int y = (p+i)->y;
        int val = (p+i)->val;
        printf("%d %d %d \n",x,y,val);
    }
}
void swap (triplet *a,triplet *b){
    triplet temp  = *a;
    *a = *b;
    *b = temp;
}