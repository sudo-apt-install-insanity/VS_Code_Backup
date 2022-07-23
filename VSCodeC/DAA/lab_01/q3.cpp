#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cout << "Enter number of integers: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }

    int new_arr[n];
    int j = 0;
    for(int i = 0; i < n;i++){
        if(arr[i] % 2 == 0){
            new_arr[j] = arr[i];
            j++;
        }
    }
    for(int i = 0; i < n;i++){
        if(arr[i] % 2 != 0){
            new_arr[j] = arr[i];
            j++;
        }
    }
    for(int i = 0; i < n;i++){
        cout << new_arr[i] << " ";
    }
}