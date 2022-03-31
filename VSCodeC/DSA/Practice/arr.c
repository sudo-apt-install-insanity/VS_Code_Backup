#include <stdio.h>

void main()
{
    int arr[] = {2, 5, 8, 10, 45, 23, 4, 10, 14, 17, 3, 9, 1};
    int reqSum = 73;
    int size = sizeof(arr) / sizeof(int);
    int strIndex = 0;
    int endIndex = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+= arr[i];
        endIndex++;
        while(sum > reqSum){
            sum -= arr[strIndex];
            strIndex++; 
        }
    }
    
}