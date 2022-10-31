#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void merge_sort(int *, int , int);
void merge(int *, int , int , int );

int main(){
    srand(time(0));
    printf("Enter size of array :");
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    printf("Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    merge_sort(arr, 0, n - 1);

    printf("Array : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

}
void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int m = low + (high - low) / 2;
        merge_sort(arr, low, m);
        merge_sort(arr, m + 1, high);
        merge(arr, low, m, high);
    }
}

void merge(int arr[], int low, int m, int high)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}