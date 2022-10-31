#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print_table()
{
    FILE *fp = fopen("table.csv", "w");
    fprintf(fp,"Sl no.,n,Average Case,Best Case, Worst Case\n");
    int count = 1;
    for (int i = 5000; i <= 50000; i += 5000)
    {
        int *arr = malloc(i * sizeof(int));
        for (int j = 0; j < i; j++)
        {
            arr[j] = rand() % i;
        }
        clock_t t1 = clock();
        insertion_sort(arr, i);
        t1 = clock() - t1;
        clock_t t2 = clock();
        insertion_sort(arr, i);
        t2 = clock() - t2;
        bubble_sort(arr, i);
        clock_t t3 = clock();
        insertion_sort(arr, i);
        t3 = clock() - t3;
        fprintf(fp,"%d,%d,%f,%f,%f\n", count, i, (double)t1 / CLOCKS_PER_SEC, (double)t2 / CLOCKS_PER_SEC, (double)t3 / CLOCKS_PER_SEC);
        count++;
    }
}

int main()
{
    print_table();
    return 0;
}