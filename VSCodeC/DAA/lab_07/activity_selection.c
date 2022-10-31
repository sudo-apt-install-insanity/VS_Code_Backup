//activity selection
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define MAX 100
typedef struct
{
    int start;
    int finish;
}activity;
void sort(activity *a, int n)
{
    int i, j;
    activity temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].finish>a[j].finish)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int main()
{
    int n, i, j;
    activity a[MAX];
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    printf("Enter the start and finish time of each activity: ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &a[i].start, &a[i].finish);
    }
    sort(a, n);
    printf("The activities that can be performed are: ");
    printf("%d ", 1);
    j=0;
    for(i=1;i<n;i++)
    {
        if(a[i].start>=a[j].finish)
        {
            printf("%d ", i+1);
            j=i;
        }
    }
    return 0;
}
