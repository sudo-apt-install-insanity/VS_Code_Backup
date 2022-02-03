#include <iostream>
using namespace std;

class String1{
    string str1;

    public:
    String1(string s){
        set(s);
    }
    string get(){
        return str1;
    }
    void set(string s){
        str1 = s; 
    }

};

class String2{
    string str2;

    public:
    String2(string s){
        set(s);
    }
    string get(){
        return str2;
    }
    void set(string s){
        str2 = s; 
    }
};

class StringConcat : public String1 , public String2{
    string concat;

    public :
    StringConcat() : String1("A ") , String2(" B"){

    }
    StringConcat(string s1,string s2) : String1(s1) , String2(s2){

    }
    string concat_string(String1 s1,String2 s2){
        concat = s1.get() + s2.get();
    }
};

int main(){
    StringConcat stringconcat;
    string concat = stringconcat.concat_string(String1("Hello"),String2(" World!"));
    cout << "String = " << concat << endl;
}
