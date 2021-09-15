#include <iostream>
using namespace std;
void reverse(int *, int );
void printarr(int *,int );
int main(){
    int *arr;
    int size,sum = 0;
    cout << "Enter size : ";
    cin >> size;
    arr = (int *)malloc(sizeof(int)*size);
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr+i);
    }
    cout << "Original array : ";
    printarr(arr,size);
    reverse(arr,size);
    cout << "Reverse array : ";
    printarr(arr,size);
    free(arr);
    return 0;
}
void reverse(int *arr, int size){
    int temp = 0;
    for(int i = 0;i < size/2;i++){
        temp = *(arr+i);
        *(arr+i) = *(arr+size-1-i);
        *(arr+size-1-i) = temp;
    }
}
void printarr(int *arr,int size){
    for(int i = 0;i < size;i++)
        cout << *(arr+i) << " ";
    cout << endl;
}