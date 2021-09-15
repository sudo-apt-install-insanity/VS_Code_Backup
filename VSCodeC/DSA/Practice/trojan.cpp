#include <iostream>
using namespace std;

int main(void)
{
    int n, num, sum=0, temp;
    cout<<"Enter the number: ";
    cin>>num;
    n = num;
    while(n>0)
    {
        temp = n % 10;
        sum += (temp*temp*temp);
        n = n/10;
    }
    if(sum == num){
        cout<<"armstrong number";
        cout<<endl;
    }
    else
        cout<<"not an armstrong number";           
    return 0;
}