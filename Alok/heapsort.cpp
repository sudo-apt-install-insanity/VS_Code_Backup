#include <iostream>
using namespace std;
int cnt = 0;
void heapify(int arr[], int N, int i)
{
    int maxi = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N || r < N)
        cnt++;
    if (l < N && arr[l] > arr[maxi])
        maxi = l;
    if (r < N && arr[r] > arr[maxi])
        maxi = r;
    if (maxi != i)
    {
        swap(arr[i], arr[maxi]);
        heapify(arr, N, maxi);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    cout << "Before sorting : ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    heapSort(arr, n);
    cout << "\nAfter sorting : ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
    cout << "No Of Comparisons : " << cnt << endl;
}