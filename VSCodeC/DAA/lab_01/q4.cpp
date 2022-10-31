#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 3,b = 4,c = 5;
    cout << "Before Swap: "<<  a << " " << b << " " << c << endl;   
    swap(a,b);
    swap(a,c);
    cout << "After Swap: "<< a << " " << b << " " << c << endl;
    return 0;
}