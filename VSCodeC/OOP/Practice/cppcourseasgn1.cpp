#include <iostream>
#include <string>
using namespace std;

int main(){
    string val;
    cout << "Enter string : ";
    cin >> val;
    int size = val.length();
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
            cout << " ";
        for (int j = 0; j <= i; j++)
            cout << val.at(j);  
        for(int j = i-1;j >= 0;j--)
            cout << val.at(j);
        
        cout << endl;
    }
    

}