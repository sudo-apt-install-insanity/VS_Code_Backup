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

    sort(arr,arr+n);
    
    int num = 0,count = 0,max_count = 0,mce = 0;
    for(int i = 0;i < n-1;i++){
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max_count){
            max_count = count;
            mce = arr[i];
        }else{
            count = 1;
        }
        
        if(arr[i] == arr[i+1]){
            num++;
        }
    }
    printf("Number of duplicates : %d\n",num);
    printf("Most repeating element : %d\n",mce);

    

}