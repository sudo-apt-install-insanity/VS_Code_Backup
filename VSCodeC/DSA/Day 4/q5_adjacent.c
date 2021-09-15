#include <stdio.h>
#include <stdlib.h>
void sum(int **,int );
int main(){
    int **mat_1482;
    int order_1482;
    printf("Enter order of matrix : ");
    scanf("%d",&order_1482);
    mat_1482 = (int **)malloc(sizeof(int *)*order_1482);
    for (int i = 0; i < order_1482; i++)
    {
        mat_1482[i] = (int *)malloc(sizeof(int)*order_1482);
    }
    printf("Enter elements of matrix : ");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            scanf("%d",&mat_1482[i][j]);
        }
    }
    while (1)
    {
        sum(mat_1482,order_1482);
    }
    
    
}

void sum(int **mat,int order){
    int value_i,value_j,value,sum = 0;
    printf("Enter value : ");
    scanf("%d",&value);
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if(mat[i][j] == value){
                value_i = i;
                value_j = j;
            }
        }
    }
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (value_i+i < order && value_j+j < order && value_i+i >= 0 && value_j+j >= 0)
            {
                sum += mat[value_i+i][value_j+j];
            }
        }
    }
    sum -= mat[value_i][value_j];
    printf("Sum is : %d\n",sum); 
}