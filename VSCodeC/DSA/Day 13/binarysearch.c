#include <stdio.h>
int partition(int arr[], int st, int en)
{
    int piv = arr[en];
    int i = (st - 1);
    int j;
    for (j = st; j <= en - 1; j++)
    {
        if (arr[j] < piv)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[en];
    arr[en] = temp;
    return (i + 1);
}
void q_sort(int arr[], int st, int en)
{
    if (st < en)
    {
        int p = partition(arr, st, en);
        q_sort(arr, st, p - 1);
        q_sort(arr, p + 1, en);
    }
}
int b_search(int arr[], int n, int x)
{
    int st = 0;
    int en = n - 1;
    int mid = 0;
    while (st < en)
    {
        mid = st + (en - st) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            st = mid + 1;
        else
            en = mid - 1;
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
    q_sort(arr, 0, n - 1);
    int x;
    printf("Enter The  Element to be Searched : ");
    scanf("%d", &x);
    int ans = b_search(arr, n, x);
    if (ans == -1)
    {
        printf("Array element Dosent Exists");
    }
    else
    {
        printf("Array Is Present At : %d\n", ans);
    }
    return 0;
}