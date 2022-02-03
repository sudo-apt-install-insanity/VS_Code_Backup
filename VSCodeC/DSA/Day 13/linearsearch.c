#include <stdio.h>
int l_search(int arr[], int n, int x)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n, i;
    printf("Enter The Size Of Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter The Array Elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter The  Element to be Searched : ");
    scanf("%d", &x);
    int ans = l_search(arr, n, x);
    if (ans == -1)
    {
        printf("Array element Dosent Exists");
    }
    else
    {
        printf("Array Is Present At : %d", ans);
    }

    return 0;
}