#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n = 0;
    printf("Enter n:");
    scanf("%d",&n);
    int **matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0;i < n;i++)
        *(matrix+i) = (int*)malloc(sizeof(int) * n);
    
 
    for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                printf("Enter element:");
                scanf("%d",&matrix[i][j]);
            }
    }
    for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                printf("%2d ",matrix[i][j]);
            }
            printf("\n");
    }
    int choice;
    printf("Enter choice:\n");
    printf("1.Number of non-zero elements.\n");
    printf("2.Sum of elements above leading diagonal.\n");
    printf("3.Display elements below minor diagonal.\n");
    printf("4.Find product of diagonal elements.\n");
    scanf("%d",&choice);
    int count1 = 0,sum = 0,prodd = 1;
    switch(choice){
        case 1:
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
               if(matrix[i][j] != 0)
                count1++;     
            }
        }
        printf("Number of non-zero elements :%d\n",count1);
        break;
        case 2:
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(j > i){
                    sum += matrix[i][j];
                }
            }
        }
        printf("Sum of elements above leading diagonal :%d\n",sum);
        break;
        case 3:
        printf("Elements below minor diagoanl: ");
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(j > n-1-i){
                    printf("%d ",matrix[i][j]);
                }
            }
        }
        break;
        case 4:
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i == j){
                    prodd *= matrix[i][j];
                }
            }
        }
        printf("Product of diagonal elements: %d\n",prodd);
        break;
        
    }

}