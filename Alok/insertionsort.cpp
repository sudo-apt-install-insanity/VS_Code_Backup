#include <iostream>

using namespace std;
// int binarysearch(int *arr,int size,int key)
// {
//     in low=0;
//     int high=size-1;
//    int mid=low+(high+low)/2;
//    while(low<=high){
//     if(arr[mid]==key)
//     return mid;
//     if(key>arr[mid])


//    }
// }
void insertionSort(int *arr,int n){
    int count=0;
    for(int j=1;j<n;++j){
        int key=arr[j];
        int i=j-1;
        for(;i>=0&&arr[i]>key;--i,count++)
            arr[i+1]=arr[i];
            
        arr[i+1]=key;
    }
cout<<count;
}
int main()
{
    cout << "Enter the array size:-";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << "element:-";
        cin >> arr[i];
    }
    insertionSort(arr,n);
    cout<<"After Insertionsort:-";

    for (int i = 0; i < n;i++)
    {
        cout<<arr[i];
    }



    
    }