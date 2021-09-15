#include <stdio.h>
#include <stdlib.h>
struct student{
    char name[20];
    int roll;
    float marks[3];    
}*s;

int main()
{
    float sum, avg;    
    // struct student *s;
    // s = (struct student *)malloc(sizeof(struct student));
    printf("\nEnter the name: ");
    scanf("%[^\n]s",s->name);
    printf("\nEnter the roll Number : ");
    scanf("%d", &s->roll);       
    printf("Enter 3 mark : ");
    scanf("%f%f%f", &s->marks[0], &s->marks[1], &s->marks[2]);

    sum = s->marks[0] + s->marks[1] + s->marks[2];
    avg = sum/3;

    printf("\e[1;1H\e[2J");
    printf("Name : %s\n",s->name);
    printf("Roll : %d\n",s->roll);
    printf("The sum of the marks = %f\n", sum);
    printf("The average marks = %f", avg);
}




