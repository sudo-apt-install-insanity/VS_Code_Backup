#include <iostream>
using namespace std;

void printarr(int *,int );
void swap(int* , int* );

int main(){
    int *arr;
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    arr = (int *)malloc(sizeof(int) * size);
    cout << "Enter elements : ";
    for (int i = 0; i < size; i++)
        cin >> *(arr+i);
    cout << "\e[1;1H\e[2J";
    cout << "Original array : ";
    printarr(arr,size);
    // sort(arr,size);
    cout << "Reverse array : ";
    printarr(arr,size);
    free(arr);
    return 0;


    
}
void printarr(int *arr,int size){
    for(int i = 0;i < size;i++)
        cout << *(arr+i) << " ";
    cout << endl;
}
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int *arr,int low,int high){
    int pivot = *(arr+high);
    int i = low - 1;

    for (int  j = 0; j <= high-1; j++){
        if(*(arr+j) < pivot){
            i++;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+i+1,arr+high);
    return (i+1);
    
}