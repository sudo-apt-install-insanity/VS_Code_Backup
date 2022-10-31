#include <stdio.h>
#include <stdlib.h>

int isqrt(int n)
{
    float sqrt = n / 2.0, temp = 0.0;
    while (sqrt != temp)
    {
        temp = sqrt;
        sqrt = (((n / temp) + temp) / 2);
    }
    return (int)sqrt;
}
int main(void)
{
    printf("Enter a number : ");
    int n;
    scanf("%d", &n);
    printf("\nThe square root of %d is : %d", n, isqrt(n));
    return 0;
}