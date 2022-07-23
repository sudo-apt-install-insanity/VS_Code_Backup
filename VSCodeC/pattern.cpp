#include <iostream>
using namespace std;

int main()
{
    int count1 = 0,count2 = 0;
    for (int i = 5; i > 0; i--)
    {
        
        if (i % 2 != 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if(count1 == 0){
                    cout << j << " ";
                }else{
                    cout << j + (count1*5)+4  << " ";
                } 
            }
            count1++;
        }else{
            for (int j = i; j > 0; j--)
            {
                if(count2 == 0 ){
                    cout << j + 5 << " "; 
                }else{
                    cout << j + 12 << " ";
                }
                
            }
            count2++;
        }

        cout << endl;
    }
    
  
}