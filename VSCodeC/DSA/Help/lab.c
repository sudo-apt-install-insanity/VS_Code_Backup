#include <stdio.h>

struct student{
    int enroll_no;
    char name[15];
    int agg_mark;
};

typedef struct student student;


int main(){
    student arr[20];
    char ch = 'Y';
    int i = 0;
    while(ch == 'Y' && i < 20){
        printf("Enter name :");
        // scanf("%[^\n",arr[i].name);
        gets(arr[i].name);
        printf("Enter enrollment number :");
        scanf("%d",&arr[i].enroll_no);
        printf("Enter aggregate marks :");
        scanf("%d",&arr[i].agg_mark);
        fflush(stdin);
        i++;
        printf("Do you want to continue(Y/N) : ");
        scanf("%c",&ch);
        fflush(stdin);
    }
    for (int j = 0; j < i; j++)
    {
        for (int k = j+1; k < i; k++)
        {
            if(arr[j].agg_mark < arr[k].agg_mark){
                student temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
        
    }
    for (int j = 0; j < i; j++)
    {

        printf("Name : %s\n" ,arr[j].name);
        printf("Enrollment number : %d\n",arr[j].enroll_no);
        // printf("Aggregate marks : %d\n",arr[j].agg_mark);
        printf("Rank : %d\n",j+1);
    }
    
    
}