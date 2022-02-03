#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(string s){
    cout << s << endl;
}



void solve(ll tc){
    ll n,k,x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<string> lex;
    string tempstr;
    for(char c : s){
        if(c != '*')
            tempstr.push_back(c);
    } 
    s = tempstr;
    lex.push_back(s);
    print(s);
}
int main(){
    ll t;
    cin >> t;
    for(ll i = 1;i <= t;i++)
        solve(i);
}