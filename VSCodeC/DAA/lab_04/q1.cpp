#include <iostream>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

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
int main(){
    srand(time(0));
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
    key = rand() % 100000;

    bubble_sort(arr, n);

    cout << "Sorted array " << endl;
    auto start = high_resolution_clock::now();
    int result = binarySearch(arr, 0, n - 1, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    if (result == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    cout << endl
         << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;

}