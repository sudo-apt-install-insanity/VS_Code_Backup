#include <iostream>
using namespace std;
class test{
    public:
    static int call(){
        cout << "hello";
    }
};
int main(){
    test t1;
    test::call();
}