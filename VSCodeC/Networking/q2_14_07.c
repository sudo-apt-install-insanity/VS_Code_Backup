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
    size_t bufsize = 32;
    size_t bytes = getline(&test->name,&bufsize,stdin);
    scanf("%f",&test->cgpa);
    scanf("%d",&test->roll);
    printer(test);
}

void printer(Info *p){
    printf("Roll : %d\nName : %s\nCGPA : %.2f",p->roll,p->name,p->cgpa);
}