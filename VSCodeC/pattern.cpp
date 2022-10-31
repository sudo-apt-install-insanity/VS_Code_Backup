#include <bits/stdc++.h>
using namespace std;

class student{
    public:
    string name,roll;
    int mark[5];

    void getdata(){
        cin>>name;
        cin>>roll;
        roll = roll.substr(0,2);
        for(int i=0;i<5;i++){
            cin>>mark[i];
        }
    }
};
int main(){
    int n;
    cin >> n;
    student list[n];
    for(int i=0;i<n;i++){
        list[i].getdata();
    }
    student passlist[n];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j = 0;j < 5;j++){
            if(list[i].mark[j] < 50 ) break;
            passlist[k] = list[i];k++; break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j < n;j++){
            if(passlist[i].roll.compare(passlist[j].roll) <= 0){
                student temp = passlist[i];
                passlist[i] = passlist[j];
                passlist[j] = temp;
            }
        }
    }
    for(int i = 0;i < k;i++){
        cout<<passlist[i].name<<" "<<passlist[i].roll<<endl;
    }

    return 0;
}