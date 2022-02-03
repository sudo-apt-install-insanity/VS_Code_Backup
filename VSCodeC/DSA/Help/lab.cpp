#include <iostream>
#include <cstring>
using namespace std;

class String{
    string a;

    public:
    String(const char *in){
      a = in;
    }
    String(){
      a = "";
    }
    String operator + (String const &obj){
      String result;
      result.a = a + obj.a;
      return result;
    }
    String operator = (String const &obj){
      a = obj.a;
    }
    int operator == (String const &obj){
      if(a == obj.a)
        return 1;
      else
        return 0;
    }
    void display(){
      cout << a << endl;
    }
};

int main(){
  
  String a("Ainesh ");
  String b("Adhikari. ");

  String c = a + b;
  c.display();
  if( a == b)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  b = a;
  
  if( a == b)
    cout << "True" << endl;
  else
    cout << "False" << endl;

}
