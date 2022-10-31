#include <iostream>
#define ll long long int
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll ans,r,c;
        cin >> r >> c;
        if(c > r){
            if(c%2 == 1){
                ans = c*c - r + 1;
            }else{
                ans = (c-1)*(c-1) + r;
            }
        }else{
            if(r%2 == 0){
                ans = r*r - c + 1;
            }else{
                ans = (r-1)*(r-1) + c;
            }
        }
        cout << ans << endl;
    }
}