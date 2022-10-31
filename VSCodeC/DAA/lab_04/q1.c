#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int key)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);
        return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    srand(time(0));
    printf("Enter size of array :");
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    bubble_sort(arr, n);

    printf("Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    int key = rand() % 100;
    printf("Random Key : %d\n", key);
    int result = binarySearch(arr, 0, n - 1, key);
    printf("Random Key is at index(-1 is not found) : %d", result);
    
    return 0;
}