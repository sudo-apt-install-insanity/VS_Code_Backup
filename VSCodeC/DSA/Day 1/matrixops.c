#include <stdio.h>
#include <stdlib.h>
void zeroes(int **, int);
void sum1(int **, int);
void display1(int **, int);
void display2(int **, int);
void display3(int **, int);
int main()
{
    int order_1482;
    printf("Enter order of matrix:");
    scanf("%d", &order_1482);
    int **matrix_1482 = (int **)malloc(sizeof(int *) * order_1482);
    for (int i = 0; i < order_1482; i++)
        matrix_1482[i] = (int *)malloc(sizeof(int) * order_1482);
    printf("Enter elements : ");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            scanf("%d", &matrix_1482[i][j]);
        }
    }
    printf("\e[1;1H\e[2J");
    for (int i = 0; i < order_1482; i++)
    {
        for (int j = 0; j < order_1482; j++)
        {
            printf("%2d ", matrix_1482[i][j]);
        }
        printf("\n");
    }
    int choice;
    printf("Enter choice:\n");
    printf("1.Find number of zeroes.\n");
    printf("2.Sum of all elements above main diagonal.\n");
    printf("3.Display all diagonal elements.\n");
    printf("4.Display matrix in row-major order.\n");
    printf("5.Display matrix in column-major order.\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        zeroes(matrix_1482, order_1482);
        break;
    case 2:
        sum1(matrix_1482, order_1482);
        break;
    case 3:
        display1(matrix_1482, order_1482);
        break;
    case 4:
        display2(matrix_1482, order_1482);
        break;
    case 5:
        display3(matrix_1482, order_1482);
        break;

    default:
        break;
    }
}
void zeroes(int **matrix_1482, int order_1482)
{
    int i, j, count = 0;
    for (i = 0; i < order_1482; i++)
    {
        for (j = 0; j < order_1482; j++)
        {
            if (matrix_1482[i][j] == 0)
            {
                count++;
            }
        }
    }
    printf("Number of zeroes : %d\n", count);
}
void sum1(int **matrix_1482, int order_1482)
{
    int i, j, sum = 0;
    for (i = 0; i < order_1482; i++)
    {
        for (j = 0; j < order_1482; j++)
        {
            if (j > i)
            {
                sum += matrix_1482[i][j];
            }
        }
    }
    printf("Sum of elements above main diagonal : %d\n", sum);
}
void display1(int **matrix_1482, int order_1482)
{
    int i, j;
    printf("Elements in main diagonal : ");
    for (i = 0; i < order_1482; i++)
    {
        for (j = 0; j < order_1482; j++)
        {
            if (i == j)
            {
                printf("%d ", matrix_1482[i][j]);
            }
        }
    }
    printf("\n");
}
void display2(int **matrix_1482, int order_1482)
{
    int i, j;
    printf("Elements in row-major order : ");
    for (i = 0; i < order_1482; i++)
    {
        for (j = 0; j < order_1482; j++)
        {
            printf("%d ", matrix_1482[i][j]);
        }
    }
    printf("\n");
}
void display3(int **matrix_1482, int order_1482)
{
    int i, j;
    printf("Elements in column-major order : ");
    for (i = 0; i < order_1482; i++)
    {
        for (j = 0; j < order_1482; j++)
        {
            printf("%d ", matrix_1482[j][i]);
        }
    }
    printf("\n");
}