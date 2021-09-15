#include <stdio.h>
#include <stdlib.h>
int main(){
    int *poly1_1482,*poly2_1482,n_1482,m_1482;
    printf("Enter order of first polynomial and second polynomial : ");
    scanf("%d%d",&n_1482,&m_1482);
    poly1_1482 = (int*)malloc(sizeof(int)*(n_1482+1));
    poly2_1482 = (int*)malloc(sizeof(int)*(m_1482+1));
    for (int i = 0; i < n_1482+1; i++)
    {
        printf("Enter coefficient for x^%d : ",i);
        scanf("%d",&poly1_1482[i]);
    }
    for (int i = 0; i < m_1482+1; i++)
    {
        printf("Enter coefficient for x^%d : ",i);
        scanf("%d",&poly2_1482[i]);
    }
    int ch;
    do{
        int *result_1482;
        printf("1.Addition.\n");
        printf("2.Subtraction.\n");
        printf("3.Multiplication.\n");
        printf("4.Exit.\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            if(n_1482 > m_1482){
                result_1482 = (int *)malloc(sizeof(int)*(n_1482+1));
                for (int i = 0; i < m_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i]+poly2_1482[i];
                }
                for (int i = m_1482+1; i < n_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i];
                }
                printf("New Polynomial : ");
                for (int i = 0; i < n_1482+1; i++)
                {
                    if(i == n_1482){
                        printf("%dx^%d",result_1482[i],i);
                    }else{
                        printf("%dx^%d + ",result_1482[i],i);
                    }
                }
                printf("\n");
            }else{
                result_1482 = (int *)malloc(sizeof(int)*(m_1482+1));
                for (int i = 0; i < n_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i]+poly2_1482[i];
                }
                for (int i = n_1482+1; i < m_1482+1; i++)
                {
                    result_1482[i] = poly2_1482[i];
                }
                printf("New Polynomial : ");
                for (int i = 0; i < m_1482+1; i++)
                {
                    if(i == m_1482){
                        printf("%dx^%d",result_1482[i],i);
                    }else{
                        printf("%dx^%d + ",result_1482[i],i);
                    }
                }
                printf("\n");
            }
            break;
        case 2:
            if(n_1482 > m_1482){
                result_1482 = (int *)malloc(sizeof(int)*(n_1482+1));
                for (int i = 0; i < m_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i]-poly2_1482[i];
                }
                for (int i = m_1482+1; i < n_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i];
                }
                printf("New Polynomial : ");
                for (int i = 0; i < n_1482+1; i++)
                {
                    if(i == n_1482){
                        printf("%dx^%d",result_1482[i],i);
                    }else{
                        printf("%dx^%d + ",result_1482[i],i);
                    }
                }
                printf("\n");
            }else{
                result_1482 = (int *)malloc(sizeof(int)*(m_1482+1));
                for (int i = 0; i < n_1482+1; i++)
                {
                    result_1482[i] = poly1_1482[i]-poly2_1482[i];
                }
                for (int i = n_1482+1; i < m_1482+1; i++)
                {
                    result_1482[i] = poly2_1482[i];
                }
                printf("New Polynomial : ");
                for (int i = 0; i < m_1482+1; i++)
                {
                    if(i == m_1482){
                        printf("%dx^%d",result_1482[i],i);
                    }else{
                        printf("%dx^%d + ",result_1482[i],i);
                    }
                }
                printf("\n");
            }
            break;
        case 3:
            result_1482 = (int *)calloc(n_1482*m_1482+1,sizeof(int));
            for (int i = 0; i < n_1482+1; i++)
            {
                for (int j = 0; j < m_1482+1; j++)
                {
                    result_1482[i+j] += poly1_1482[i] * poly2_1482[j];
                }
            } 
            printf("New Polynomial : ");
                for (int i = 0; i < n_1482*m_1482+1; i++)
                {
                    if(i == n_1482*m_1482){
                        printf("%dx^%d",result_1482[i],i);
                    }else{
                        printf("%dx^%d + ",result_1482[i],i);
                    }
                }
                printf("\n");
            break;
        default:
            break;
        }
    }while(ch != 4);
    
}