#include <stdio.h>
#include <stdlib.h>
typedef struct employee{
    char name_1482[20];
    char gender_1482;
    char department_1482[20];
    int basicpay_1482;
    int grosspay_1482;
}employee;

int main(){
    int size;
    employee *emplist_1482;
    printf("Enter number of employees : ");
    scanf("%d",&size);
    emplist_1482 = (employee *)malloc(sizeof(employee)*size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter employee name : ");
        scanf(" %[^\n]s",&(emplist_1482+i)->name_1482);
        printf("Enter employee gender : ");
        scanf(" %c",&(emplist_1482+i)->gender_1482);
        printf("Enter employee deparment : ");
        scanf(" %[^\n]s",&(emplist_1482+i)->department_1482);
        printf("Enter employee basic pay : ");
        scanf("%d",&(emplist_1482+i)->basicpay_1482);
        // printf("\e[1;1H\e[2J");
    }
    for (int i = 0; i < size; i++)
    {
        (emplist_1482+i)->grosspay_1482 = (emplist_1482+i)->basicpay_1482 + 0.25* (emplist_1482+i)->basicpay_1482 + 0.75* (emplist_1482+i)->basicpay_1482;
    }
    for (int i = 0; i < size; i++)
    {
        printf("Employee name : %s\n",(emplist_1482+i)->name_1482);
        printf("Employee gender : %c\n",(emplist_1482+i)->gender_1482);
        printf("Employee department : %s\n",(emplist_1482+i)->department_1482);
        printf("Employee grosspay : %d\n",(emplist_1482+i)->grosspay_1482);
    }
    
    
    
}