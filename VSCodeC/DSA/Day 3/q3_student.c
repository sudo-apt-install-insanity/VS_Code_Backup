#include <stdio.h>
#include <stdlib.h>
typedef struct student{
    int roll_1482;
    char name_1482[20];
    int marks_1482[5];
    float percent_1482;
    char grade_1482;
}student;
void input(student *,int);
void calc(student *,int);
void sort(student *,int);
void print(student *,int);
void swap(student *,student *);
int main(){
    student *list_1482;
    int size_1482;
    printf("Enter number of students : ");
    scanf("%d",&size_1482);
    list_1482 = (student *)malloc(sizeof(student)*size_1482);
    input(list_1482,size_1482);
    calc(list_1482,size_1482);
    sort(list_1482,size_1482);
    print(list_1482,size_1482);


}
void input(student *p,int size){
    for (int i = 0; i < size; i++)
    {
        printf("Enter name : ");
        scanf(" %[^\n]s",&(p+i)->name_1482);
        printf("Enter roll : ");
        scanf("%d",&(p+i)->roll_1482);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter mark : ");
            scanf("%d",&(p+i)->marks_1482[j]);
        } 
        // printf("\e[1;1H\e[2J");
    }
}
void calc(student *p,int size){
    for (int i = 0; i < size; i++)
    {
        (p+i)->percent_1482 = ((p+i)->marks_1482[0]+(p+i)->marks_1482[1]+(p+i)->marks_1482[2]+(p+i)->marks_1482[3]+(p+i)->marks_1482[4])/5.0;
        if ((p+i)->percent_1482 >= 90)  {
            (p+i)->grade_1482 = 'O';
        }else if ((p+i)->percent_1482 >= 80)
        {
            (p+i)->grade_1482 = 'E';
        }else if ((p+i)->percent_1482 >= 70)
        {
            (p+i)->grade_1482 = 'A';
        }else if ((p+i)->percent_1482 >= 60)
        {
            (p+i)->grade_1482 = 'B';
        }else if ((p+i)->percent_1482 >= 50)
        {
            (p+i)->grade_1482 = 'C';
        }else if ((p+i)->percent_1482 >= 40)
        {
            (p+i)->grade_1482 = 'D';
        }else
            (p+i)->grade_1482 = 'F';
    }
}
void sort(student *p,int size){
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if((p+min)->percent_1482 > (p+j)->percent_1482)
                min = j;
        }
        swap(p+min,p+i);
        
    }
}
void swap(student *a,student *b){
    student temp = *a;
    *a = *b;
    *b = temp;
}
void print(student *p,int size){
    for (int i = 0; i < size; i++)
    {
        printf("Name : %s\n",(p+i)->name_1482);
        printf("Roll : %d\n",(p+i)->roll_1482);
        printf("Percentage : %0.2f\n",(p+i)->percent_1482);
        printf("CGPA : %0.2f\n",(p+i)->percent_1482/10);
        printf("Grade : %c\n\n",(p+i)->grade_1482);
    }
    
}