#include <stdio.h>
int BubbleSort(int arr[], int n)
{
    int i, j, temp, count = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    return count;
}
int SelectionSort(int arr[], int n)
{
    int i, j, count = 0, minindx, temp;
    for (i = 0; i < n - 1; i++)
    {
        minindx = i;
        for (j = i + 1; j < n; j++)
        {
            count++;
            if (arr[minindx] > arr[j])
            {
                minindx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minindx];
        arr[minindx] = temp;
    }

    return count;
}
int InsertionSort(int arr[], int n)
{
    int i, x, j, count = 0;
    for (i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
    return count;
}
void Print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter Size Of Array : ");
    scanf("%d", &n);
    int arr[n];
    int i, x;
    int ch = 0;
    do
    {
        printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n0.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Bubble Sort : \n");
            printf("Enter Elements Of Array : ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            x = BubbleSort(arr, n);
            printf("\nSorted Array : ");
            Print(arr, n);
            printf("\nNo Of Comparisons : %d", x);
            break;
        case 2:
            printf("Selection Sort : \n");
            printf("Enter Elements Of Array : ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            x = SelectionSort(arr, n);
            printf("\nSorted Array : ");
            Print(arr, n);
            printf("\nNo Of Comparisons : %d", x);
            break;
        case 3:
            printf("Insertion Sort : \n");
            printf("Enter Elements Of Array : ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }
            x = InsertionSort(arr, n);
            printf("\nSorted Array : ");
            Print(arr, n);
            printf("\nNo Of Comparisons : %d", x);
            break;
        }

    } while (ch != 0);
}