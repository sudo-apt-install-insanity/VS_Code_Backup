#include <stdio.h>
#include <stdlib.h>
typedef struct student{
    int roll;
    char name[20];
    int mark;
} student;
int main(){
    student s[5];
    int i;
    printf("Enter name,roll,marks of 5 students: ");
    for (i = 0; i < 5; i++)
        scanf("%s%d%d", &s[i].name, &s[i].roll, &s[i].mark);

    for (i = 0; i < 4; i++){
        int imin = i;
        for (int j = i + 1; j < 5; j++){
            if (s[j].mark < s[imin].mark){
                imin = j;
            }
            student temp = s[i];
            s[i] = s[imin];
            s[imin] = temp;
        }
    }
    printf("Display of student info : ");
    for (i = 0; i < 5; i++){
        printf("\n%s\t\t%d\t\t%d\n", s[i].name, s[i].roll, s[i].mark);
    }

    return 0;
}