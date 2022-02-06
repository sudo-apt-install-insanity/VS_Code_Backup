#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string str = "";
        int lmax = 0,gmax = 0,start=0,end=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(str.find(s.at(i)) == string::npos){
                str += s.at(i);
                end ++;
            }else{
                remove(str.begin(),str.end(),s.at(i));
                start =i;
                end = i+1;
            }
            lmax = end - start;
            if(lmax >= gmax){
                gmax = lmax;
            }
        }
        return gmax;
    }

};

int main(){
    Solution *s = new Solution();
    cout << s->lengthOfLongestSubstring("abcabcbb");
}