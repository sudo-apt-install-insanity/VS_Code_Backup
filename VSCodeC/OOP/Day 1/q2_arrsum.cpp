#include <iostream>
using namespace std;

int main(){
    int *arr;
    int size,sum = 0;
    cout << "Enter size :" <<endl;
    cin >> size;
    arr = (int *)malloc(sizeof(int)*size);
    cout << "Enter elements :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr+i);
        sum += *(arr+i);
    }
    cout << "Sum is : " << sum << endl;
    
}