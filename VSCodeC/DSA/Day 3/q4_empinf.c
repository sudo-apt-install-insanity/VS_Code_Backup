#include <stdio.h>
#include <stdlib.h>
typedef struct name{
    char fname_1482[10];
    char mname_1482[10];
    char lname_1482[10];
}name;
typedef struct date{
    int dd_1482;
    int mm_1482;
    int yy_1482;
} date;
typedef struct employee{
    name empname_1482;
    date dob_1482;
    int accnum_1482;
    int balance_1482;
}employee;
void input(employee *,int );
void bal_200(employee *,int );
void add_bal(employee *,int );
int main(){
    employee *emplist_1482;
    int size;
    printf("Enter number of employees : ");
    scanf("%d",&size);
    emplist_1482 = (employee *)malloc(sizeof(employee)*size);
    input(emplist_1482,size);
    add_bal(emplist_1482,size);
    bal_200(emplist_1482,size);
}
void input(employee *p,int size){
    for (int i = 0; i < size; i++)
    {
        printf("Enter employee first name : ");
        scanf(" %[^\n]s",p[i].empname_1482.fname_1482);
        printf("Enter employee middle name : ");
        scanf(" %[^\n]s",p[i].empname_1482.mname_1482);
        printf("Enter employee last name : ");
        scanf(" %[^\n]s",p[i].empname_1482.lname_1482);
        printf("Enter employee date of birth(DD/MM/YY) : ");
        scanf("%d%d%d",&p[i].dob_1482.dd_1482,&p[i].dob_1482.mm_1482,&p[i].dob_1482.yy_1482);
        printf("Enter employee account number : ");
        scanf("%d",&p[i].accnum_1482);
        printf("Enter employee balance : ");
        scanf("%d",&p[i].balance_1482);
        printf("\n");
    }
}
void bal_200(employee *p,int size){
    int index = 1;
    printf("Employees having balance less than 200 : \n");
    for (int i = 0; i < size; i++)
    {
        if(p[i].balance_1482 < 200){
            printf("%d. %s %s %s \n",index,p[i].empname_1482.fname_1482,p[i].empname_1482.mname_1482,p[i].empname_1482.lname_1482);
            index++;
        }
    }
    
}
void add_bal(employee *p,int size){
    int index = 1;
    printf("Employees with balance added : \n");
    for (int i = 0; i < size; i++)
    {
        if(p[i].balance_1482 > 1000){
            p[i].balance_1482 += 100;
            printf("%d. %s %s %s \n",index,p[i].empname_1482.fname_1482,p[i].empname_1482.mname_1482,p[i].empname_1482.lname_1482);
            index++;
        }
           
    }
}