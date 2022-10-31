#include <bits/stdc++.h>
using namespace std;

int nonzero(int ** ,int );
int sum_above_main_diag(int **,int );
void disp_below_minor(int **,int );
void prod_diag(int **,int );

int main(){
    int **mat;
    int order;
    printf("Enter order of matrix : ");
    scanf("%d",&order);
    mat = (int **)malloc(sizeof(int *)*order);
    for (int i = 0; i < order; i++)
    {
        mat[i] = (int *)malloc(sizeof(int)*order);
    }
    printf("Enter elements of matrix : \n");
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }

    printf("Nonzero : %d\n",nonzero(mat,order));
    printf("Sum above leading : %d\n",sum_above_main_diag(mat,order));
    disp_below_minor(mat,order);
    prod_diag(mat,order);
}

int nonzero(int ** p,int order){
    int count = 0;
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if(p[i][j] != 0){
                count++;
            }
        }
    }
    return count;
}

int sum_above_main_diag(int **p,int order){
    int sum = 0;
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if(j > i)
                sum += p[i][j];
        }
    }
    return sum;
}

void disp_below_minor(int **p,int order){
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            if(i > order-1-j)
                printf("%d  ",p[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}

void prod_diag(int **p,int order){
    int main_prod = 1,minor_prod = 1;
    for (int i = 0; i < order; i++)
    {
        for(int j = 0;j < order;j++){
            if(i == j){
                main_prod *= p[i][j];
            }
            if(i+order-1-j == order-1)
                minor_prod *= p[i][order-1-j];
            
        }
    }
    printf("Main prod : %d \nMinor prod : %d \n",main_prod,minor_prod);
    
    
}

