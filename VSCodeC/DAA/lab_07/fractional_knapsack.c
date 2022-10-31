//fractional knapsack
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define MAX 100
typedef struct
{
    int weight;
    int profit;
    float ratio;
}item;

void sort(item *a, int n)
{
    int i, j;
    item temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i].ratio<a[j].ratio)
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
    int n, i, j, w, p, max;
    item a[MAX];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight and profit of each item: ");
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &a[i].weight, &a[i].profit);
        a[i].ratio=(float)a[i].profit/a[i].weight;
    }
    sort(a, n);
    printf("Enter the maximum weight: ");
    scanf("%d", &max);
    w=0;
    p=0;
    for(i=0;i<n;i++)
    {
        if(w+a[i].weight<=max)
        {
            w+=a[i].weight;
            p+=a[i].profit;
        }
        else
        {
            p+=(max-w)*a[i].ratio;
            break;
        }
    }
    printf("The maximum profit is %d", p);
    return 0;
}