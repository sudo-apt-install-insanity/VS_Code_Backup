#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    return div(((a + b) + abs(a - b)), 2).quot;
}
int main ()
{
    printf("Enter two numbers :");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("\nMaximum of the two : %d", max(a, b));
}