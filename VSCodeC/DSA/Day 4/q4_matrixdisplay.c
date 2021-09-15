#include <stdio.h>
#include <stdlib.h>
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
    printf("Enter elements of matrix : \n");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            scanf("%d",&mat_1482[i][j]);
        }
    }
    printf("UPPER LEFT TRIANGULAR MATRIX : \n");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            if(i < order_1482-1-j)
                printf("%d ",mat_1482[i][j]);
            else if(mat_1482[i][j] < 10)
                printf("   ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("UPPER RIGHT TRIANGULAR MATRIX : \n");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            if(j > i)
                printf("%d  ",mat_1482[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    printf("LOWER LEFT TRIANGULAR MATRIX : \n");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            if(j < i)
                printf("%d  ",mat_1482[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    printf("LOWER RIGHT TRIANGULAR MATRIX : \n");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            if(i > order_1482-1-j)
                printf("%d  ",mat_1482[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
    

}