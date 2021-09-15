#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --> 0){
        int n;
        int k;
        int l;
        cin >> n >> k >> l;
        int max_drug = l - l%k;
        if(k < 0){
            max_drug = 0;
        }
        
        int max_speed = INT_MIN;
        while(n -->1){
            int s;
            cin >> s;
            if(s > max_speed)
                max_speed = s;
        }
        int frnd_speed;
        cin >>frnd_speed;
        if(frnd_speed + max_drug > max_speed)
            cout << "Yes" <<endl;
        else
            cout << "No" <<endl;
    }
    
}