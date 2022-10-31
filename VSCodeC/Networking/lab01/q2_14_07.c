#include <stdio.h>
#include <stdlib.h>
struct info
{
    int roll;
    char *name;
    float cgpa;
};

typedef struct info Info;

void printer(Info *);
int main(){
    Info *test = malloc(sizeof(Info));
    printf("Enter name:");
    size_t bufsize = 32;
    getline(&test->name,&bufsize,stdin);
    printf("Enter cgpa :");
    scanf("%f",&test->cgpa);
    printf("Enter roll :");
    scanf("%d",&test->roll);
    printer(test);
}

void printer(Info *p){
    printf("Roll : %d\nName : %sCGPA : %.2f",p->roll,p->name,p->cgpa);
}