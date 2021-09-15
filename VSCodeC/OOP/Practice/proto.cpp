#include <iostream>
using namespace std;
int factorial(int);
int main(){
    
    int value;
    cin >>  value;
    cout << factorial(value);
    return 0; 
}
int factorial(int n){
    if(n < 0)
        return -1;
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}