#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
    srand(time(0));
    int n = 0;
    printf("Enter number of integers: ");
    scanf("%d", &n);
    int arr[n];
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nMax : %d\nMin : %d\n", max, min);
}